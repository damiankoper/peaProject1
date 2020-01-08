#pragma once
#include "methods/TSPInstanceSolver.hpp"
#include "methods/Cross.hpp"
template <typename Cross>
class GA : public TSPInstanceSolver
{

public:
    GA(float population = 100, float pc = 0.8, float pm = 0.01) : population(population), pc(pc), pm(pm) {}
    ~GA();

    Route solve(TSPInstance &tsp);

    float population;
    float pc;
    float pm;
};