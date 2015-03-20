#include "Game.h"

#include "platform/Platform.h"
#include "scenes/Scene.h"

/**
 * Implements Game.h
 */
Game::Game(std::shared_ptr<Scene> scene)
{
    playScene(scene);
}

void Game::playScene(std::shared_ptr<Scene> scene)
{
    scenes.push_front(scene);
}

void Game::queueScene(std::shared_ptr<Scene> scene)
{
    scenes.push_back(scene);
}

void Game::endScene()
{
    scenes.pop_front();
}

void Game::run()
{
    std::shared_ptr<Timer> timer = Platform::createTimer();

    while (!scenes.empty()) {
        int dt = timer->tick();

        // Take a reference to the front of the scene queue since
        // scene->update() might put a new scene onto the queue
        // and we want to make sure it has a chance to update itself
        // before we try to render it, as well as finish rendering this one
        // before we pause it
        std::shared_ptr<Scene> scene = scenes.front();

        scene->update(*this, dt);
        scene->render();
    }
}

void Game::quit()
{
    scenes.clear();
}
