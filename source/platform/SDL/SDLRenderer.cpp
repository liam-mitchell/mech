#include "SDLRenderer.h"
#include "SDLImage.h"

#include <iostream>

#include <SDL/SDL.h>

/**
 * Implements SDLRenderer.h
 */
SDLRenderer::SDLRenderer(unsigned int width, unsigned int height)
    : Renderer(width, height)
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

    std::cout << "Created SDL window!\n";
}

/**
 * Draw an SDLImage
 *
 * NOTE: Renderers should only implement the images they can handle (ie.
 *  draw(SDLImage, Camera) for SDLRenderer). Others should simply throw.
 */
void SDLRenderer::draw(SDLImage &image) const
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = image.getRect()->w;
    src.h = image.getRect()->h;

    SDL_Rect dest;
    dest.x = image.getRect()->x;
    dest.y = image.getRect()->y;
    dest.w = 0;
    dest.h = 0;

    SDL_BlitSurface(image.getSurface(),
                    &src,
                    surface,
                    &dest);
}

void SDLRenderer::flip()
{
    SDL_UpdateWindowSurface(window);
}

SDLRenderer::~SDLRenderer()
{
    SDL_DestroyWindow(window);
}
