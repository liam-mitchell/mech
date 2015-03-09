#include "Behaviour.h"

bool Behaviour::operator<(const Behaviour &other) const
{
    return priority < other.priority;
}
