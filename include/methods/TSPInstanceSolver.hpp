#pragma once
#include "TSPInstance.hpp"
#include <vector>

class TSPInstanceSolver
{

public:
    TSPInstanceSolver();

    virtual std::vector<int> solve(TSPInstance &tsp) = 0;
    virtual ~TSPInstanceSolver();
};