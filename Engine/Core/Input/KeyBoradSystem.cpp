#include "KeyBoradSystem.h"
#include <GLFW/glfw3.h>

std::vector<std::function<void(int,int,int)>> KeyBoradSystem::pFuns=std::vector<std::function<void(int,int,int)>>();
std::vector<std::function<void(bool[])>> KeyBoradSystem::pFuns2=std::vector<std::function<void(bool[])>>();
bool KeyBoradSystem::keys[1025];
//bool KeyBoradSystem::keys[1025];
void KeyBoradSystem::BindKeyEvent(std::function<void(int,int,int)> fun)
{
    pFuns.push_back(fun);
}

void KeyBoradSystem::BindKeyLoopEvent(std::function<void(bool[])> fun)
{
    pFuns2.push_back(fun);
}

void KeyBoradSystem::Update(int key,int mod,int action)
{
    if(key>=0&&key<=1024)
    {
        if(action==GLFW_PRESS)
            keys[key]=true;
        else if(action==GLFW_RELEASE)
            keys[key]=false;
    }
}

void KeyBoradSystem::CallKeyLoopEvent()
{
    for(auto i : pFuns2)
    {
        i(keys);
    }
}

void KeyBoradSystem::CallKeyEvent(int key,int mod,int action)
{
    //std::function ap;
    Update(key,mod,action);
    for(auto i : pFuns)
    {
        i(key,mod,action);
    }
}