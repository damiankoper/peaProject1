#include "tsp/TSPInstance.hpp"
#include "tsp/Route.hpp"

TSPInstance::TSPInstance(std::istream &inputStream)
{
    inputStream >> size;

    if (size < 3)
    {
        throw "TSP instance is too small!";
    }

    matrix = new int *[size];
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
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
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void TSPInstance::print(std::ostream &outputStream)
{
    int maxChars = 0;
    std::stringstream ss;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            ss << matrix[i][j];
            maxChars = std::max((int)ss.str().length(), maxChars);
            ss.str("");
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            outputStream << std::setw(maxChars) << matrix[i][j] << " ";
        }
        outputStream << std::endl;
    }
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
    return size;
}