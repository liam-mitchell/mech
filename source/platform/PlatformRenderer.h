#ifndef __PLATFORM_RENDERER_H_
#define __PLATFORM_RENDERER_H_

#include <list>

#include "PlatformImage.h"

/**
 * Platform-agnostic rendering engine
 *
 * Uses the visitor pattern to allow the renderer to call platform-specific
 *  draw() functions. Implementations should only implement the draw() function
 *  for their specific implementation, and throw an exception if they are asked
 *  to draw() a different type of image.
 *
 */

class SDLImage;

namespace Platform
{
    class Renderer
    {
    public:
        Renderer(unsigned int width, unsigned int height);

        /**
         * Render a list of images, first culling those not visible to the camera
         *
         * Dispatches images to the correct draw image via calling the
         *  draw(Renderer) method on the image - each image must implement that
         *  method as Renderer.draw(*this), so as to call the correct draw()
         *  function on the renderer.
         */
        void render(const std::list<Image> &images, const Camera &camera) const;

        /**
         * Visitee callbacks
         */
        void draw(const SDLImage &image, const Camera &camera) const;

        /**
         * Implementation to be overridden by platform-specific interfaces
         *
         * Specific implementations should only override their own draw()
         *  method - all others should throw an exception.
         */
        class Implementation
        {
        public:
            virtual
            void draw(const SDLImage &image, const Camera &camera) const = 0;
        };

    private:
        std::unique_ptr<Implementation> impl;
    };
}

#endif // __PLATFORM_RENDERER_H_
