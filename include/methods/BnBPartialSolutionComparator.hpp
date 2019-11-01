#pragma once
#include "methods/BnBPartialSolution.hpp"

class BnBPartialSolutionComparator
{
public:
    bool operator()(const BnBPartialSolution &left, const BnBPartialSolution &right);
};
