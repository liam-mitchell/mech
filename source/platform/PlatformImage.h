#ifndef __PLATFORM_IMAGE_H_
#define __PLATFORM_IMAGE_H_

#include <memory>

#include "../math/Vec2.h"

/**
 * Platform-agnostic image class
 *
 * Implements the visitee side of the visitor pattern for Platform::Renderer.
 *  See PlatformRenderer.h for details.
 */

class Camera;

namespace Platform
{
    class Renderer;
    
    class Image
    {
    public:
        virtual void draw(const Renderer &renderer, const Camera &camera)
            const = 0;
        virtual void resize(const Camera &camera) = 0;

    public:
        Vec2 position;
        Vec2 size;
    };
}

#endif // __PLATFORM_IMAGE_H_
