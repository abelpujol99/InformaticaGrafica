#pragma once
#include "Renderer.h"
#include <Program.h>
#include <objects/Axis.h>

class ExPlacementTriangles : public Renderer
{
    Program* program;
    GLuint VAO;
    GLuint VBO;
    Axis* axis;

public:
    ExPlacementTriangles(int width, int height);
    ~ExPlacementTriangles();
protected:
    void render(float dt);
};