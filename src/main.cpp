#include "tsp/TSPInstance.hpp"
#include "methods/BruteForce.hpp"
#include "methods/BnB.hpp"
#include "methods/DP.hpp"
#include "methods/TabuSearch.hpp"
#include "methods/SwapMove.hpp"
#include "methods/ShiftMove.hpp"
#include "methods/ReverseMove.hpp"
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
  tabuParams,
  tabu,
};

enum NHood
{
  swap = 0,
  shift,
  reverse
};

void printNHood(NHood n)
{
  switch (n)
  {
  case NHood::swap:
    std::cout << "Swap" << std::endl;
    break;
  case NHood::shift:
    std::cout << "Shift" << std::endl;
    break;
  case NHood::reverse:
    std::cout << "Reverse" << std::endl;
    break;
  }
}

void displayMenu()
{
  std::cout << "[0] Wyjdź" << std::endl;
  std::cout << "[1] Wczytaj" << std::endl;
  std::cout << "[2] Losowy" << std::endl;
  std::cout << "[3] BruteForce" << std::endl;
  std::cout << "[4] Branch and Bound" << std::endl;
  std::cout << "[5] Held-Karp" << std::endl;
  std::cout << "[6] Parametry TabuSearch" << std::endl;
  std::cout << "[7] TabuSearch" << std::endl;
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
  std::string filename = "";

  int tabuTime = 10000;
  int tabuSize = 10;
  int moveTime = 100;

  NHood nhood = swap;
  while (!exitt)
  {
    system("clear");
    std::cout << ("Plik: " + filename) << std::endl;

    if (tsp != nullptr && tsp->getSize() < 20)
      tsp->print(std::cout);
    std::cout << buff.str() << std::endl;
    std::cout << "TabuSearch - rozmiar listy: " << tabuSize
              << ", liczba iteracji: " << tabuTime
              << ", liczba iteracji dla ruchu(kadencja): " << moveTime << std::endl
              << "Sąsiedztwo: ";
    printNHood(nhood);
    std::cout << std::endl;
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
      filename = input;
      if (tsp != nullptr)
      {
        delete tsp;
        tsp = nullptr;
      }
      f.open("data/" + input + ".txt", std::ios::in);
      if (f.fail())
      {
        buff << "Błąd otwierania pliku!";
      }
      else
      {
        tsp = new TSPInstance(f);
        f.close();
      }
      break;
    case Menu::randomm:
      std::cout << "Podaj ilość miast: ";
      std::cin >> menuSelect;
      if (tsp != nullptr)
      {
        delete tsp;
        tsp = nullptr;
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
    case Menu::tabuParams:
      std::cout << "Podaj rozmiar listy tabu: ";
      std::cin >> tabuSize;
      std::cout << "Podaj ilość iteracji: ";
      std::cin >> tabuTime;
      std::cout << "Podaj iteracje kadencji: ";
      std::cin >> moveTime;
      std::cout << "Podaj sposób generowania sąsiedztwa(1-swap, 2-shift, 3-reverse): ";
      std::cin >> menuSelect;
      switch (menuSelect - 1)
      {
      case NHood::swap:
        nhood = swap;
        break;
      case NHood::shift:
        nhood = shift;
        break;
      case NHood::reverse:
        nhood = reverse;
        break;
      }
      break;
    case Menu::tabu:
      switch (nhood)
      {
      case NHood::swap:
        solve(tsp, new TabuSearch<SwapMove>(tabuTime, tabuSize, moveTime), buff);
        break;
      case NHood::shift:
        solve(tsp, new TabuSearch<ShiftMove>(tabuTime, tabuSize, moveTime), buff);
        break;
      case NHood::reverse:
        solve(tsp, new TabuSearch<ReverseMove>(tabuTime, tabuSize, moveTime), buff);
        break;
      }
      break;
    }
  }

  return 0;
}