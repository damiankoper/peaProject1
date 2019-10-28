#include "tsp/TSPInstance.hpp"
#include <iostream>

int main(int argc, char **argv)
{
  TSPInstance* tsp = new TSPInstance(std::cin);

  tsp->print(std::cout);
  std::cout << std::endl<<tsp->routeDistance({0,1,2});
  
  return 0;
}