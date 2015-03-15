#ifndef __PLATFORM_IMAGE_H_
#define __PLATFORM_IMAGE_H_

#include <memory>

#include "../math/Vec2.h"

/**
 * Platform-agnostic image class
 */
class Camera;
class Renderer;
    
class Image
{
public:
    /**
     * Used for double dispatch to allow each platform's renderer access
     *  to image internals. The renderer implements a draw() function for
     *  each concrete type of image, and then given an abstract Image pointer,
     *  calls image->draw(*this), giving it a reference to an abstract Renderer.
     *  The image then calls renderer.draw(*this), giving the renderer a
     *  reference to a concrete type of image.
     *
     * Example call sequence for SDLImage:
     *  - renderer.render()            // Abstract renderer, abstract image
     *  -> image.draw(Renderer &)      // Concrete image has abstract renderer
     *  -> renderer.draw(SDLImage &)   // Concrete renderer has conrete image
     *
     * This allows each renderer access to the Image subclass's methods and
     *  members, allowing (for example) the SDLRenderer to access an SDLImage's
     *  SDL_Surface and SDL_Rect for drawing.
     *
     * The requirement implied by this setup is that each image must implement
     *  the draw(Renderer &) function in the same way - simply as
     *
     *  virtual void XXXImage::draw(const Renderer &renderer)
     *  {
     *      renderer.draw(*this);
     *  }
     *
     * See SDLImage for a sample implementation.
     */
    virtual void draw(const Renderer &renderer) = 0;

    /**
     * Used to update the internal structures' position and size.
     */
    virtual void setPixelPosition(int x, int y) = 0;
    virtual void setPixelSize(int w, int h) = 0;

public:
    /**
     * Position and size in world coordinates - ie. meters. These coordinates
     *  must be correct when the image is passed to the renderer for rendering,
     *  as they are used by the camera to cull the images and to position and
     *  scale them for rendering.
     */
    Vec2 position;
    Vec2 size;
};

#endif // __PLATFORM_IMAGE_H_
