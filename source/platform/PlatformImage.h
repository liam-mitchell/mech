#ifndef __PLATFORM_IMAGE_H_
#define __PLATFORM_IMAGE_H_

#include <memory>

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
        Image();
        void draw(const Renderer &renderer, const Camera &camera) const;

        class Implementation
        {
        public:
            virtual
            void draw(const Renderer &renderer, const Camera &camera) const = 0;
        };

    private:
        std::unique_ptr<Implementation> impl;
    };
}

#endif // __PLATFORM_IMAGE_H_
