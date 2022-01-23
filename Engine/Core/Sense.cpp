#include "Sense.h"
#include "Mesh.h"
#include "Actor.h"

Sense::Sense() : name("default"),items()
{

}

Sense::Sense(std::string name) : name(name),items()
{
    
}

Sense::~Sense()
{
    for(auto i : items)
    {
        if(i!=nullptr)
            delete i;
    }
}


void Sense::AddItem(Quark* actor)
{
    if(actor==nullptr)
        Print("警告:加入的Quark为nullptr");
    items.push_back(actor);
}

void Sense::DeleteItem(Quark* actor)
{
    for(auto iter=items.begin();iter!=items.end();++iter)
        if((*iter)==actor)
        {
            iter=items.erase(iter);
        }
}

void Sense::Render()
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

void Sense::SetShader(Shader* shader)
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