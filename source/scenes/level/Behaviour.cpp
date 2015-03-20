#include "Behaviour.h"

Behaviour::Behaviour(int priority)
    : priority(priority)
{}

bool Behaviour::operator<(const Behaviour &other) const
{
    return priority < other.priority;
}
