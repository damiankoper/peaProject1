#include "methods/DP.hpp"
#include <iostream>
DP::DP()
{
}

DP::~DP()
{
}

void displayV(std::vector<std::vector<int>> v)
{
  for (auto &&i : v)
  {
    for (auto &&j : i)
    {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

Route DP::solve(TSPInstance &tsp)
{
  opt = std::vector<std::vector<int>>(tsp.getSize());
  for (size_t i = 0; i < tsp.getSize(); i++)
  {
    opt[i] = std::vector<int>(1 << (tsp.getSize() - 1), -1);

    opt[i][0] = tsp.pathDistance(i, 0);
  }

  displayV(opt);

  int result = subCompute(0, (1 << tsp.getSize() - 1) - 1, tsp);

  displayV(opt);

  Route r = Route();
  r.v.push_back(0);
  return r;
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
        min = v;
    }
    opt[from][S] = min;
  }
  return opt[from][S];
}