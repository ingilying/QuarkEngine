#include "Camera.h"
#include "GLFW/glfw3.h"
#include <iostream>

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
    glm::quat reveDirec=glm::conjugate(direction);
    glm::mat4 roat=glm::mat4_cast(reveDirec);
    glm::mat4 translation=glm::translate(glm::mat4(1.0),-position);
    view=roat * translation;
    //std::cout<<"i am been to render."<<std::endl;
}

void Camera::UpdateData()
{
    glm::quat x=glm::angleAxis(glm::radians(UpAngle),glm::vec3(1,0,0));
    glm::quat y=glm::angleAxis(glm::radians(-RightAngle),glm::vec3(0,1,0));
    direction=y*x;
}

void Camera::AddForwardMovement()
{
    glm::quat qua=direction * glm::quat(0,0,0,-1) * glm::conjugate(direction);
    CamFront=glm::vec3(qua.x,qua.y,qua.z);
    float realSpeed=Speed * deltaTime;
    position+=CamFront * realSpeed;
    //std::cout<<"i forward."<<std::endl;
}

void Camera::AddBackwardMovement()
{
    glm::quat qua=direction * glm::quat(0,0,0,-1) * glm::conjugate(direction);
    CamFront=glm::vec3(qua.x,qua.y,qua.z);
    float realSpeed=Speed * deltaTime;
    position-=CamFront * realSpeed;
}

void Camera::AddRightMovement()
{
    glm::quat qua=direction * glm::quat(0,0,0,-1) * glm::conjugate(direction);
    CamFront=glm::vec3(qua.x,qua.y,qua.z);
    CamRight=glm::normalize(glm::cross(CamFront,CamUp));
    float realSpeed=deltaTime*Speed;
    position+=CamRight * realSpeed;
}

void Camera::AddLeftMovement()
{
    glm::quat qua=direction * glm::quat(0,0,0,-1) * glm::conjugate(direction);
    CamFront=glm::vec3(qua.x,qua.y,qua.z);
    CamRight=glm::normalize(glm::cross(CamFront,CamUp));
    float realSpeed=deltaTime*Speed;
    position-=CamRight * realSpeed;
}

void Camera::AddUpMovement()
{
    float realSpeed=deltaTime*Speed;
    position+=CamUp * realSpeed;
}

void Camera::AddDownMovement()
{
    float realSpeed=deltaTime*Speed;
    position-=CamUp * realSpeed;
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

void Camera::AddRoation(float xoffest,float yoffest)
{
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