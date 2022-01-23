#pragma once

#ifndef UNTILS_H

#define  UNTILS_H

#include <glad/glad.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <glm/glm.hpp>
#include <filesystem>
namespace fs=std::filesystem;

void Print(const char* str);
const char* getRawFileContext(const char* name, char* content_out);
bool compileShader(unsigned int& shader, const char* source, GLenum type);

#endif