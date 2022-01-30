#pragma once
#include <glm/glm.hpp>

class Quark
{
private:
    /* data */
   
public:
    glm::vec3 position;
    glm::vec3 relativePosition;
    glm::vec3 roation;
    glm::vec3 relativeRoation;
    glm::vec3 scale;
    glm::vec3 relativeScale;
    glm::mat4 transform;
    Quark() : position(0,0,0),roation(0,0,0),scale(1,1,1),relativePosition(0,0,0),relativeRoation(0,0,0),relativeScale(0,0,0)
    {
        
    };
    void SetPosition(glm::vec3 pos)
    {
        this->position=pos;
        //glm::mat4 translform=glm::mat4(1.0f);
	    //std::cout<<GetPosition().x<<" "<<GetPosition().y<<" "<<GetPosition().z<<std::endl;
	    // translform = glm::translate(translform, GetPosition());
	    // translform = glm::rotate(translform, GetRoation().x, glm::vec3(1.0f, 0.0f, 0.0f));
	    // translform = glm::rotate(translform, GetRoation().y, glm::vec3(0.0f, 1.0f, 0.0f));
	    // translform = glm::rotate(translform, GetRoation().z, glm::vec3(0.0f, 0.0f, 1.0f));
	    // translform = glm::scale(translform, GetScale());
        // this->transform=translform;
    };
    void SetRelativePosition(glm::vec3 pos)
    {
        this->relativePosition=pos;
        this->position+=relativePosition;
    };
    glm::vec3 GetPosition()
    {
        return this->position;
    };
    void SetRoation(glm::vec3 roat)
    {
        this->roation=roat;
    };
    void SetRelativeRotaion(glm::vec3 roat)
    {
        this->relativeRoation=roat;
        this->roation+=relativePosition+roat;
    };
    glm::vec3 GetRoation()
    {
        return this->roation;
    };
    void SetScale(float scale)
    {
        this->scale=glm::vec3(scale,scale,scale);
    };
    void SetRelativeScale(float scale)
    {
        this->relativeScale=glm::vec3(scale,scale,scale);
        this->scale+=relativeScale;
    }
    void SetScale(glm::vec3 scale)
    {
        this->scale=scale;
    };
    void SetRealativeScale(glm::vec3 scale)
    {
        this->relativeScale=scale;
        this->scale+=scale;
    }
    glm::vec3 GetScale()
    {
        return scale;
    };
    virtual void Render()
    {
        
    };
};