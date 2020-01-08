#include "methods/OxCross.hpp"
#include <algorithm>

OxCross::~OxCross()
{
}

Route OxCross::cross(Route mother, Route father)
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
  int current = 0;
  for (int currentChild = 0; currentChild < mother.v.size(); currentChild++)
  {
    for (; current < mother.v.size() && (currentChild < a || currentChild > b); current++)
    {
      if (std::find(mother.v.begin() + a, mother.v.begin() + b + 1, father.v[current]) - (mother.v.begin() + b + 1) == 0)
      {

        child.v[currentChild] = father.v[current];
        current++;
        break;
      }
    }
  }
  return child;
}