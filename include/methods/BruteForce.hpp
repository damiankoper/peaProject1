#pragma once
#include "methods/TSPInstanceSolver.hpp"
#include <vector>
class BruteForce : public TSPInstanceSolver
{

public:
    BruteForce();
    ~BruteForce();

    std::vector<int> solve(TSPInstance &tsp);
};