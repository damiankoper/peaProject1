#include "methods/GA.hpp"
#include "methods/PmxCross.hpp"
#include "methods/OxCross.hpp"
#include "methods/Greedy.hpp"
#include "methods/ShiftMove.hpp"
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
    std::ofstream myfilePath;
    std::stringstream ss;
    ss << "GA_" << tsp.getSize() << "_" << population << "_" << Cross::getName() << "_" << pc << "_" << pm << ".csv";
    myfile.open(ss.str());
    myfilePath.open("path_" + ss.str());

    Greedy greedy = Greedy();
    Route greedyR = greedy.solve(tsp);
    Route best;

    // Populacja początkowa
    std::vector<Route> parents;
    parents.push_back(greedyR);
    for (int i = 1; i < population; i++)
    {
        parents.push_back(greedyR);
        std::shuffle(parents[i].v.begin(), parents[i].v.end(), std::random_device());
    }
    // Populacja początkowa

    for (int generation = 0; generation < generations; generation++)
    {
        //Selekcja
        std::sort(parents.begin(), parents.end(), [&tsp](Route r1, Route r2) {
            return tsp.routeDistance(r1) < tsp.routeDistance(r2);
        });
        parents = std::vector<Route>(parents.begin(), parents.begin() + population);
        //Selekcja

        int newDistance = tsp.routeDistance(parents[0]);
        if (best.v.size() == 0 || tsp.routeDistance(best) > newDistance)
        {
            best = parents[0];
            std::cout << "Nowe rozwiązanie: " << newDistance << " " << generation << std::endl;
            myfile << generation << "," << newDistance << "," << (newDistance - bestDistance) / (float)bestDistance * 100 << "%" << std::endl;
        }

        //Krzyżowanie i mutacja
        std::vector<Route> children;
        for (int i = 0; i < population; i++)
        {
            Route mother = parents[rand() % population];
            Route father = parents[rand() % population];

            float randPc = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            if (randPc <= pc)
            {
                int a = rand() % tsp.getSize();
                int b = rand() % tsp.getSize();
                Cross cross = Cross(a, b);
                children.push_back(cross.cross(mother, father));
                children.push_back(cross.cross(father, mother));
            }
            else
            {
                children.push_back(mother);
                children.push_back(father);
            }

            float randPm = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            if (randPm <= pm)
            {
                int a = rand() % tsp.getSize();
                int b = rand() % tsp.getSize();
                ShiftMove move = ShiftMove(a, b);
                move.make(children[children.size() - 1]);
                move.make(children[children.size() - 2]);
            }
        }
        //Krzyżowanie i mutacja

        parents = children;
    }

    best.print(myfilePath);
    myfile.close();
    myfilePath.close();
    return best;
}

template class GA<PmxCross>;
template class GA<OxCross>;