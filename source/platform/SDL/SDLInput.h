#ifndef __SDL_INPUT_H_
#define __SDL_INPUT_H_

#include "../Platform.h"

#include <SDL/SDL.h>

union SDL_Event;

class SDLInput : public Input
{
public:
    SDLInput();

    virtual void update();

    virtual bool jump();
    virtual bool quit();
private:
    void handleKeyDown(SDL_Event *event);
    void handleKeyUp(SDL_Event *event);
    void handleQuit();

private:
    static bool jump_;
    static bool quit_;
};

#endif // __SDL_INPUT_H_
