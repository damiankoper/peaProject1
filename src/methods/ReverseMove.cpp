#include "methods/ReverseMove.hpp"
#include <algorithm>
ReverseMove::~ReverseMove()
{
}

void ReverseMove::make(Route &route)
{
  std::reverse(route.v.begin() + a, route.v.begin() + b);
}