#include "Level.h"

#include <iostream>

/**
 * Implements Level.h
 */
Level::Level() : renderer(0, 0)
               , camera()
{

}

/**
 * Step the level forward by dt milliseconds
 */
void Level::update(unsigned int dt)
{
    std::cout << "Tick: " << dt << std::endl;
}

/**
 * Render all entities in the level after first culling ones that aren't
 *  visible to our current camera
 */
void Level::render()
{
    Platform::Image image;
    std::list<Platform::Image> images;

    images.push_back(std::move(image));

    renderer.render(images, camera);
}
