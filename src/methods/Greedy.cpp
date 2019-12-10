#include "methods/Greedy.hpp"

Greedy::Greedy()
{
}

Greedy::~Greedy()
{
}

Route Greedy::solve(TSPInstance &tsp)
{
  Route route = Route();
  std::vector<bool> visited = std::vector<bool>(tsp.getSize(), false);
  visited[0] = true;
  route.v.push_back(0);
  for (int i = 0; i < tsp.getSize() - 1; i++)
  {
    int min = 0;
    int minDist = INT32_MAX;
    for (int j = 0; j < tsp.getSize(); j++)
    {
      if (visited[j])
        continue;
      if (minDist > tsp.pathDistance(route.v[route.v.size() - 1], j))
      {
        minDist = tsp.pathDistance(route.v[route.v.size() - 1], j);
        min = j;
      }
    }
    visited[min] = true;
    route.v.push_back(min);
  }

  return route;
}
