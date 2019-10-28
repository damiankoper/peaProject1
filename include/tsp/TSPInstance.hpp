#pragma once
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

private:
    int size;
    int **matrix;
};