#ifndef __SDL_IMAGE_H_
#define __SDL_IMAGE_H_

#include "../Platform.h"

class SDLImage : public Image
{
public:
    SDLImage(const std::string &path);
    virtual void draw(const Renderer &renderer) const;

    virtual void setPixelPosition(unsigned int x, unsigned int y);
    virtual void setPixelSize(unsigned int w, unsigned int h);
};

#endif // __SDL_IMAGE_H_
