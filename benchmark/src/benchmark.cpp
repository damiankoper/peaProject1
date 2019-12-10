#include "tester/Tester.hpp"
#include "tsp/TSPInstance.hpp"
#include "methods/BruteForce.hpp"
#include "methods/BnB.hpp"
#include "methods/DP.hpp"
#include "methods/TabuSearch.hpp"
#include "methods/SwapMove.hpp"
#include "methods/ShiftMove.hpp"
#include "methods/ReverseMove.hpp"
#include "methods/SA.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
void test(TSPInstanceSolver *solver, std::string name, int n = 8)
{
  TSPInstance *tsp = nullptr;
  Tester tester = Tester();
  tester.log = name + ": ";
  tester.testEnv.startElements = 4;
  tester.testEnv.activeElements = 4;
  tester.setOverallRepeats(n - 3)
      ->setSameDataRepeats(100)
      ->beforeEach([&tsp](Tester::TestEnv &testEnv) {
        if (tsp != nullptr)
          delete tsp;
        tsp = new TSPInstance(testEnv.activeElements);
      })
      ->setTestedFn([&solver, &tsp](Tester::TestEnv &testEnv) {
        solver->solve(*tsp);
      })
      ->afterSameDataSet([](Tester::TestEnv &testEnv) {
        testEnv.activeElements++;
      });
  tester.runAll();
  tester.writeLastToFile("benchmark/" + name + ".csv");

  if (tsp != nullptr)
    delete tsp;
}

void solve(TSPInstance *tsp, TSPInstanceSolver *solver)
{
  Route r = solver->solve(*tsp);
}

int main(int argc, char **argv)
{
  /*  test(new BruteForce(), "BruteForce", 9);
  test(new BnB(), "BnB", 15);
  test(new DP(), "DP", 17); */
  std::ifstream f;
  TSPInstance *tsp = nullptr;

  int tabuTime = 1000000;
  int tabuSize = 12;
  int moveTime = 50;

  /*   f.open("data/ftv47.txt", std::ios::in);
  tsp = new TSPInstance(f);
  solve(tsp, new TabuSearch<SwapMove>(tabuTime, tabuSize, moveTime));
  solve(tsp, new TabuSearch<ShiftMove>(tabuTime, tabuSize, moveTime));
  solve(tsp, new TabuSearch<ReverseMove>(tabuTime, tabuSize, moveTime));
  f.close();

  tabuTime = 1000000;
  tabuSize = 18;
  f.open("data/ftv170.txt", std::ios::in);
  tsp = new TSPInstance(f);
  solve(tsp, new TabuSearch<SwapMove>(tabuTime, tabuSize, moveTime));
  solve(tsp, new TabuSearch<ShiftMove>(tabuTime, tabuSize, moveTime));
  solve(tsp, new TabuSearch<ReverseMove>(tabuTime, tabuSize, moveTime));
  f.close();

  tabuTime = 1000000;
  tabuSize = 22;
  f.open("data/rbg403.txt", std::ios::in);
  tsp = new TSPInstance(f);
  solve(tsp, new TabuSearch<SwapMove>(tabuTime, tabuSize, moveTime));
  solve(tsp, new TabuSearch<ShiftMove>(tabuTime, tabuSize, moveTime));
  solve(tsp, new TabuSearch<ReverseMove>(tabuTime, tabuSize, moveTime));
  f.close(); */

  int saT = 1000;
  float saTk = 0.01;
  float saa = 0.9999;

  f.open("data/ftv47.txt", std::ios::in);
  tsp = new TSPInstance(f);
  solve(tsp, new SA<SwapMove>(saT, saTk, saa, 0.8));
  solve(tsp, new SA<ShiftMove>(saT, saTk, saa, 0.8));
  solve(tsp, new SA<ReverseMove>(saT, saTk, saa, 0.8));
  f.close();

  f.open("data/ftv170.txt", std::ios::in);
  tsp = new TSPInstance(f);
  solve(tsp, new SA<SwapMove>(saT, saTk, saa, 0.8));
  solve(tsp, new SA<ShiftMove>(saT, saTk, saa, 0.8));
  solve(tsp, new SA<ReverseMove>(saT, saTk, saa, 0.8));
  f.close();

  f.open("data/rbg403.txt", std::ios::in);
  tsp = new TSPInstance(f);
  solve(tsp, new SA<SwapMove>(saT, saTk, saa, 0.8));
  solve(tsp, new SA<ShiftMove>(saT, saTk, saa, 0.8));
  solve(tsp, new SA<ReverseMove>(saT, saTk, saa, 0.8));
  f.close();

  return 0;
}