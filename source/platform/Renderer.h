#ifndef __PLATFORM_RENDERER_H_
#define __PLATFORM_RENDERER_H_

#include <list>

#include "Image.h"

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

class Renderer
{
protected:
    static const std::string WINDOW_TITLE;

public:

    /**
     * Render a list of images, first culling those not visible to the camera
     *
     * Dispatches images to the correct draw image via calling the
     *  draw(Renderer) method on the image - each image must implement that
     *  method as Renderer.draw(*this), so as to call the correct draw()
     *  function on the renderer.
     */
    void render(std::list<std::shared_ptr<Image>> &images,
                const Camera &camera) const;

    /**
     * Visitee callbacks
     */
    virtual void draw(const SDLImage &image) const = 0;
};

#endif // __PLATFORM_RENDERER_H_
