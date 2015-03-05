#ifndef __SDL_IMAGE_H_
#define __SDL_IMAGE_H_

#include "../Platform.h"

class SDLImage : public Platform::Image::Implementation
{
public:
    SDLImage();
    void draw(const Platform::Renderer &renderer, const Camera &camera) const;
};

#endif // __SDL_IMAGE_H_
