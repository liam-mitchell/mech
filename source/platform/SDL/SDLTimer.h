#ifndef __SDL_TIMER_H_
#define __SDL_TIMER_H_

#include "../Platform.h"

/**
 * SDL timer interface
 *
 * See Platform.h for details
 */
class SDLTimer : public Platform::Timer::Implementation
{
public:
    SDLTimer();
    virtual unsigned int tick();
private:
    unsigned int last_tick;
};

#endif // __SDL_TIMER_H_
