#ifndef __SDL_IMAGE_H_
#define __SDL_IMAGE_H_

#include "../Platform.h"

class SDLImage : public Image
{
public:
    SDLImage(const std::string &path);
    virtual void draw(const Renderer &renderer) const;
};

#endif // __SDL_IMAGE_H_
