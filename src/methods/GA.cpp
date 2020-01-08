#include "methods/GA.hpp"
#include "methods/PmxCross.hpp"
#include "methods/OxCross.hpp"
#include "methods/Greedy.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
template <typename Cross>
GA<Cross>::~GA()
{
}

template <typename Cross>
Route GA<Cross>::solve(TSPInstance &tsp)
{
    std::ofstream myfile;
    std::stringstream ss;
    ss << "GA_" << tsp.getSize() << "_" << population << "_" << Cross::getName() << ".csv";
    myfile.open(ss.str());

    Greedy greedy = Greedy();
    Route best = greedy.solve(tsp);

    // Populacja początkowa
    std::vector<Route> parents = {best};
    for (int i = 1; i < population; i++)
    {
        parents.push_back(best);
        std::shuffle(parents[i].v.begin(), parents[i].v.end(), std::random_device());
    }
    // Populacja początkowa

    
    best.print(myfile);
    myfile.close();
    return best;
}

template class GA<PmxCross>;
template class GA<OxCross>;