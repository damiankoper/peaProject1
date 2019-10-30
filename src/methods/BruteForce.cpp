#include "methods/BruteForce.hpp"

BruteForce::BruteForce()
{
}

BruteForce::~BruteForce()
{
}

Route BruteForce::solve(TSPInstance &tsp)
{
  Route route = Route(tsp.getSize());
  Route bestRoute = route;
  int bestRouteDistance = INT32_MAX;

  do
  {
    int routeDistance = tsp.routeDistance(route);
    if(routeDistance < bestRouteDistance){
      bestRouteDistance = routeDistance;
      bestRoute = route;
    }
  } while (std::next_permutation(route.v.begin(), route.v.end()));

  return bestRoute;
}
