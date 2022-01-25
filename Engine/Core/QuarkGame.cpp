#include "QuarkGame.h"

QuarkGame::QuarkGame(string name, int width, int height) : Game(name,width,height)
{
	

}

void QuarkGame::Begin()
{
	Game::Begin();
	glfwSetWindowUserPointer(window,this);
	//std::vector<float> *triangle_data=new std::vector<float>(triangle_vertices,triangle_vertices+6*3);
	//vector<Vertex> triangle_vers;
	//Load the triangle vertices	-0.5f, -0.5f, 0.0f
	//triangle_vers.push_back(Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	//triangle_vers.push_back(Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)));
	//triangle_vers.push_back(Vertex(glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)));

	//vector<unsigned int> triangle_indices;
	//triangle_indices.push_back(0);
	//triangle_indices.push_back(1);
	//triangle_indices.push_back(2);
	//End

	//Mesh mesh(triangle_vers, vector<Texture>());
	//mesh = new Mesh(triangle_vers,triangle_indices ,vector<Texture>());
	//glEnable(GL_DEPTH_TEST);
	mesh=new Mesh("models/trigle.quark");
	Mesh *block_mesh=new Mesh("models/block.quark");
	mesh->SetShader(shader);
	block_mesh->SetShader(shader);
	mesh->SetImage("images/girl.jpg");
	block_mesh->SetImage("images/girl.jpg");
	//Actor triangle(mesh);
	triangle = new Actor(mesh);
	Actor *block=new Actor(block_mesh);
	block->SetPosition(glm::vec3(0.5f,0.3f,0.0f));
	triangle->SetPosition(glm::vec3(5.1f, 3.0f, 0.0f));
	cam.SetPosition(glm::vec3(0.1f,1.0f,0.0f));
	triangle->SetScale(0.1f);
	triangle->EnableTexture(true);
	trpos = triangle->GetPosition();
	root.AddItem(triangle);
	root.AddItem(block);
	shader->SetBool("bColor",false);
	//KeyBoradSystem::BindKeyEvent(this,&QuarkGame::KeyInputEvent);
	cam.SetSpeed(3.0f);
	cam.SetSenstity(0.05f);
	KeyBoradSystem::BindKeyEvent(std::bind(&QuarkGame::KeyInputEvent,this,PLACEHOLIDERS_3));
}
void QuarkGame::KeyInputEvent(int key,int mod,int action)
{
	//Game::ProcessInputEvent(window,key,scancode,action,mods);
	// if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	// {
	// 	glfwSetWindowShouldClose(window, true);
	// 	return;
	// }
	//if(key==GLFW_KEY_SPACE && action==GLFW_PRESS)
	//{
	//	glfwSetWindowShouldClose(window,true);
	//}
	if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window,true);
		return;
	}
	if (key==GLFW_KEY_F7 && (action==GLFW_PRESS || action==GLFW_REPEAT ))
	{
		if (!is_mode_line)
		{
			Print("on");
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			is_mode_line = true;
		}
		else {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			is_mode_line = false;
		}
		return;
	}
	if(key==GLFW_KEY_UP && (action==GLFW_PRESS|| action==GLFW_REPEAT))
	{
		Actor* tr=(Actor*)(*root.items.begin());
		glm::vec3 scale=tr->GetScale()+glm::vec3(0.1f,0.1f,0.1f);
		//cout<<"Scale: X: "<<scale.x<<" Y: "<<scale.y<<" Z: "<<scale.z<<endl;
		tr->SetScale(scale);
		//Print("放大0.1");
		return;
	}
	if(key==GLFW_KEY_DOWN && (action==GLFW_PRESS || action==GLFW_REPEAT))
	{
		Actor* tr=(Actor*)(*root.items.begin());
		tr->SetScale(tr->GetScale()-glm::vec3(0.1f,0.1f,0.1f));
		return;
	}
	if(key==GLFW_KEY_C && action==GLFW_PRESS)
	{
		shader->SetBool("bColor",!is_corlor);
		//is_corlor=!is_corlor;
		if(is_corlor)
			is_corlor=false;
		else is_corlor=true;
		return;
	}
}

void QuarkGame::Update()
{
	//Print("I'm QuarkGame.");
	Actor *block=(Actor*)root.items[1];
	float roation=block->GetRoation().x+0.001f;
	if(roation>360.0f)	roation=0.0f;
	block->SetRoation(glm::vec3(roation,roation,roation));
}


void QuarkGame::Free()
{
	mesh->Clean();
	//delete triangle;
	//delete shader;
	//delete mesh;
	//delete window;
	glfwTerminate();
}