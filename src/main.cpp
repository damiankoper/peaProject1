#include "tsp/TSPInstance.hpp"
#include "methods/BruteForce.hpp"
#include <iostream>

int main(int argc, char **argv)
{
  TSPInstance* tsp = new TSPInstance(std::cin);
    
  BruteForce bf = BruteForce();
  std::cout << 
    std::endl << 
    tsp->routeDistance(
      bf.solve(*tsp)
    ) << 
    std::endl;
  return 0;
}