#pragma once
#include <glm/glm.hpp>

class Quark
{
private:
    /* data */
   
public:
    glm::vec3 position;
    glm::vec3 roation;
    glm::vec3 scale;
    glm::mat4 transform;
    Quark() : position(0,0,0),roation(0,0,0),scale(1,1,1)
    {
        
    };
    void SetPosition(glm::vec3 pos)
    {
        this->position=pos;
        glm::mat4 translform=glm::mat4(1.0f);
	    //std::cout<<GetPosition().x<<" "<<GetPosition().y<<" "<<GetPosition().z<<std::endl;
	    // translform = glm::translate(translform, GetPosition());
	    // translform = glm::rotate(translform, GetRoation().x, glm::vec3(1.0f, 0.0f, 0.0f));
	    // translform = glm::rotate(translform, GetRoation().y, glm::vec3(0.0f, 1.0f, 0.0f));
	    // translform = glm::rotate(translform, GetRoation().z, glm::vec3(0.0f, 0.0f, 1.0f));
	    // translform = glm::scale(translform, GetScale());
        // this->transform=translform;
    };
    glm::vec3 GetPosition()
    {
        return this->position;
    };
    void SetRoation(glm::vec3 roat)
    {
        this->roation=roat;
        // glm::mat4 translform=glm::mat4(1.0f);
	    // //std::cout<<GetPosition().x<<" "<<GetPosition().y<<" "<<GetPosition().z<<std::endl;
	    // translform = glm::translate(translform, GetPosition());
	    // translform = glm::rotate(translform, GetRoation().x, glm::vec3(1.0f, 0.0f, 0.0f));
	    // translform = glm::rotate(translform, GetRoation().y, glm::vec3(0.0f, 1.0f, 0.0f));
	    // translform = glm::rotate(translform, GetRoation().z, glm::vec3(0.0f, 0.0f, 1.0f));
	    // translform = glm::scale(translform, GetScale());
        // this->transform=translform;
    };
    glm::vec3 GetRoation()
    {
        return this->roation;
    };
    void SetScale(float scale)
    {
        this->scale=glm::vec3(scale,scale,scale);
        // glm::mat4 translform=glm::mat4(1.0f);
	    // //std::cout<<GetPosition().x<<" "<<GetPosition().y<<" "<<GetPosition().z<<std::endl;
	    // translform = glm::translate(translform, GetPosition());
	    // translform = glm::rotate(translform, GetRoation().x, glm::vec3(1.0f, 0.0f, 0.0f));
	    // translform = glm::rotate(translform, GetRoation().y, glm::vec3(0.0f, 1.0f, 0.0f));
	    // translform = glm::rotate(translform, GetRoation().z, glm::vec3(0.0f, 0.0f, 1.0f));
	    // translform = glm::scale(translform, GetScale());
        // this->transform=translform;
    };
    void SetScale(glm::vec3 scale)
    {
        this->scale=scale;
        // glm::mat4 translform=glm::mat4(1.0f);
	    // //std::cout<<GetPosition().x<<" "<<GetPosition().y<<" "<<GetPosition().z<<std::endl;
	    // translform = glm::translate(translform, GetPosition());
	    // translform = glm::rotate(translform, GetRoation().x, glm::vec3(1.0f, 0.0f, 0.0f));
	    // translform = glm::rotate(translform, GetRoation().y, glm::vec3(0.0f, 1.0f, 0.0f));
	    // translform = glm::rotate(translform, GetRoation().z, glm::vec3(0.0f, 0.0f, 1.0f));
	    // translform = glm::scale(translform, GetScale());
        // this->transform=translform;
    };
    glm::vec3 GetScale()
    {
        return scale;
    };
    virtual void Render()
    {
        
    };
};