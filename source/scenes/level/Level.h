#ifndef __LEVEL_H_
#define __LEVEL_H_

#include "../Scene.h"

#include "../../cameras/StaticCamera.h"
#include "Entity.h"

#include "../../platform/Platform.h"

#include <list>
#include <memory>

class Game;

/**
 * Implementation of the Scene class for a standard playable level
 *
 * See Scene.h for details
 */
class Level : public Scene {
public:
    Level(std::shared_ptr<Image> background);

    void update(Game &game, unsigned int dt);
    void render();

    void addEntity(std::shared_ptr<Entity> e);
    void removeEntity(std::shared_ptr<Entity> e);

private:
    void updateInput();
    void updateBehaviours(unsigned int dt);
    void updatePhysics(unsigned int dt);
    void updateEntities();

private:
    std::shared_ptr<Input> input;
    std::shared_ptr<Renderer> renderer;

    std::shared_ptr<Image> background;
    
    std::list<std::shared_ptr<Entity>> born;
    std::list<std::shared_ptr<Entity>> active;
    std::list<std::shared_ptr<Entity>> dead;

    StaticCamera camera;
};

#endif // __LEVEL_H_
