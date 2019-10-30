#pragma once
#include "methods/TSPInstanceSolver.hpp"
#include <vector>
#include <algorithm>

class BruteForce : public TSPInstanceSolver
{

public:
    BruteForce();
    ~BruteForce();

    Route solve(TSPInstance &tsp);
};