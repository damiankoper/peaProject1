#pragma once
#include <vector>
#include <iostream>
class Route {

public:
    Route();
    Route(int size);
    ~Route();

    void print(std::ostream &outputStream);

    std::vector<int> v;
};