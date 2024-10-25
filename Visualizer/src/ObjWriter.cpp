#include "ObjWriter.h"
#include<fstream>
#include<iomanip>
#include "ObjWriter.h"
#include <iostream>

#include <QSet> 
void ObjWriter::Write(const std::string& filename, const Triangulation& triangulation)
{
    std::ofstream outfile(filename);
    std::vector<Point> allNormals;
    QSet<Point> points = { Point(1,2,3),Point(2,3,4)};
    for (auto i : points) {
        std::cout << i.X() << " " << i.Y() << " " << i.Z() << std::endl;
    }
    if (outfile.is_open())
    {
        for each (Point pt in triangulation.uniqueVertex)
        {
            outfile << std::fixed << std::setprecision(6)
                << formulateVertex(triangulation, pt);
        }
        for each (Point normals in triangulation.uniqueNormal)
        {
            outfile << std::fixed << std::setprecision(6)
                << formulateVertexNormal(triangulation, normals);
        }
        for each (Triangle faces in triangulation.Triangles)
        {
            allNormals.push_back(faces.Normal());
            outfile << std::fixed << std::setprecision(6)
                << formulateFace(triangulation, faces) << std::endl;
        }
    }
}

std::string ObjWriter::formulateVertex(Triangulation triangulation, Point point)
{
    double x = triangulation.UniqueNumbers[point.X()];
    double y = triangulation.UniqueNumbers[point.Y()];
    double z = triangulation.UniqueNumbers[point.Z()];

    return "v " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + "\n";
}

std::string ObjWriter::formulateVertexNormal(Triangulation triangulation, Point point)
{
    double x = triangulation.UniqueNumbers[point.X()];
    double y = triangulation.UniqueNumbers[point.Y()];
    double z = triangulation.UniqueNumbers[point.Z()];

    return "vn " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + "\n";
}

std::string ObjWriter::formulateFace(Triangulation triangulation, Triangle triangle)
{
    // v vt vn
    std::string new1 = std::to_string(triangulation.uniqueVertexMap[triangle.P1()]+1) + "//" + std::to_string(triangulation.uniqueNormalMap[triangle.Normal()]+1)
        + " " + std::to_string(triangulation.uniqueVertexMap[triangle.P2()] + 1) + "//" + std::to_string(triangulation.uniqueNormalMap[triangle.Normal()] + 1)
        + " " + std::to_string(triangulation.uniqueVertexMap[triangle.P3()] + 1) + "//" + std::to_string(triangulation.uniqueNormalMap[triangle.Normal()] + 1);
    return "f " + new1;
}
