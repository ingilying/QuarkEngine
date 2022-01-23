#pragma once
#include <string>
#include <vector>
#include "Quark.h"
#include "Shader.h"
#include "untils.h"

class Sense{

public:
    std::string name;
    std::vector<Quark*> items;
    Sense();
    Sense(std::string name);
    ~Sense();
    void AddItem(Quark* actor);
    void DeleteItem(Quark* actor);
    void SetShader(Shader* shader);
    void Render();
};