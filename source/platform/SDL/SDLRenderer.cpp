#include "SDLRenderer.h"

#include <iostream>

/**
 * Implements SDLRenderer.h
 */
SDLRenderer::SDLRenderer(unsigned int width, unsigned int height)
{
    std::cout << "Created SDL renderer!\n";
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
