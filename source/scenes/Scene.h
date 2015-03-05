#ifndef __SCENE_H_
#define __SCENE_H_

/**
 * Scene class
 *
 * The Game class maintains a list of scenes, running the front scene on its
 *  list each time. It calls the scene's update() function with the current
 *  timestep, then calls the scene's render() function.
 *
 * This interface is designed to be overridden by different types of levels
 *  or scenes. The standard 'level' implementation can be found in the Level
 *  class (surprisingly enough), but this class should be useful for menu
 *  screens, pause screens, cutscenes... anything you can really think of.
 */
class Scene {
public:
    virtual void update(unsigned int dt) = 0;
    virtual void render() = 0;
};

#endif // __SCENE_H_
