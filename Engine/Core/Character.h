#pragma once
#include <glm/glm.hpp>
#include "Camera.h"
#include "Actor.h"

class Character : public Actor
{
public:
    //Camera *camera;
    //virtual Character();
    Character(){};
    ~Character(){};
    virtual void SetDeltaTime(float time) = 0;
   // virtual void SetPosition(glm::vec3 position);
    virtual void SetSpeed(float speed) = 0;
    virtual void SetSenstity(float senstity) = 0;
};