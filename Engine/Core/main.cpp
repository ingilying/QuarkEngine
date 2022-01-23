#include "QuarkGame.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIFHT 600
#define WINDOW_NAME "OpenGantEngine"

float triangle_vertices[] = {
	//位置				颜色
	-0.5f, -0.5f, 0.0f, 1.0f ,0.0f,
	 0.5f, -0.5f, 0.0f, 0.0f ,1.0f,
	 0.0f,  0.5f, 0.0f, 0.0f ,0.0f
};
vector<Vertex> triangle_vers;

unsigned int triangle_indices[] = {
	0,1,3,
	1,2,3
};

float quad_vertices[] = {
	0.5f, 0.5f, 0.0f,   // 右上角
	0.5f, -0.5f, 0.0f,  // 右下角
	-0.5f, -0.5f, 0.0f, // 左下角
	-0.5f, 0.5f, 0.0f   // 左上角
};
unsigned int quad_indices[] = {
	0,1,3,
	1,2,3
};

int main()
{
	QuarkGame game(string("QuarkEngine"),800,600);
	game.Init();
	game.Begin();
	game.Loop();
	game.Free();
	return 0;
}