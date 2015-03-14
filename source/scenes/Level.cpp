#include "Level.h"

#include "../platform/Platform.h"

#include <iostream>

/**
 * Implements Level.h
 */
Level::Level(std::shared_ptr<Image> background)
    : input(Platform::createInput())
    , renderer(Platform::createRenderer(1020, 780))
    , camera()
{
    
}

/**
 * Step the level forward by dt milliseconds
 */
void Level::update(unsigned int dt)
{
    updateInput();
    updateBehaviours(dt);
    updatePhysics(dt);
    updateEntities();
}

/**
 * Render all entities in the level after first culling ones that aren't
 *  visible to our current camera
 */
void Level::render()
{
    std::list<std::shared_ptr<Image>> images;

    for (auto &e: active) {
        images.splice(images.end(), e->getImages());
    }

    renderer->render(images, camera);
}


void Level::addEntity(std::shared_ptr<Entity> e)
{
    born.push_back(e);
}

void Level::removeEntity(std::shared_ptr<Entity> e)
{
    active.remove(e);
    dead.push_back(e);
}

void Level::updateEntities()
{
    for (auto &e: born) {
        e->create();
        active.push_back(e);
    }

    born.clear();

    for (auto &e: dead) {
        e->destroy();
    }

    dead.clear();
}

void Level::updateBehaviours(unsigned int dt)
{
    for (auto &e: active) {
        e->updateBehaviours(*this, dt);
    }
}

void Level::updatePhysics(unsigned int dt)
{
    // TODO
}

void Level::updateInput()
{
    input->update();
}
