#pragma once
#include "methods/Move.hpp"
#include "tsp/Route.hpp"
class ReverseMove : public Move
{

public:
    ReverseMove(int a, int b) : Move(a,b) {}
    ~ReverseMove();

    void make(Route &route);
};