#include "Level.h"

#include "../platform/Platform.h"

#include <iostream>

/**
 * Implements Level.h
 */
Level::Level(std::shared_ptr<Image> background)
    : input(Platform::createInput())
    , renderer(Platform::createRenderer(1020, 780))
    , camera(10.2, 7.8)
{
    testimage = Platform::createImage("/home/liam/src/mech/assets/test-image.png");
    testimage->position.x = 1;
    testimage->position.y = 1;
    testimage->size.x = 1;
    testimage->size.y = 1;
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

    images.push_back(testimage);

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
