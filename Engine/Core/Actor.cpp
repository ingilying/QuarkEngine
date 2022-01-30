#include "Actor.h"


Actor::Actor(Mesh *mesh) : Quark() 
{
	//this->mesh = mesh;
	root=new Scene();
	root->AddItem(mesh);
}

Actor::Actor() : Quark()
{
	root=new Scene();
}

void Actor::Render()
{
	for(auto i : root->items)
	{
		if(Mesh *j=dynamic_cast<Mesh*>(i))
			j->EnableTexture(bTexture);
		i->Render();
	}
}

void Actor::Update(float deltaTime)
{
	for (auto i : root->items)
	{
		if(Actor *j=dynamic_cast<Actor*>(i))
			j->Update(deltaTime);
	}
	
}


void Actor::SetShader(Shader* shader)
{
	this->shader=shader;
	for(auto i : root->items)
	{
		if(Mesh* j=dynamic_cast<Mesh*>(i))
		{
			j->SetShader(shader);
		}
	}
}

void Actor::SetPosition(glm::vec3 pos)
{
	Quark::SetPosition(pos);
	for(auto i : root->items)
	{
		i->SetPosition(pos);
	}
}

void Actor::SetRoation(glm::vec3 roat)
{
	Quark::SetRoation(roat);
	for (auto i : root->items)
	{
		i->SetRoation(roat);
	}
	
}

void Actor::SetScale(glm::vec3 scale)
{
	Quark::SetScale(scale);
	for(auto i : root->items)
	{
		i->SetScale(scale);
	}
}

void Actor::SetScale(float scale)
{
	Quark::SetScale(scale);
	for(auto i : root->items)
	{
		i->SetScale(scale);
	}
}

void Actor::EnableTexture(bool is)
{
	this->bTexture=is;
	for(auto i : root->items)
	{
		if(Mesh *j=dynamic_cast<Mesh*>(i))
		{
			j->EnableTexture(is);
		}
	}
}


Actor::~Actor()
{
	delete root;
}