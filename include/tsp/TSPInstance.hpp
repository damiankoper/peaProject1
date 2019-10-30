#pragma once
#include "tsp/Matrix.hpp"
#include <iostream>
#include <vector>
class TSPInstance
{

public:
    TSPInstance(std::istream &dataStream);
    ~TSPInstance();
    
    void print(std::ostream &outputStream);
    int routeDistance(std::vector<int> path);
    int pathDistance(int from, int to);

    int getSize();

private:
    Matrix matrix;
};