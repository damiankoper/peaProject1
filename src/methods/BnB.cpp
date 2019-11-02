#include "methods/BnB.hpp"
#include <queue>
#include <vector>
BnB::BnB()
{
}

BnB::~BnB()
{
}

Route BnB::solve(TSPInstance &tsp)
{
  std::priority_queue<
      BnBPartialSolution,
      std::vector<BnBPartialSolution>,
      BnBPartialSolutionComparator>
      queue;

  BnBPartialSolution rootSolution;
  rootSolution.matrix = tsp.matrix;
  rootSolution.route.v.push_back(0);
  rootSolution.lowerBound = rootSolution.reduce();
  queue.push(rootSolution);

  BnBPartialSolution currentSolution;
  while (!queue.empty())
  {
    currentSolution = queue.top();

    if (currentSolution.route.v.size() == tsp.getSize())
    {
      return currentSolution.route;
    }

    int from = currentSolution.route.v.back();
    for (size_t to = 0; to < tsp.getSize(); to++)
    {
      int toCost = currentSolution.matrix[from][to];
      if (toCost != -1)
      {
        BnBPartialSolution deeperSolution = currentSolution;
        
        for (size_t i = 0; i < tsp.getSize(); i++)
        {
          deeperSolution.matrix[from][i] = -1;  
          deeperSolution.matrix[i][to] = -1;            
        }
        deeperSolution.matrix[to][from] = -1;
        deeperSolution.route.v.push_back(to);
        deeperSolution.lowerBound += 
          deeperSolution.reduce() + 
          toCost;

        queue.push(deeperSolution);
      }
    }

    queue.pop();
  }
  return currentSolution.route;
}