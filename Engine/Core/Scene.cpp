#include "Scene.h"
#include "Mesh.h"
#include "Actor.h"

Scene::Scene() : name("default"),items()
{

}

Scene::Scene(std::string name) : name(name),items()
{
    
}

Scene::~Scene()
{
    for(auto i : items)
    {
        if(i!=nullptr)
            delete i;
    }
}


void Scene::AddItem(Quark* actor)
{
    if(actor==nullptr)
        Print("警告:加入的Quark为nullptr");
    items.push_back(actor);
}

void Scene::DeleteItem(Quark* actor)
{
    for(auto iter=items.begin();iter!=items.end();++iter)
        if((*iter)==actor)
        {
            iter=items.erase(iter);
        }
}

void Scene::Render()
{
    for(Quark* i : items)
    {
        if(i==nullptr)
        {
            Print("Quark为nullptr");
        }else{
            i->Render();
        }
    }
}

void Scene::Update(float deltaTime)
{
    for(Quark* i : items)
    {
        if(Actor* j=dynamic_cast<Actor*>(i))
        {
            j->Update(deltaTime);
        }
    }
}

void Scene::SetShader(Shader* shader)
{
    for(auto i : items)
    {
        if(Mesh* j=dynamic_cast<Mesh*>(i))
        {
            j->SetShader(shader);
        }else if(Actor* j=dynamic_cast<Actor*>(i))
        {
            j->SetShader(shader);
        }
    }
}