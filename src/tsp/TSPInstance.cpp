#include "tsp/TSPInstance.hpp"
#include "tsp/Route.hpp"

TSPInstance::TSPInstance(std::istream &inputStream)
{
    size_t size;
    inputStream >> size;

    if (size < 3)
    {
        throw "TSP instance is too small!";
    }

    matrix = Matrix(size);
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            inputStream >> matrix[i][j];
            if (i == j)
                matrix[i][j] = -1;
        }
    }
}

TSPInstance::~TSPInstance()
{
}

void TSPInstance::print(std::ostream &outputStream)
{
    matrix.print(outputStream);
}

int TSPInstance::routeDistance(Route &route)
{
    int distance = 0;
    for (size_t i = 0; i < route.v.size() - 1; i++)
    {
        distance += pathDistance(route.v.at(i), route.v.at(i + 1));
    }
    distance += pathDistance(route.v.at(route.v.size() - 1), route.v.at(0));

    return distance;
}

int TSPInstance::pathDistance(int from, int to)
{
    return matrix[from][to];
}

int TSPInstance::getSize()
{
    return matrix.getSize();
}