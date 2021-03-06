#ifndef __ENTITY_H_
#define __ENTITY_H_

#include "Behaviour.h"

#include "../../platform/Platform.h"

#include <list>
#include <memory>
#include <set>

class Level;

class Entity {
public:
    virtual void create() = 0;
    virtual void destroy() = 0;

    virtual std::list<std::shared_ptr<Image>> getImages() = 0;

    virtual void updateBehaviours(Level &level, unsigned int dt);
protected:
    std::set<std::shared_ptr<Behaviour>, BehaviourCompare> behaviours;
};

#endif // __ENTITY_H_
