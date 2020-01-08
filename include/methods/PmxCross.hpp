#pragma once
#include "methods/Cross.hpp"
#include "tsp/Route.hpp"
class PmxCross : public Cross
{

public:
    PmxCross(int a, int b) : Cross(a, b) {}
    ~PmxCross();

    Route cross(Route mother, Route father);

    static std::string getName()
    {
        return "pmx";
    }
};