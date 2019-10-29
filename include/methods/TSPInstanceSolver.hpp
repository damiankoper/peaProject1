#pragma once
#include "tsp/TSPInstance.hpp"
#include <vector>

class TSPInstanceSolver
{

public:
    virtual std::vector<int> solve(TSPInstance &tsp) = 0;
    virtual ~TSPInstanceSolver() {};
};