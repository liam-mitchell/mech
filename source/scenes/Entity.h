#ifndef __ENTITY_H_
#define __ENTITY_H_

#include "Behaviour.h"
#include "RenderData.h"

#include <list>
#include <memory>
#include <set>

class Level;

class Entity {
public:
    virtual void create() = 0;
    virtual void destroy() = 0;

    virtual std::list<Platform::Image> getImages() = 0;

    virtual void updateBehaviours(Level &level, unsigned int dt);
private:
    std::set<std::unique_ptr<Behaviour>, BehaviourCompare> behaviours;
};

#endif // __ENTITY_H_
