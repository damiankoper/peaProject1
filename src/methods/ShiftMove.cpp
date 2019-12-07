#include "methods/ShiftMove.hpp"

ShiftMove::~ShiftMove()
{
}

void ShiftMove::make(Route &route)
{
  int tmp = route.v.at(a);
  route.v.erase(route.v.begin()+a);
  route.v.insert(route.v.begin()+b, tmp);
}