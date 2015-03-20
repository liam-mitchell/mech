#include "Entity.h"

void Entity::updateBehaviours(Level &level, unsigned int dt)
{
    for (auto b = behaviours.rbegin(); b != behaviours.rend(); ++b) {
        if ((*b)->execute(level, dt)) {
            break;
        }
    }
}
