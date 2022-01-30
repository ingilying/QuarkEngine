#pragma once
#include "Actor.h"
#include "Character.h"

class FPSCharacter : public Character
{
private:
    float lastx,lasty;
    float daltaTime;
public:
    Camera *camera;
    //glm::mat4 view;
    FPSCharacter();
    ~FPSCharacter();
    void SetDeltaTime(float time);
    void Update(float deltaTime) override;
    void SetPosition(glm::vec3 position);
    void InitLastMouseXY(float x,float y);
    void KeyInput(bool keys[]);
    void MouseInput(float x,float y);
    void SetSpeed(float speed);
    void SetSenstity(float senstity);
    void Render();
};