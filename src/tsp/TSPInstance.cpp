#include "tsp/TSPInstance.hpp"
#include <istream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <numeric>

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

int TSPInstance::routeDistance(std::vector<int> path)
{
    int distance = 0;
    for (size_t i = 0; i < path.size() - 1; i++)
    {
        distance += pathDistance(path.at(i), path.at(i + 1));
    }
    distance += pathDistance(path.at(path.size() - 1), path.at(0));

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