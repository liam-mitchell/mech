#include "SDLImage.h"

#include <iostream>

SDLImage::SDLImage(const std::string &path)
{
    
}

void SDLImage::draw(const Renderer &renderer, const Camera &camera) const
{
    std::cout << "Image: Drew SDL image!\n";
    renderer.draw(*this, camera);
}

void SDLImage::resize(const Camera &camera)
{

}
