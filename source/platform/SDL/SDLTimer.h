#ifndef __SDL_TIMER_H_
#define __SDL_TIMER_H_

#include "../Platform.h"

/**
 * SDL implementation of Timer (see platform/Timer.h)
 */
class SDLTimer : public Timer
{
public:
    SDLTimer();

    /**
     * Return the number of ticks since last called
     */
    virtual unsigned int tick();
private:
    unsigned int last_tick;
};

#endif // __SDL_TIMER_H_
