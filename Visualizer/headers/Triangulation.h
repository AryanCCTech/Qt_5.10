#pragma once
#include "Triangle.h"
#include<vector>
#include <map>

class Triangulation
{
public:
    Triangulation();
    ~Triangulation();

    std::vector<double> UniqueNumbers;
    std::vector<Triangle> Triangles;
    std::vector<Point> uniqueVertex;
    std::vector<Point> uniqueNormal;
    std::map<Point, int> uniqueVertexMap;
    std::map<Point, int> uniqueNormalMap;
};