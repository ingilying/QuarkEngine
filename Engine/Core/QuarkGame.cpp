#include "QuarkGame.h"

QuarkGame::QuarkGame(string name, int width, int height) : Game(name,width,height)
{
	

}

void QuarkGame::Begin()
{
	Game::Begin();
	glfwSetWindowUserPointer(window,this);
	mesh=new Mesh("models/trigle.quark");
	Mesh *block_mesh=new Mesh("models/block.quark");
	mesh->SetShader(shader);
	block_mesh->SetShader(shader);
	mesh->SetImage("images/girl.jpg");
	block_mesh->SetImage("images/girl.jpg");
	triangle = new Actor(mesh);
	Actor *block=new Actor(block_mesh);
	character=new FPSCharacter();
	block->SetPosition(glm::vec3(0.5f,0.3f,0.0f));
	triangle->SetPosition(glm::vec3(5.1f, 3.0f, 0.0f));
	character->SetPosition(glm::vec3(0.1f,1.0f,0.0f));
	triangle->SetScale(0.1f);
	triangle->EnableTexture(true);
	trpos = triangle->GetPosition();
	root.AddItem(triangle);
	root.AddItem(block);
	root.AddItem(character);
	shader->SetBool("bColor",false);
	character->SetSpeed(3.0f);
	character->SetSenstity(0.05f);
	//std::cout<<"A"<<std::endl;
	this->camera=character->camera;
	character->InitLastMouseXY(width/2,height/2);
	KeyBoradSystem::BindKeyLoopEvent(std::bind(&FPSCharacter::KeyInput,character,placeholders::_1));
	MouseSystem::BindEvent(std::bind(&FPSCharacter::MouseInput,character,placeholders::_1,placeholders::_2));
	KeyBoradSystem::BindKeyEvent(std::bind(&QuarkGame::KeyInputEvent,this,PLACEHOLIDERS_3));
}

void QuarkGame::Update()
{
	//Print("I'm QuarkGame.");
	Actor *block=(Actor*)root.items[1];
	float roation=block->GetRoation().x+0.001f;
	if(roation>360.0f)	roation=0.0f;
	block->SetRoation(glm::vec3(roation,roation,roation));
}

void QuarkGame::KeyInputEvent(int key,int mod,int action)
{
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
		cout<<"Scale: X: "<<scale.x<<" Y: "<<scale.y<<" Z: "<<scale.z<<endl;
		tr->SetScale(scale);
		Print("放大0.1");
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


void QuarkGame::Free()
{
	mesh->Clean();
	glfwTerminate();
}