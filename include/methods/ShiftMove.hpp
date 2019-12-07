#pragma once
#include "methods/Move.hpp"
#include "tsp/Route.hpp"
class ShiftMove : public Move
{

public:
    ShiftMove(int a, int b) : Move(a,b) {}
    ~ShiftMove();

    void make(Route &route);
};