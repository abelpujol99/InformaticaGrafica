#pragma once
#include "Renderer.h"
class GeometryEx1 : public Renderer
{

private: 

    Program* program;
    GLuint VAO;
    GLuint VBO;
    Axis* axis;

protected:
    void render(float dt);

public: 

	GeometryEx1(int width, int height);
	~GeometryEx1();



};

