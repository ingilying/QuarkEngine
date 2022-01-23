#include "Mesh.h"
#include <algorithm>
#include <fstream>
#define DEBUGM
#ifdef DEBUGM
#include <iostream>
#endif

Mesh::Mesh(vector<Vertex> vertices,vector<unsigned int>indices, vector<STexture> textures):
								Quark()
{
	this->vertices = vertices;
	this->textures = textures;
	this->indices  = indices;
	setup();
}

Mesh::Mesh(string fn) : vertices(),indices(),textures()
{
	texture=nullptr;
	ifstream file(fn);
	if(file.is_open())
	{
		bool bcolor;
		int vs;
		glm::vec3 ver,corlor;
		glm::vec2 tex;
		file>>bcolor;
		file>>vs;
		for(int i=0;i<vs;++i)
		{
			float v1,v2,v3;
			file>>v1>>v2>>v3;
			ver=glm::vec3(v1,v2,v3);
			file>>v1>>v2>>v3;
			corlor=glm::vec3(v1,v2,v3);
			file>>v1>>v2;
			tex=glm::vec2(v1,v2);
			Vertex vex=Vertex(ver,tex,corlor);
			vertices.push_back(vex);
		}
		file>>vs;
		for (int i = 0; i < vs; ++i)
		{
			int v1;
			file>>v1;
			indices.push_back(v1);
		}
		setup();
	}else{
		cout<<fn<<" 文件不存在"<<endl;
	}
	file.close();
}


void Mesh::Clean()
{
	glDisableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1,&VBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1,&EBO);
}

void Mesh::Render()
{
	glm::mat4 translform=glm::mat4(1.0f);
	//std::cout<<GetPosition().x<<" "<<GetPosition().y<<" "<<GetPosition().z<<std::endl;
	translform = glm::translate(translform, GetPosition());
	translform = glm::rotate(translform, GetRoation().x, glm::vec3(1.0f, 0.0f, 0.0f));
	translform = glm::rotate(translform, GetRoation().y, glm::vec3(0.0f, 1.0f, 0.0f));
	translform = glm::rotate(translform, GetRoation().z, glm::vec3(0.0f, 0.0f, 1.0f));
	translform = glm::scale(translform, GetScale());
	if (shader != nullptr)
	{
		shader->Use();
		shader->SetMat4("transform", translform);
	}
	else cout << "[Mesh]:Shader is not found." << endl;
	if(texture!=nullptr && bTexture)
	{	
		texture->Render();
		shader->SetBool("bTexture",true);
	}
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE0,0);
	shader->SetBool("bTexture",false);
}

void Mesh::setup()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1,&EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()*sizeof(unsigned int),&indices[0],GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
	
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Colors));

	glBindVertexArray(0);
}

void Mesh::SetShader(Shader* shader)
{
	this->shader = shader;
}

void Mesh::SetImage(string fn)
{
	if(texture!=nullptr)
		delete texture;
	texture=new Texture(fn);
	shader->SetBool("bTexture",true);
}


void Mesh::EnableTexture(bool is)
{
	this->bTexture=is;
	if(is)
		shader->SetBool("bTexture",true);
	else shader->SetBool("bTexture",false);
}
// glm::mat4 Mesh::GetTranslform()
// {
// 	return transform;
// }