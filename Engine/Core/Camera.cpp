#include "Camera.h"
#include "GLFW/glfw3.h"

Camera::Camera() : Quark() 
{
    this->SetPosition(glm::vec3(0.0f,0.0f,0.0f));
    CamFront=glm::vec3(0.0f,0.0f,-1.0f);
    CamUp=glm::vec3(0.0f,1.0f,0.0f);
    direction=glm::quat(0,0,0,-1);
    Speed=1.0f;
    Senstity=0.01f;
    UpdateData();
}
void Camera::Update()
{
    //float radius=10.0f;
    //position.x=sin(glfwGetTime())*radius;
    //position.y=cos(glfwGetTime())*radius;
    
    //view=glm::lookAt(position,position+CamFront,CamUp);

    glm::quat reveDirec=glm::conjugate(direction);
    glm::mat4 roat=glm::mat4_cast(reveDirec);
    glm::mat4 translation=glm::translate(glm::mat4(1.0),-position);

   // glm::quat qPitch=glm::angleAxis(Pitc)


    view=roat * translation;
}

void Camera::UpdateData()
{
    glm::quat x=glm::angleAxis(glm::radians(UpAngle),glm::vec3(1,0,0));
    glm::quat y=glm::angleAxis(glm::radians(-RightAngle),glm::vec3(0,1,0));
    direction=y*x;
}


void Camera::KeyInput(bool keys[])
{
    //float speed=0.1f;
    glm::quat qua=direction * glm::quat(0,0,0,-1) * glm::conjugate(direction);
    CamFront=glm::vec3(qua.x,qua.y,qua.z);
    CamRight=glm::normalize(glm::cross(CamFront,CamUp));
    float realSpeed=deltaTime*Speed;
    //CamRight=
    if (keys[GLFW_KEY_W])
	{
        position+=CamFront * realSpeed;
		return;
	}
	if (keys[GLFW_KEY_S])
	{
		position-=CamFront * realSpeed;
		return;
	}
	if (keys[GLFW_KEY_A])
	{
		position-=CamRight * realSpeed;
		return;
	}
	if (keys[GLFW_KEY_D])
	{
		position+=CamRight * realSpeed;
		return;
	}
    if(keys[GLFW_KEY_SPACE])
    {
        position+=CamUp * realSpeed;
        return;
    }
    if(keys[GLFW_KEY_LEFT_SHIFT])
    {
        position-=CamUp * realSpeed;
    }
}

void Camera::SetDeltaTime(float delTime)
{
    this->deltaTime=delTime;
}

void Camera::SetSpeed(float speed)
{
    this->Speed=speed;
}

void Camera::SetSenstity(float senstity)
{
    this->Senstity=senstity;
}

void Camera::MouseInput(float xoffest,float yoffest)
{
    //float sensitivity=0.01f;
    xoffest*=Senstity;
    yoffest*=Senstity;
    RightAngle+=xoffest;
    UpAngle+=yoffest;
    if(UpAngle>89.0f)
        UpAngle=89.0f;
    if(UpAngle<-89.0f)
        UpAngle=-89.0f;
    UpdateData();
}