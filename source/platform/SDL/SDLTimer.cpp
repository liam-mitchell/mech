#include "SDLTimer.h"

#include <SDL/SDL.h>

/**
 * Implements SDLTimer.h
 */
SDLTimer::SDLTimer() {
    last_tick = SDL_GetTicks();
}

unsigned int SDLTimer::tick() {
    unsigned int old = last_tick;
    last_tick = SDL_GetTicks();
    SDL_Delay(10);
    return last_tick - old;
}
