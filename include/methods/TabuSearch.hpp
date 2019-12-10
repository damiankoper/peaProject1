#pragma once
#include "methods/TSPInstanceSolver.hpp"

template <typename Move>
class TabuSearch : public TSPInstanceSolver
{

public:
    TabuSearch(int time = 1000000, int tabuSize = 10, int moveTime = 1000) : time(time), tabuSize(tabuSize), moveTime(moveTime) {}
    ~TabuSearch();

    struct TabuMove
    {
        Route route;
        Move move;
        int distance = 0;
        int timeLeft = 1000;
    };

    bool isInTabuList(Move move);
    Route solve(TSPInstance &tsp);

    void addToTabu(TabuMove tabuMove);
    void processTabu();
    void decreaseTabu();

    int time = 1000000;
    int tabuSize = 10;
    int moveTime = 10;

    std::vector<TabuMove> tabuList = std::vector<TabuMove>();
};