#include "SDLImage.h"

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDLImage::SDLImage(const std::string &path)
{
    surface = IMG_Load(path.c_str());
    if (!surface) {
        throw "Error initializing SDL image!";
    }

    rect.x = 0;
    rect.y = 0;

    rect.w = surface->w;
    rect.h = surface->h;
}

void SDLImage::draw(const Renderer &renderer)
{
    renderer.draw(*this);
}

void SDLImage::setPixelPosition(int x, int y)
{
    rect.x = x;
    rect.y = y;
}

void SDLImage::setPixelSize(int w, int h)
{
    rect.w = w;
    rect.h = h;

    if (w != surface->w || h != surface->h) {
        // TODO: scale the surface (SDL_BlitScaled())
    }
}

SDL_Surface *SDLImage::getSurface()
{
    return surface;
}

SDL_Rect *SDLImage::getRect()
{
    return &rect;
}

SDLImage::~SDLImage()
{
    SDL_FreeSurface(surface);
}
