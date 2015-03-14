#ifndef __SDL_RENDERER_H_
#define __SDL_RENDERER_H_

#include "../PlatformRenderer.h"

#include <SDL/SDL.h>

/**
 * SDL implementation of Platform::Renderer
 *
 * See PlatformRenderer.h for details
 */
class SDLRenderer : public Platform::Renderer
{
public:
    SDLRenderer(unsigned int width, unsigned int height);

    SDLRenderer(const SDLRenderer &other) = delete;
    SDLRenderer &operator=(const SDLRenderer &other) = delete;

    /**
     * Image draw callbacks
     *
     * MUST be implemented for each new type of Platform::Image!
     */
    void draw(const SDLImage &image, const Camera &camera) const;

    ~SDLRenderer();
private:
    SDL_Window *window;
    SDL_Surface *surface;
};

#endif // __SDL_RENDERER_H_
