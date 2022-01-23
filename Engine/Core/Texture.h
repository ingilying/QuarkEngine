#pragma once
#include <string>
#include <glad/glad.h>
//#include "Mesh.h"

struct STexture {
	unsigned int id;
	std::string type;
	STexture()
	{};
	STexture(unsigned int id,std::string type)
	{
		this->id=id;
		this->type=type;
	}
};

class Texture
{
private:
    std::string file_name;
    int width,height,channels;
    unsigned char* data;
    STexture tex;
public:
    Texture(std::string name);
    void Render();
};