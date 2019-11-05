#include "tester/Tester.hpp"
#include <chrono>
#include <functional>
#include <iostream>
#include <fstream>

Tester::Tester()
{
}

Tester *Tester::setTestedFn(std::function<void(TestEnv &testEnv)> cb)
{
    testedFn = cb;
    return this;
}

Tester *Tester::beforeEach(std::function<void(TestEnv &testEnv)> cb)
{
    beforeEachFn = cb;
    return this;
}

Tester *Tester::afterEach(std::function<void(TestEnv &testEnv)> cb)
{
    afterEachFn = cb;
    return this;
}

Tester *Tester::afterSameDataSet(std::function<void(TestEnv &testEnv)> cb)
{
    afterSameDataSetFn = cb;
    return this;
}

Tester *Tester::setSameDataRepeats(int i)
{
    sameDataRepeats = i;
    return this;
}

Tester *Tester::setOverallRepeats(int i)
{
    overallRepeats = i;
    return this;
}

double Tester::runSingle()
{
    beforeEachFn(testEnv);

    auto start = std::chrono::high_resolution_clock::now();
    if (testedFn != NULL)
    {
        testedFn(testEnv);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    afterEachFn(testEnv);
    return elapsed.count();
}

double Tester::runSingleData()
{
    double sum = 0;
    for (int i = 0; i < sameDataRepeats; i++)
    {
        sum += runSingle();
    }

    afterSameDataSetFn(testEnv);

    double avg = sum / sameDataRepeats;
    std::cout << log << avg << std::endl;
    return avg;
}

std::vector<Tester::TestResult> Tester::runAll()
{
    std::vector<Tester::TestResult> vec = std::vector<Tester::TestResult>();
    for (int i = 0; i < overallRepeats; i++)
    {
        Tester::TestResult result = TestResult(testEnv);
        result.time = runSingleData();
        vec.push_back(result);
    }
    lastResults = vec;
    return vec;
}

Tester *Tester::writeLastToFile(std::string name)
{
    std::ofstream myfile;
    myfile.open(name);
    myfile << "startElements, time" << std::endl;
    for (auto testResult : lastResults)
    {
        //myfile << testResult.startElements << ",";
        myfile << testResult.activeElements << ",";
        myfile << testResult.time;
        myfile << std::endl;
    }

    myfile.close();
    return this;
}
