#include "SDLImage.h"

#include <iostream>

SDLImage::SDLImage()
{
    std::cout << "Created new SDL image!\n";
}

void
SDLImage::draw(const Platform::Renderer &renderer, const Camera &camera) const
{
    std::cout << "Image: Drew SDL image!\n";
    renderer.draw(*this, camera);
}
