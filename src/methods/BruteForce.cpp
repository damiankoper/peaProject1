#include "methods/BruteForce.hpp"
#include <numeric>
#include <algorithm>
BruteForce::BruteForce()
{
}

BruteForce::~BruteForce()
{
}

std::vector<int> BruteForce::solve(TSPInstance &tsp)
{
  std::vector<int> route = std::vector<int>(tsp.getSize());
  std::iota(route.begin(), route.end(), 0);
  std::vector<int> bestRoute = route;
  int bestRouteDistance = INT32_MAX;

  do
  {
    int routeDistance = tsp.routeDistance(route);
    if(routeDistance < bestRouteDistance){
      bestRouteDistance = routeDistance;
      bestRoute = route;
    }
  } while (std::next_permutation(route.begin(), route.end()));

  return bestRoute;
}
