#pragma once
#include "tsp/Route.hpp"
class Move
{

public:
    virtual void make(Route &route) = 0;

protected:
    Move(int b, int a) : a(a), b(b) {}
    virtual ~Move();

    int a;
    int b;
};