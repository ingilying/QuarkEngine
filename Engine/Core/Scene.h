#pragma once
#include <string>
#include <vector>
#include "Quark.h"
#include "Shader.h"
#include "untils.h"

class Scene{

public:
    std::string name;
    std::vector<Quark*> items;
    Scene();
    Scene(std::string name);
    ~Scene();
    void AddItem(Quark* actor);
    void DeleteItem(Quark* actor);
    void SetShader(Shader* shader);
    void Render();
    void Update(float deltaTime);
};