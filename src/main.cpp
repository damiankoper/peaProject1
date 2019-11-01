#include "tsp/TSPInstance.hpp"
#include "methods/BruteForce.hpp"
#include "methods/BnB.hpp"
#include <iostream>

int main(int argc, char **argv)
{
  TSPInstance *tsp = new TSPInstance(std::cin);

  BnB bf = BnB();
  bf.solve(*tsp).print(std::cout);
  return 0;
}