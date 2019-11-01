#pragma once
#include "tsp/Matrix.hpp"
#include "tsp/Route.hpp"

class BnBPartialSolution
{

public:
    BnBPartialSolution();
    ~BnBPartialSolution();

    int reduce();

    Matrix matrix;
    Route route;
    int lowerBound = INT32_MAX;

private:
    int minRow(Matrix matrix, int n);
    int minCol(Matrix matrix, int n);
};