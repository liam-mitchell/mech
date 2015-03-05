#ifndef __GAME_H_
#define __GAME_H_

#include <list>
#include <memory>

class Scene;

class Game {
public:
    Game() = delete;
    Game(std::unique_ptr<Scene> scene);

    void playScene(std::unique_ptr<Scene> scene);
    void queueScene(std::unique_ptr<Scene> scene);
    void endScene();

    void run();

private:
    std::list<std::unique_ptr<Scene>> scenes;
};

#endif // __GAME_H_
