#pragma once
#include "methods/Cross.hpp"
#include "tsp/Route.hpp"
class OxCross : public Cross
{

public:
    OxCross(int a, int b) : Cross(a, b) {}
    ~OxCross();

    Route cross(Route mother, Route father);

    static std::string getName()
    {
        return "ox";
    }
};