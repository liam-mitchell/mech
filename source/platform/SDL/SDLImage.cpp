#include "SDLImage.h"

#include <iostream>

SDLImage::SDLImage(const std::string &path)
{
    
}

void SDLImage::draw(const Renderer &renderer) const
{
    std::cout << "Image: Drew SDL image!\n";
    renderer.draw(*this);
}
