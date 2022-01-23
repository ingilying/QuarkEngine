#include "Shader.h"

Shader::Shader(const char* path, const char* path2)
{
	unsigned int vertexShader, fragmentShader;
	char vsshadersource[1024];
	getRawFileContext(path, vsshadersource);
	char fsshadersource[1024];
	getRawFileContext(path2, fsshadersource);
	int success; char info[512];
	if (!compileShader(vertexShader, vsshadersource, GL_VERTEX_SHADER))
		return;
	if (!compileShader(fragmentShader, fsshadersource, GL_FRAGMENT_SHADER))
		return;
	Index = glCreateProgram();
	glAttachShader(Index, vertexShader);
	glAttachShader(Index, fragmentShader);
	glLinkProgram(Index);
	glGetProgramiv(Index, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(Index, 512, NULL, info);
		Print("着色器链接失败!");
		Print(info);
		return;
	}
	glDeleteShader(vertexShader);//链接完成后删除着色器对象
	glDeleteShader(fragmentShader);
}

void Shader::Use()
{
	glUseProgram(Index);
}

void Shader::SetBool(const std::string& name, bool value)
{
	glUniform1i(glGetUniformLocation(Index, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value)
{
	glUniform1i(glGetUniformLocation(Index, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value)
{
	glUniform1f(glGetUniformLocation(Index, name.c_str()), value);
}

void Shader::SetFloatVec3(const std::string& name, glm::vec3 value)
{
	glUniform3f(glGetUniformLocation(Index, name.c_str()), value.x,value.y, value.z);
}

void Shader::SetMat4(const std::string& name, glm::mat4 value)
{
	glUniformMatrix4fv(glGetUniformLocation(Index, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}
