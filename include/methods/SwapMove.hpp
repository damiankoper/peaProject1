#pragma once
#include "methods/Move.hpp"
#include "tsp/Route.hpp"
class SwapMove : public Move
{

public:
    SwapMove(int a, int b) : Move(a,b) {}
    ~SwapMove();

    void make(Route &route);
};