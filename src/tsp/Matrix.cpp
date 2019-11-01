#include "tsp/Matrix.hpp"
#include <sstream>
#include <math.h>
#include <iomanip>
#include <numeric>

Matrix::Matrix() {}
Matrix::Matrix(size_t size)
{
  this->size = size;
  m = std::vector<std::vector<int>>(size);
  for (size_t i = 0; i < size; i++)
  {
    m[i] = std::vector<int>(size);
  }
}

Matrix::~Matrix() {}

Matrix &Matrix::operator=(const Matrix &matrix)
{
  size = matrix.size;
  m = matrix.m;

  return *this;
}

std::vector<int> &Matrix::operator[](size_t i)
{
  return m[i];
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
