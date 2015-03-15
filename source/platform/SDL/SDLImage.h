#ifndef __SDL_IMAGE_H_
#define __SDL_IMAGE_H_

#include "../Platform.h"

#include <SDL/SDL.h>
#include <SDL/SDL_rect.h>

/**
 * SDL implementation of Image (see platform/Image.h)
 */
class SDLImage : public Image
{
public:
    /**
     * Construct an image from a path
     */
    SDLImage(const std::string &path);

    /**
     * Double dispatch callback - calls renderer.draw(*this) to dispatch
     *  to the correct Renderer::draw() function
     */
    virtual void draw(const Renderer &renderer);

    /**
     * Update the internal surface and rectangle to a specified position and
     *  size
     */
    virtual void setPixelPosition(int x, int y);
    virtual void setPixelSize(int w, int h);

    virtual ~SDLImage();

    /**
     * Data for the renderer, which knows we're an SDLImage
     */
    SDL_Surface *getSurface();
    SDL_Rect *getRect();

private:
    SDL_Surface *surface;
    SDL_Rect rect;
};

#endif // __SDL_IMAGE_H_
