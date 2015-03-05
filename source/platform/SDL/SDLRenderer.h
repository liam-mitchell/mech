#ifndef __SDL_RENDERER_H_
#define __SDL_RENDERER_H_

#include "../PlatformRenderer.h"

/**
 * SDL implementation of Platform::Renderer
 *
 * See PlatformRenderer.h for details
 */
class SDLRenderer : public Platform::Renderer::Implementation
{
public:
    SDLRenderer(unsigned int width, unsigned int height);

    /**
     * Image draw callbacks
     *
     * MUST be implemented for each new type of Platform::Image!
     */
    void draw(const SDLImage &image, const Camera &camera) const;
};

#endif // __SDL_RENDERER_H_
