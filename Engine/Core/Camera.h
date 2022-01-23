#pragma once
#include "Quark.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

class Camera : public Quark
{

public:
    glm::vec3 CamDirection;
    glm::vec3 CamRight;
    glm::vec3 CamFront;
    glm::vec3 CamUp;
    glm::quat direction;
    glm::mat4 view;
    float RightAngle;
    float UpAngle;
    float Speed;
    float Senstity;
    float deltaTime;
    bool is_click;
    Camera();
    void Update();
    //void AddMove(glm::vec3 dvec);
    void UpdateData();
    void SetDeltaTime(float del);
    void SetSpeed(float speed);
    void SetSenstity(float senstity);
    void KeyInput(bool keys[]);
    void MouseInput(float xoffest,float yoffest);
};