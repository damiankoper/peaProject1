#include "methods/DP.hpp"
#include <iostream>
DP::DP()
{
}

DP::~DP()
{
}

Route DP::solve(TSPInstance &tsp)
{
  opt = std::vector<std::vector<int>>(tsp.getSize());
  path = std::vector<std::vector<int>>(tsp.getSize());
  for (size_t i = 0; i < tsp.getSize(); i++)
  {
    opt[i] = std::vector<int>(1 << (tsp.getSize() - 1), -1);
    path[i] = std::vector<int>(1 << (tsp.getSize() - 1), -1);
    opt[i][0] = tsp.pathDistance(i, 0);
  }

  route = Route();
  Set S = (1 << tsp.getSize() - 1) - 1;
  int result = subCompute(0, S, tsp);

  int last = 0;
  route.v.push_back(last);
  for (size_t i = 0; i < tsp.getSize() - 1; i++)
  {
    route.v.push_back(path[last][S]);
    last = route.v.back();
    S = S & ~(1 << (last - 1));
  }

  return route;
}

int DP::subCompute(int from, Set S, TSPInstance &tsp)
{
  int min = INT32_MAX;

  if (opt[from][S] == -1)
  {
    for (int to = 1; to < tsp.getSize(); to++)
    {
      Set R = S & ~(1 << (to - 1));
      if (from == to || (S & (1 << (to - 1))) == 0)
        continue;
      int v = tsp.pathDistance(from, to) + subCompute(to, R, tsp);
      if (v < min)
      {
        min = v;
        path[from][S] = to;
      }
    }
    opt[from][S] = min;
  }
  return opt[from][S];
}