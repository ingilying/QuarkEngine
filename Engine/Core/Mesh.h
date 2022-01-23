#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include "Shader.h"
#include "Quark.h"
#include "Texture.h"

struct Vertex {
	glm::vec3 Postion;
	glm::vec2 TexCoords;
	glm::vec3 Colors;
	Vertex(glm::vec3 pos, glm::vec2 tex,glm::vec3 colors)
	{
		Postion = pos;
		TexCoords = tex;
		Colors=colors;
	}
};


using namespace std;

class Mesh : public Quark
{

private:
	int VertexCount;
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	vector<Vertex> vertices;
	vector<STexture> textures;
	vector<unsigned int>indices;
	bool bTexture;
	Shader* shader;
	Texture* texture;
public:
	Mesh(vector<Vertex> vertices,vector<unsigned int> indices,vector<STexture> textures);
	Mesh(string fn);
	void setup();
	float *points;
	void Clean();
	void Render();
	//void SetTranslform(glm::mat4 trans);
//	glm::mat4 GetTranslform();
	void SetShader(Shader* shader);
	void SetImage(string fn);
	void EnableTexture(bool is);
};

