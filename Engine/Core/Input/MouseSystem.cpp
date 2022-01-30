#include "MouseSystem.h"

std::vector<std::function<void(float,float)>> MouseSystem::pFuns;

void MouseSystem::BindEvent(std::function<void(float,float)> event)
{
    pFuns.push_back(event);
}

void MouseSystem::CallEvent(float x,float y)
{
    for(auto i : pFuns)
    {
        i(x,y);
    }
}