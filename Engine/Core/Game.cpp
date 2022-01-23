#include "Game.h"


Game::Game(string name,int width,int height) : root()
{
    this->title=name;
    this->width=width;
    this->height=height;
    lastx=width/2;
    lasty=height/2;
}

void Game::Init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window=glfwCreateWindow(width,height,title.c_str(),nullptr,nullptr);
    if(window==nullptr)
    {
        Print("GLFW加载失败");
        glfwTerminate();
        exit(0);
        return;
    }
    Print("GLFW加载成功");
    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Print("GLAD加载失败");
        exit(0);
    }
    Print("GLAD加载成功");
    glViewport(0,0,width,height);
    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
    glfwSetWindowUserPointer(window,this);
    glfwSetFramebufferSizeCallback(window,[](GLFWwindow* window,int width,int height){
        Game* game=static_cast<Game*>(glfwGetWindowUserPointer(window));
        if(game!=nullptr)
            game->FrameBufferSizeChange(window,width,height);
    });
    glfwSetKeyCallback(window,[](GLFWwindow* window,int key,int scancode,int action,int mods){
        Game* game=(Game*)(glfwGetWindowUserPointer(window));
        if(game!=nullptr)
            KeyBoradSystem::CallKeyEvent(key,mods,action);
    });
    glfwSetCursorPosCallback(window,[](GLFWwindow *window,double xpos,double ypos){
        Game* game=(Game*)(glfwGetWindowUserPointer(window));
        if(game!=nullptr)
            game->MouseInput(xpos,ypos);
    });
    KeyBoradSystem::BindKeyLoopEvent(std::bind(&Camera::KeyInput,&cam,placeholders::_1));
}

void Game::Begin()
{
    shader=new Shader("shaders/basic.vs","shaders/basic.fs");
}

void Game::FrameBufferSizeChange(GLFWwindow* window,int width,int height)
{
    this->width=width;
    this->height=height;
    glViewport(0,0,width,height);
}


void Game::MouseInput(double xpos,double ypos)
{
    cam.MouseInput(xpos-lastx,lasty-ypos);
    lastx=xpos;
    lasty=ypos;
}


void Game::ProcessInputEvent(GLFWwindow* window,int key,int scancode,int action,int mods)
{
    
}


void Game::Loop()
{
    shader->SetBool("bTexture",false);
    while (!glfwWindowShouldClose(window))
	{
        float currentTime=glfwGetTime();
        deltaTime=currentTime-lastTime;
        lastTime=currentTime;
        cam.SetDeltaTime(deltaTime);
        KeyBoradSystem::CallKeyLoopEvent();
        cam.Update();
        Update();
		glm::mat4 view = cam.view;
		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.6f));
		shader->SetMat4("projection", projection);
		shader->SetMat4("view", view);
        root.SetShader(shader);
		//triangle->SetPosition(trpos);
		//triangle.SetPosition(glm::vec3(1.0f,triangle.GetPosition().y+0.5f,0.0f));
		//Render
		glClearColor(44/255, 44/255, 44/255, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//triangle->Render();
        root.Render();
		glfwSwapBuffers(window);
		glfwPollEvents();
		//Sleep(50);
	}
}

void Game::KeyInputEvent(int key,int mod,int action)
{

}


void Game::Free()
{
    //delete shader;
    //delete window;
    glfwTerminate();
}

void Game::Update()
{
   // Print("I'm Game.");
}