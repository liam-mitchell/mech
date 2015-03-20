#ifndef __GAME_H_
#define __GAME_H_

#include <list>
#include <memory>

class Scene;

class Game {
public:
    Game() = delete;
    Game(std::shared_ptr<Scene> scene);

    void playScene(std::shared_ptr<Scene> scene);
    void queueScene(std::shared_ptr<Scene> scene);
    void endScene();

    void run();
    void quit();

private:
    std::list<std::shared_ptr<Scene>> scenes;
};

#endif // __GAME_H_
