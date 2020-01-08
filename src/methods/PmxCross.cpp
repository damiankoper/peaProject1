#include "methods/PmxCross.hpp"
#include <algorithm>

PmxCross::~PmxCross()
{
}

Route PmxCross::cross(Route mother, Route father)
{
  if (b < a)
  {
    std::swap(a, b);
  }

  Route child(mother.v.size());
  for (auto &i : child.v)
  {
    i = -1;
  }
  std::copy(mother.v.begin() + a, mother.v.begin() + b + 1, child.v.begin() + a);
  int notCopied;
  int notCopiedIndex;

  int fatherPos;
  int path;
  for (int current = a; current <= b; current++)
  {
    if (std::find(mother.v.begin() + a, mother.v.begin() + b + 1, father.v[current]) - (mother.v.begin() + b + 1) == 0)
    {
      notCopied = father.v[current];
      path = mother.v[current];

      do
      {
        fatherPos = std::find(father.v.begin(), father.v.end(), path) - father.v.begin();
        path = mother.v[fatherPos];
      } while (fatherPos >= a && fatherPos <= b);
      child.v[fatherPos] = notCopied;
    }
  }

  for (int i = 0; i < child.v.size(); i++)
  {
    if (child.v[i] == -1)
    {
      child.v[i] = father.v[i];
    }
  }

  return child;
}