#include "tester/Tester.hpp"
#include "tsp/TSPInstance.hpp"
#include "methods/BruteForce.hpp"
#include "methods/BnB.hpp"
#include "methods/DP.hpp"

void test(TSPInstanceSolver *solver, std::string name, int n = 8)
{
  TSPInstance *tsp = nullptr;
  Tester tester = Tester();
  tester.log = name + ": ";
  tester.testEnv.startElements = 4;
  tester.testEnv.activeElements = 4;
  tester.setOverallRepeats(n-3)
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

int main(int argc, char **argv)
{
  test(new BruteForce(), "BruteForce", 9);
  test(new BnB(), "BnB", 15);
  test(new DP(), "DP", 15);
  return 0;
}