#ifndef GAME
#define GAME
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Shader.h"
#include "untils.h"
#include "Sense.h"
#include "Camera.h"
#include "KeyBoradSystem.h"

using namespace std;

class Game{

private:
    
public:
    string title;
    int width,height;
    GLFWwindow* window;
    bool is_mode_line,is_corlor;
    double lastx,lasty;
    float deltaTime,lastTime;
    //bool is_click;
    Shader* shader;
    Sense root;
    Camera cam;
    Game(string name,int width,int height);
    void Init();
    virtual void Begin();
    virtual void Loop();
    virtual void Free();
    virtual void Update();
    void FrameBufferSizeChange(GLFWwindow* window,int width,int height);
    virtual void ProcessInputEvent(GLFWwindow* window,int key,int scancode,int action,int mods);
    virtual void KeyInputEvent(int key,int mod,int action);
    virtual void MouseInput(double xpos,double ypos);
};

#endif