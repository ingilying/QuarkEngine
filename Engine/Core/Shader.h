#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "untils.h"

class Shader
{
public:
	unsigned int Index;
	Shader(const char* path, const char* path2);
	void Use();
	void SetBool(const std::string& name, bool value);
	void SetInt(const std::string& name, int value);
	void SetFloat(const std::string& name, float value);
	void SetFloatVec3(const std::string& name, glm::vec3 value);
	void SetMat4(const std::string& name, glm::mat4 value);
};


#endif // SHADER_H
