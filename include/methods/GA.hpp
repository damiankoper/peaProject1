#pragma once
#include "methods/TSPInstanceSolver.hpp"
#include "methods/Cross.hpp"
template <typename Cross>
class GA : public TSPInstanceSolver
{

public:
    GA(int population = 100, float pc = 0.8, float pm = 0.01, int generations = 10000, int bestDistance = 1)
        : population(population), pc(pc), pm(pm), generations(generations), bestDistance(bestDistance)
    {
    }
    ~GA();

    Route solve(TSPInstance &tsp);
    int bestDistance;
    int population;
    float pc;
    float pm;
    int generations;
};