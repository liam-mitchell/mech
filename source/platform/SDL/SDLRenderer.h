#ifndef __SDL_RENDERER_H_
#define __SDL_RENDERER_H_

#include "../Renderer.h"

#include <SDL/SDL.h>

/**
 * SDL implementation of Renderer (see platform/Renderer.h)
 */
class SDLRenderer : public Renderer
{
public:
    SDLRenderer(unsigned int width, unsigned int height);

    /**
     * Disallow copying and assignment for now - these will have to be written
     *  with some care if we decide there's a need for copying renderers, and
     *  for now they are deleted for safety.
     */
    SDLRenderer(const SDLRenderer &other) = delete;
    SDLRenderer &operator=(const SDLRenderer &other) = delete;

    /**
     * Image draw callbacks
     *
     * MUST be implemented for each new type of Image!
     */
    void draw(SDLImage &image) const;

    /**
     * Swap front and back buffers
     */
    void flip();

    ~SDLRenderer();
private:
    SDL_Window *window;
    SDL_Surface *surface;
};

#endif // __SDL_RENDERER_H_
