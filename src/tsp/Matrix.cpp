#include "tsp/Matrix.hpp"
#include <sstream>
#include <math.h>
#include <iomanip>
#include <numeric>

Matrix::Matrix() {}
Matrix::Matrix(size_t size)
{
  createArray(size);
}

Matrix::~Matrix()
{
  for (size_t i = 0; i < size; i++)
  {
    delete[] m[i];
  }
  delete[] m;
  
  m = nullptr;
}
Matrix &Matrix::operator=(const Matrix &matrix)
{
  createArray(matrix.size);  
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j< size; j++)
    {
      m[i][j] = matrix.m[i][j];
    }
  }
  return *this;
}

int *Matrix::operator[](size_t i)
{
  return m[i];
}

void Matrix::createArray(size_t size)
{
  if (m != nullptr)
  {
    this->~Matrix();
  }

  this->size = size;
  m = new int *[size];

  for (size_t i = 0; i < size; i++)
  {
    m[i] = new int[size];
  }
}

int Matrix::getSize()
{
  return size;
}

void Matrix::print(std::ostream &outputStream)
{
  int maxChars = 0;
  std::stringstream ss;
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      ss << m[i][j];
      maxChars = std::max((int)ss.str().length(), maxChars);
      ss.str("");
    }
  }

  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      outputStream << std::setw(maxChars) << m[i][j] << " ";
    }
    outputStream << std::endl;
  }
}
