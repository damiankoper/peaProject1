#include "tsp/Route.hpp"
#include <numeric>

Route::Route()
{
    v = std::vector<int>();
}

Route::Route(int size)
{
    v = std::vector<int>(size);
    std::iota(v.begin(), v.end(), 0);
}

Route::~Route()
{
}

void Route::print(std::ostream &outputStream)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i != 0)
            outputStream << " -> ";
        outputStream << v[i];
        
        if (i == v.size() - 1)
            outputStream << " -> " << v[0];
    }
    outputStream << std::endl;
}