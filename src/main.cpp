#include "tsp/TSPInstance.hpp"
#include "methods/BruteForce.hpp"
#include "methods/BnB.hpp"
#include "methods/DP.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
  std::ifstream f;
  f.open("bin/data.txt", std::ios::in);
  //TSPInstance *tsp = new TSPInstance(std::cin);
  TSPInstance *tsp = new TSPInstance(f);

  BruteForce bf = BruteForce();
  Route r1 = bf.solve(*tsp);
  r1.print(std::cout);
  std::cout << tsp->routeDistance(r1) << std::endl
            << std::endl;

  BnB bnb = BnB();
  Route r2 = bnb.solve(*tsp);
  r2.print(std::cout);
  std::cout << tsp->routeDistance(r2) << std::endl
            << std::endl;

  DP dp = DP();
  Route r3 = dp.solve(*tsp);
  r3.print(std::cout);
  std::cout << tsp->routeDistance(r3) << std::endl
            << std::endl;

  return 0;
}