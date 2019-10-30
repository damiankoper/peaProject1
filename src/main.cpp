#include "tsp/TSPInstance.hpp"
#include "methods/BruteForce.hpp"
#include <iostream>

int main(int argc, char **argv)
{
  TSPInstance tsp = TSPInstance(std::cin);
  tsp.print(std::cout);
  BruteForce bf = BruteForce();
  std::cout << 
    std::endl << 
    tsp.routeDistance(
      bf.solve(tsp)
    ) << 
    std::endl;
  return 0;
}