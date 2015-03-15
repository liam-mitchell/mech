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

void SDLImage::setPixelPosition(unsigned int x, unsigned int y)
{

}

void SDLImage::setPixelSize(unsigned int w, unsigned int h)
{

}
