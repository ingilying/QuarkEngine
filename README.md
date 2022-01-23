# QuarkEngine  
---------
## 1.介绍  
 QuarkEngine是一款由IngilYing完成的一款轻量化3D游戏引擎。QuarkEngine基于OpenGL图形API。它制作的缘由是因为学习UE4游戏引擎时发现UE4虽然开源强大，但是也存在一个非常明显的缺点就是开发成本非常的高，他的源码整整几十个G，条件不是很好的开发者并不能承担得起这样的开发成本，于是我便萌生了要开发游戏引擎的念头。

## 2.架构  
首先每个游戏都有一个默认的Sense[^Sense],开发者可以通过编写自己的Sense来设置默认的Sense。
任何3D或者2D物体都继承于Quark。Quark定义了物体最基本的坐标，旋转和缩放等，里面还定义了一些基本的方法如Render,SetXXX，GetXXX等。
Mesh类基于Quark，它作为一种资源，它负责描述物体的形状。Actor基于Quark,它里面定义了一个Sense，所以你只需在它的Begin阶段添加你的物体进入这个Sense即可。
下面展示了一个Game类的子类把物体初始化并加入场景的过程。
```c++
void HelloGame::Begin()
{
    Mesh *mesh=new Mesh("models/block.quark");
    mesh->SetShader(shader);
    Actor *block=new Actor(mesh);
    block.SetPosition(glm::vec3(1.0f,5.0f,0.0f);
    root.AddItem(block);
}
```
  
## 3.依赖的库
* OpenGL
* [GLFW](https://www.glfw.org/)
* [GLAD](https://github.com/Dav1dde/glad)
* [stb_image.h](https://github.com/nothings/stb)
[^Sense]:Sense是QuarkEngine里的场景
