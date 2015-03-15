#ifndef __PLATFORM_IMAGE_H_
#define __PLATFORM_IMAGE_H_

#include <memory>

#include "../math/Vec2.h"

/**
 * Platform-agnostic image class
 *
 * Implements the visitee side of the visitor pattern for Renderer.
 *  See PlatformRenderer.h for details.
 */

class Camera;
class Renderer;
    
class Image
{
public:
    virtual void draw(const Renderer &renderer) = 0;

    virtual void setPixelPosition(int x, int y) = 0;
    virtual void setPixelSize(int w, int h) = 0;

public:
    Vec2 position;
    Vec2 size;
};

#endif // __PLATFORM_IMAGE_H_
