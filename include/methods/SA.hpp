#pragma once
#include "methods/TSPInstanceSolver.hpp"

template <typename Move>
class SA : public TSPInstanceSolver
{

public:
    SA(float T = 10, float Tk = 1000, float a = 0.9999, float p = 0.8) : T(T), Tk(Tk), a(a), p(p) {}
    ~SA();

    Route solve(TSPInstance &tsp);

    float T;
    float Tk;
    float p;
    float a;
};