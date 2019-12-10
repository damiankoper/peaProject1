#include "methods/Move.hpp"

Move::~Move()
{
}

bool Move::operator==(const Move &move)
{
    return (move.a == a && move.b == b) || (move.a == b && move.b == a);
}
