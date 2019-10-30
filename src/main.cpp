#include "tsp/TSPInstance.hpp"
#include "methods/BruteForce.hpp"
#include <iostream>

int main(int argc, char **argv)
{
  TSPInstance *tsp = new TSPInstance(std::cin);

  BruteForce bf = BruteForce();
  bf.solve(*tsp).print(std::cout);
  return 0;
}