#pragma once
#include <vector>
#include <functional>

#define PLACEHOLIDERS_3 placeholders::_1,placeholders::_2,placeholders::_3

class KeyBoradSystem
{
public:
    static std::vector<std::function<void(int,int,int)>> pFuns;
    static std::vector<std::function<void(bool[])>> pFuns2;
    static bool keys[1025];
    static void BindKeyEvent(std::function<void(int,int,int)> fun);
    static void BindKeyLoopEvent(std::function<void(bool[])> fun);
    static void CallKeyEvent(int key,int mod,int action);
    static void Update(int key,int mod,int action);
    static void CallKeyLoopEvent();
};
