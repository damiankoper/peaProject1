#include "methods/BnBPartialSolution.hpp"

BnBPartialSolution::BnBPartialSolution()
{
}

BnBPartialSolution::~BnBPartialSolution()
{
}

int BnBPartialSolution::minRow(Matrix matrin, int n)
{
  int min = INT32_MAX;
  std::vector<int> row = matrix[n];
  for (size_t i = 0; i < row.size(); i++)
  {
    if (row[i] < min && row[i] != -1)
    {
      min = row[i];
    }
  }
  return min == INT32_MAX ? 0 : min;
}

int BnBPartialSolution::minCol(Matrix matrin, int n)
{
  int min = INT32_MAX;
  for (size_t i = 0; i < matrix.getSize(); i++)
  {
    if (matrix[i][n] < min && matrix[i][n] != -1)
    {
      min = matrix[i][n];
    }
  }
  return min == INT32_MAX ? 0 : min;
}

int BnBPartialSolution::reduce()
{
  int reduction = 0;
  for (size_t i = 0; i < matrix.getSize(); i++)
  {
    int min = minRow(matrix, i);
    if (min != 0)
    {
      reduction += min;
      for (size_t j = 0; j < matrix.getSize(); j++)
      {
        if (matrix[i][j] != -1)
          matrix[i][j] -= min;
      }
    }
  }

  for (size_t i = 0; i < matrix.getSize(); i++)
  {
    int min = minCol(matrix, i);
    if (min != 0)
    {
      reduction += min;
      for (size_t j = 0; j < matrix.getSize(); j++)
      {
        if (matrix[j][i] != -1)
          matrix[j][i] -= min;
      }
    }
  }
  return reduction;
}