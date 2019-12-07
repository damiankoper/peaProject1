#include "methods/SwapMove.hpp"

SwapMove::~SwapMove()
{
}

void SwapMove::make(Route &route)
{
  std::swap(route.v[a], route.v[b]);
}