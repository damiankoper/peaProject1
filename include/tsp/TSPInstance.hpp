#pragma once
#include "tsp/Route.hpp"
#include <iostream>
#include <vector>
#include <istream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <numeric>

class TSPInstance
{

public:
    TSPInstance(std::istream &dataStream);
    ~TSPInstance();

    int getSize();

    void print(std::ostream &outputStream);

    int routeDistance(Route &route);
    int pathDistance(int from, int to);

private:
    Matrix matrix;
};