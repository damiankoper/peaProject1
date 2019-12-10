#include "methods/TabuSearch.hpp"
#include "methods/SwapMove.hpp"
#include "methods/ShiftMove.hpp"
#include "methods/ReverseMove.hpp"
#include "methods/Greedy.hpp"
#include <iostream>
template <typename Move>
TabuSearch<Move>::~TabuSearch()
{
}

template <typename Move>
Route TabuSearch<Move>::solve(TSPInstance &tsp)
{
    Greedy greedy = Greedy();
    Route best = greedy.solve(tsp);
    int bestRouteDistance = tsp.routeDistance(best);
    Route localBestRoute = best;
    std::cout << "Zachłanny: " << bestRouteDistance << std::endl;

    for (size_t i = 0; i < time; i++)
    {
        std::vector<TabuSearch::TabuMove> generated;
        for (size_t j = 0; j < tsp.getSize(); j++)
        {
            Move move = Move(0, 0);
            do
            {
                int a = rand() % tsp.getSize();
                int b = rand() % tsp.getSize();
                move = Move(a, b);
            } while (isInTabuList(move));

            Route movedRoute = localBestRoute;
            move.make(movedRoute);
            generated.push_back({movedRoute, move, tsp.routeDistance(movedRoute)});
        }

        TabuSearch::TabuMove localBest = generated[0];
        int localBestRouteDistance = tsp.routeDistance(localBest.route);
        for (size_t i = 1; i < generated.size(); i++)
        {
            if (generated[i].distance < localBest.distance)
            {
                localBest = generated[i];
            }
        }
        localBestRoute = localBest.route;

        if (localBest.distance < bestRouteDistance)
        {
            bestRouteDistance = localBest.distance;
            std::cout << "Nowe rozwiązanie: " << bestRouteDistance << std::endl;
            addToTabu(localBest);
            best = localBest.route;
        }
        processTabu();
        decreaseTabu();
    }

    return best;
}

template <typename Move>
bool TabuSearch<Move>::isInTabuList(Move move)
{
    for (auto &&tabuMove : tabuList)
    {
        if (move == tabuMove.move)
            return true;
    }
    return false;
}

template <typename Move>
void TabuSearch<Move>::addToTabu(TabuSearch::TabuMove tabuMove)
{
    int minTimeLeft = INT32_MAX;
    int minTimeLeftI = 0;
    if (tabuList.size() == tabuSize)
    {
        for (int i = 0; i < tabuList.size(); i++)
        {
            if (tabuList[i].timeLeft < minTimeLeft)
            {
                minTimeLeft = tabuList[i].timeLeft;
                minTimeLeftI = i;
            }
        }
        tabuList[minTimeLeftI].timeLeft = 0;
    }
    tabuList.push_back(tabuMove);
}

template <typename Move>
void TabuSearch<Move>::processTabu()
{
    std::vector<int> toRemove;
    for (int i = 0; i < tabuList.size(); i++)
    {
        if (tabuList[i].timeLeft == 0)
        {
            toRemove.push_back(i);
        }
    }
    for (int i = 0; i < toRemove.size(); i++)
    {
        tabuList.erase(tabuList.begin() + toRemove[i]);
        std::cout << "Usunięto z listy tabu, rozmiar: " << tabuList.size() << std::endl;
    }
}

template <typename Move>
void TabuSearch<Move>::decreaseTabu()
{
    for (int i = 0; i < tabuList.size(); i++)
    {
        tabuList[i].timeLeft--;
    }
}

template class TabuSearch<SwapMove>;
template class TabuSearch<ShiftMove>;
template class TabuSearch<ReverseMove>;