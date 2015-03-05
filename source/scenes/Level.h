#ifndef __LEVEL_H_
#define __LEVEL_H_

#include "Scene.h"

#include "../Camera.h"

#include "../platform/Platform.h"

/**
 * Implementation of the Scene class for a standard playable leve
 *
 * See Scene.h for details
 */
class Level : public Scene {
public:
    Level();

    void update(unsigned int dt);
    void render();

private:
    Platform::Renderer renderer;

    Camera camera;
};

#endif // __LEVEL_H_
