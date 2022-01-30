#pragma once
#include <vector>
#include <functional>

class MouseSystem
{
public:
    static std::vector<std::function<void(float,float)>> pFuns;
    static void BindEvent(std::function<void(float,float)> event);
    static void CallEvent(float x,float y);
};