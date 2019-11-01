#include "methods/BnBPartialSolutionComparator.hpp"

bool BnBPartialSolutionComparator::operator()(const BnBPartialSolution  &left, const BnBPartialSolution &right)
{
  return left.lowerBound > right.lowerBound;
}