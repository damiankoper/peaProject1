#include "methods/SA.hpp"
#include "methods/SwapMove.hpp"
#include "methods/ShiftMove.hpp"
#include "methods/ReverseMove.hpp"
#include "methods/Greedy.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
template <typename Move>
SA<Move>::~SA()
{
}

template <typename Move>
Route SA<Move>::solve(TSPInstance &tsp)
{
    std::ofstream myfile;
    std::stringstream ss;
    ss << "SA_" << tsp.getSize() << "_" << T << "_" << Move::getName() << ".csv";
    myfile.open(ss.str());

    Greedy greedy = Greedy();
    Route best = greedy.solve(tsp);
    Route localBestRoute = best;
    int j = 0;
    while (T > Tk)
    {
        for (size_t i = 0; i < tsp.getSize(); i++)
        {
            int ap = rand() % tsp.getSize();
            int bp = rand() % tsp.getSize();
            Move move = Move(ap, bp);

            Route movedRoute = localBestRoute;
            move.make(movedRoute);

            int distance = tsp.routeDistance(movedRoute);
            int localBestDistance = tsp.routeDistance(localBestRoute);
            if (distance < tsp.routeDistance(localBestRoute) || p < exp((localBestDistance - distance) / T))
            {
                localBestRoute = movedRoute;
            }

            if (distance < tsp.routeDistance(best))
            {
                best = movedRoute;
                std::cout << "Nowe rozwiązanie: " << distance << " " << T << std::endl;
                myfile << j << "," << distance << std::endl;
            }
            j++;
        }
        T = T * a;
    }
    best.print(myfile);
    myfile.close();
    return best;
}

template class SA<SwapMove>;
template class SA<ShiftMove>;
template class SA<ReverseMove>;