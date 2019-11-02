#pragma once
#include "methods/TSPInstanceSolver.hpp"
#include "tsp/Route.hpp"
#include "tsp/TSPInstance.hpp"
#include <vector>

typedef unsigned int Set;

class DP : public TSPInstanceSolver
{
public:
    DP();
    ~DP();

    Route solve(TSPInstance &tsp);

private:
    std::vector<std::vector<int>> opt; // g(i, S) -> g(int, {0b000000})
    int subCompute(int i, Set S, TSPInstance &tsp);
};