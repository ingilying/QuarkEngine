#pragma once
#include "Mesh.h"
#include "Quark.h"
#include "Scene.h"

class Actor : public Quark
{
private:
	//Mesh* mesh;
	Scene* root;
	Shader* shader;
	bool bTexture;
public:
	Actor(Mesh *mesh);
	Actor();
	~Actor();
	void Render();
	virtual void Update(float deltaTime);
	void SetShader(Shader* shader);
	void SetPosition(glm::vec3 pos);
	void SetRoation(glm::vec3 roat);
	void SetScale(float scale);
	void SetScale(glm::vec3 scale);
	void EnableTexture(bool is);
};

