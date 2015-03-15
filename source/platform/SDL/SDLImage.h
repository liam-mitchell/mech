#ifndef __SDL_IMAGE_H_
#define __SDL_IMAGE_H_

#include "../Platform.h"

#include <SDL/SDL.h>
#include <SDL/SDL_rect.h>

class SDLImage : public Image
{
public:
    SDLImage(const std::string &path);
    virtual void draw(const Renderer &renderer);

    virtual void setPixelPosition(int x, int y);
    virtual void setPixelSize(int w, int h);

    virtual ~SDLImage();

    SDL_Surface *getSurface();
    SDL_Rect *getRect();

private:
    SDL_Surface *surface;
    SDL_Rect rect;
};

#endif // __SDL_IMAGE_H_
