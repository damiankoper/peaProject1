#pragma once
#include "methods/TSPInstanceSolver.hpp"
#include "methods/BnBPartialSolution.hpp"
#include "methods/BnBPartialSolutionComparator.hpp"
class BnB : public TSPInstanceSolver
{

public:
    BnB();
    Route solve(TSPInstance &tsp);
    ~BnB();
};