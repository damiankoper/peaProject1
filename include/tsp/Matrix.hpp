#pragma once
#include <iostream>
#include <vector>
class Matrix
{

public:
    Matrix();
    Matrix(size_t size);
    ~Matrix();

    std::vector<int> &operator[](size_t i);
    Matrix &operator=(const Matrix &matrix);

    int getSize();

    void print(std::ostream &outputStream);

    static Matrix createRandom(int size, int min, int max);

private:
    void createArray(size_t size);
    std::vector<std::vector<int>> m;
    int size = 0;
};