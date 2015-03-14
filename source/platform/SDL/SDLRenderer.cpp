#include "SDLRenderer.h"

#include <iostream>

#include <SDL/SDL.h>

/**
 * Implements SDLRenderer.h
 */
SDLRenderer::SDLRenderer(unsigned int width, unsigned int height)
{
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(),
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width,
                              height,
                              SDL_WINDOW_OPENGL);

    if (!window) {
        throw "SDL failed to create window!\n";
    }

    surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    std::cout << "Created SDL window!\n";
}

/**
 * Draw an SDLImage
 *
 * NOTE: Renderers should only implement the images they can handle (ie.
 *  draw(SDLImage, Camera) for SDLRenderer). Others should simply throw.
 */
void SDLRenderer::draw(const SDLImage &image, const Camera &camera) const
{
    std::cout << "Renderer: Drew SDL image!\n";
}

SDLRenderer::~SDLRenderer()
{
    SDL_DestroyWindow(window);
}
