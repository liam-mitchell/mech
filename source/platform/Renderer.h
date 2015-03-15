#ifndef __PLATFORM_RENDERER_H_
#define __PLATFORM_RENDERER_H_

#include <list>

#include "Image.h"

/**
 * Platform-agnostic rendering engine
 *
 * 
 */
class SDLImage;

class Renderer
{
protected:
    static const std::string WINDOW_TITLE;

public:
    Renderer(unsigned int width, unsigned int height);
    /**
     * Render a list of images, using a camera to cull images that aren't
     *  visible and position and scale images appropriately.
     *
     * Utilizes double dispatch in order to allow platform-specific subclasses
     *  access to the specific methods and members within the platform-specific
     *  Image class. After culling and positioning images, it then loops over
     *  them, calling image->draw(*this). The images then call back the
     *  appropriate platform-specific draw(XXXImage &) function.
     *
     * Example call sequence for SDLImage:
     *  - renderer.render()            // Abstract renderer, abstract image
     *  -> image.draw(Renderer &)      // Concrete image has abstract renderer
     *  -> renderer.draw(SDLImage &)   // Concrete renderer has conrete image
     *
     *
     * This allows each renderer access to the Image subclass's methods and
     *  members, allowing (for example) the SDLRenderer to access an SDLImage's
     *  SDL_Surface and SDL_Rect for drawing.
     */
    void render(std::list<std::shared_ptr<Image>> &images,
                const Camera &camera);

    /**
     * Double-dispatch callbacks
     *
     * Standard implementation for all types of image other than the one which
     *  matches the type of the renderer (ie. SDLImage for SDLRenderer) is to
     *  simply throw an exception, since the Platform::createXXX() functions
     *  should produce the same types for both unless something is terribly
     *  wrong.
     */
    virtual void draw(SDLImage &image) const = 0;

protected:
    /**
     * Swap the front and back buffers
     *
     * Called by render() after drawing all images.
     */
    virtual void flip() = 0;

protected:
    unsigned int width;
    unsigned int height;
};

#endif // __PLATFORM_RENDERER_H_
