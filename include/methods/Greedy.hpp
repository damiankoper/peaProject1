#pragma once
#include "methods/TSPInstanceSolver.hpp"
#include <vector>
#include <algorithm>

class Greedy : public TSPInstanceSolver
{

public:
    Greedy();
    ~Greedy();

    Route solve(TSPInstance &tsp);
};