#pragma once
#include "Renderer.h"
#include <Program.h>
#include <objects/Axis.h>
#include <objects/Cube.h>

class ExPlacementCube : public Renderer
{
    Program* program;
    GLuint VAO;
    GLuint VBO;
    Cube cube;
    Axis* axis;

public:
    ExPlacementCube(int width, int height);
    ~ExPlacementCube();
protected:
    void render(float dt);
};

