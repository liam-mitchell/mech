#ifndef __SDL_INPUT_H_
#define __SDL_INPUT_H_

#include "../Platform.h"

class SDLInput : public Platform::Input::Implementation
{
public:
    virtual void update();
    
    virtual bool jumping();
};

#endif // __SDL_INPUT_H_
