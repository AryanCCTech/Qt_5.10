#pragma once
#include "Writer.h"
#include "Triangulation.h"

class ObjWriter : public Writer
{
public:
    void Write(const std::string& filename, const Triangulation& triangulation);

private:
    std::string formulateVertex(Triangulation triangulation, Point point);
    std::string formulateVertexNormal(Triangulation triangulation, Point point);
    std::string formulateFace(Triangulation triangulation, Triangle triangle);
};
