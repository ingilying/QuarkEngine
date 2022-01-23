#pragma once
#include "Mesh.h"
#include "Quark.h"
#include "Sense.h"

class Actor : public Quark
{
private:
	//Mesh* mesh;
	Sense* root;
	Shader* shader;
	bool bTexture;
public:
	Actor(Mesh *mesh);
	~Actor();
	void Render();
	void SetShader(Shader* shader);
	void SetPosition(glm::vec3 pos);
	void SetRoation(glm::vec3 roat);
	void SetScale(float scale);
	void SetScale(glm::vec3 scale);
	void EnableTexture(bool is);
};

