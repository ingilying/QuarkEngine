#include "FPSCharacter.h"
#include <iostream>

FPSCharacter::FPSCharacter() : Character() 
{
    camera=new Camera();
}

FPSCharacter::~FPSCharacter()
{
    delete camera;
}

void FPSCharacter::SetPosition(glm::vec3 position)
{
    Actor::SetPosition(position);
    camera->SetPosition(position);
}

void FPSCharacter::KeyInput(bool keys[])
{
    if (keys[GLFW_KEY_W])
	{
        camera->AddForwardMovement();
        //std::cout<<"H"<<std::endl;
		return;
	}
	if (keys[GLFW_KEY_S])
	{
		camera->AddBackwardMovement();
		return;
	}
	if (keys[GLFW_KEY_A])
	{
		camera->AddLeftMovement();
		return;
	}
	if (keys[GLFW_KEY_D])
	{
		camera->AddRightMovement();
		return;
	}
    if(keys[GLFW_KEY_E])
    {
        camera->AddUpMovement();
        return;
    }
    if(keys[GLFW_KEY_Q])
    {
        camera->AddDownMovement();
    }
}

void FPSCharacter::MouseInput(float x,float y)
{
    camera->AddRoation(x-lastx,lasty-y);
    lastx=x;
    lasty=y;
}

void FPSCharacter::InitLastMouseXY(float x,float y)
{
    this->lastx=x;
    this->lasty=y;
}

void FPSCharacter::SetDeltaTime(float time)
{
    this->daltaTime=time;
    camera->SetDeltaTime(time);
}

void FPSCharacter::Render()
{
    
    camera->Update();
    Actor::Render();
   // this->view=camera->view;  
   //std::cout<<"i render"<<std::endl;
}

void FPSCharacter::SetSpeed(float speed)
{
    this->camera->SetSpeed(speed);
}

void FPSCharacter::SetSenstity(float sensity)
{
    this->camera->SetSenstity(sensity);
}

void FPSCharacter::Update(float deltaTime)
{
   // std::cout<<"update"<<deltaTime<<std::endl;
    this->SetDeltaTime(deltaTime);
}