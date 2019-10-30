#pragma once
#include <iostream>

class Matrix
{

public:
    Matrix();
    Matrix(size_t size);
    ~Matrix();

    int *operator[](size_t i);
    Matrix &operator=(const Matrix &matrix);
    
    int getSize();

    void print(std::ostream &outputStream);

private:
    void createArray(size_t size);
    int **m = nullptr;
    int size = 0;
};