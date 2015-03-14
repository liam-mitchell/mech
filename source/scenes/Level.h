#ifndef __LEVEL_H_
#define __LEVEL_H_

#include "Scene.h"

#include "../Camera.h"
#include "Entity.h"

#include "../platform/Platform.h"

#include <list>
#include <memory>

/**
 * Implementation of the Scene class for a standard playable level
 *
 * See Scene.h for details
 */
class Level : public Scene {
public:
    Level(std::shared_ptr<Platform::Image> background);

    void update(unsigned int dt);
    void render();

    void addEntity(std::shared_ptr<Entity> e);
    void removeEntity(std::shared_ptr<Entity> e);

private:
    void updateInput();
    void updateBehaviours(unsigned int dt);
    void updatePhysics(unsigned int dt);
    void updateEntities();

private:
    std::shared_ptr<Platform::Input> input;
    std::shared_ptr<Platform::Renderer> renderer;

    std::shared_ptr<Platform::Image> background;
    
    std::list<std::shared_ptr<Entity>> born;
    std::list<std::shared_ptr<Entity>> active;
    std::list<std::shared_ptr<Entity>> dead;

    Camera camera;
};

#endif // __LEVEL_H_
