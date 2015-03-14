#ifndef __SDL_INPUT_H_
#define __SDL_INPUT_H_

#include "../Platform.h"

class SDLInput : public Platform::Input
{
public:
    virtual void update();
    
    virtual bool jumping() const;
};

#endif // __SDL_INPUT_H_
