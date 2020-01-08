#pragma once
#include "tsp/Route.hpp"
class Cross
{

public:
    virtual Route cross(Route mother, Route father) = 0;

protected:
    Cross(int b, int a) : a(a), b(b) {}
    virtual ~Cross();

    int a;
    int b;
};