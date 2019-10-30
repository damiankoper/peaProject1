#pragma once
#include "tsp/TSPInstance.hpp"
#include "tsp/Route.hpp"
#include <vector>

class TSPInstanceSolver
{

public:
    virtual Route solve(TSPInstance &tsp) = 0;
    virtual ~TSPInstanceSolver() {};
};