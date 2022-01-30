#pragma once
#include <string>
#include <glad/glad.h>
#include "FPSCharacter.h"
#include <GLFW/glfw3.h>
//#include <windows.h>
#include <iostream>
#include <glm/glm.hpp>
#include "Game.h"
#include "Mesh.h"
#include "Shader.h"
#include "Actor.h"

using namespace std;
class QuarkGame : public Game
{
private:
	glm::vec3 trpos;
	Mesh *mesh;
	Actor *triangle;
	FPSCharacter *character;
public:
	QuarkGame(string name,int width,int height);
	void Begin();
	void Free();
	void Update();
	//void FrameBufferSizeChange(GLFWwindow *window,int width,int height);
	//virtual void InputEvent(int key,int mod,int action);
	void KeyInputEvent(int key,int mod,int action);
};

