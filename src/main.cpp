#include "tsp/TSPInstance.hpp"
#include "methods/BruteForce.hpp"
#include "methods/BnB.hpp"
#include "methods/DP.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
enum Menu
{
  exitt = 0,
  read,
  randomm,
  bf,
  bnb,
  dp,
};

void displayMenu()
{
  std::cout << "[0] Wyjdź" << std::endl;
  std::cout << "[1] Wczytaj" << std::endl;
  std::cout << "[2] Losowy" << std::endl;
  std::cout << "[3] BruteForce" << std::endl;
  std::cout << "[4] Branch and Bound" << std::endl;
  std::cout << "[5] Held-Karp" << std::endl;
}

void solve(TSPInstance *tsp, TSPInstanceSolver *solver, std::stringstream &buff)
{
  if (tsp == nullptr)
    buff << "Nie wczytano macierzy!" << std::endl;
  else
  {
    buff << std::endl;
    Route r = solver->solve(*tsp);
    r.print(buff);
    buff << tsp->routeDistance(r)
         << std::endl
         << std::endl;
  }
}

int main(int argc, char **argv)
{
  srand(time(NULL));
  std::ifstream f;
  TSPInstance *tsp = nullptr;
  bool exitt = false;
  int menuSelect;
  std::stringstream buff;
  std::string input;

  while (!exitt)
  {
    system("clear");
    if (tsp != nullptr)
      tsp->print(std::cout);
    std::cout << buff.str() << std::endl;
    buff.str("");
    displayMenu();
    std::cin >> menuSelect;
    switch (menuSelect)
    {
    case Menu::exitt:
      exitt = true;
      break;
    case Menu::read:
      std::cout << "Podaj nazwę pliku: ";
      std::cin >> input;
      if (tsp != nullptr)
      {
        delete tsp;
      }
      f.open("data/" + input + ".txt", std::ios::in);
      tsp = new TSPInstance(f);
      f.close();
      break;
    case Menu::randomm:
      std::cout << "Podaj ilość miast: ";
      std::cin >> menuSelect;
      if (tsp != nullptr)
      {
        delete tsp;
      }
      tsp = new TSPInstance(menuSelect);
      break;
    case Menu::bf:
      solve(tsp, new BruteForce(), buff);
      break;
    case Menu::bnb:
      solve(tsp, new BnB(), buff);
      break;
    case Menu::dp:
      solve(tsp, new DP(), buff);
      break;
    }
  }

  return 0;
}