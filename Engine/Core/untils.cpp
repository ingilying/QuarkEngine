#include "untils.h"

void Print(const char* str)
{
	std::cout << str << std::endl;
}


const char* getRawFileContext(const char* name, char* content_out)
{
	//char p[512];
	using namespace std;
	//GetCurrentDirectory(512,p);
	//getcwd(p, 512);
	string cur=fs::current_path();
	ifstream file;
	stringstream stream;
	cur.append("/");
	cur.append(name);
	cout << cur << endl;
	file.open(cur);
	//char context[1024] = "";
	string str;
	while (!file.eof())
	{
		string line;
		getline(file, line);
		//cout << line << endl;
		str.append(line);
		str.append("\n");
	}
	file.close();
	//Print(stream.str());
	//cout << str << endl;
	//char *content = new char[1024];
	int len = str.length() + 1;
	str.copy(content_out, len, 0);
	content_out[len - 1] = '\0';
	//Print(content_out);
	return content_out;
}

bool compileShader(unsigned int& shader, const char* source, GLenum type)
{
	shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	int success; char info[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		Print("着色器编译失败!");
		Print(source);
		glGetShaderInfoLog(shader, 512, NULL, info);
		Print("错误");
		Print(info);
		return false;
	}
	return true;
}