#include "SDLInput.h"

bool SDLInput::jump_ = false;
bool SDLInput::quit_ = false;

SDLInput::SDLInput()
{}

void SDLInput::update()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            handleKeyDown(&event);
            break;
        case SDL_KEYUP:
            handleKeyUp(&event);
            break;
        case SDL_QUIT:
            handleQuit();
            break;
        default:
            break;
        }
    }
}

void SDLInput::handleKeyDown(SDL_Event *event)
{
    if (event->key.keysym.sym == SDLK_UP) {
        jump_ = true;
    }
}

void SDLInput::handleKeyUp(SDL_Event *event)
{
    if (event->key.keysym.sym == SDLK_UP) {
        jump_ = false;
    }
}

void SDLInput::handleQuit()
{
    quit_ = true;
}

bool SDLInput::jump()
{
    return jump_;
}

bool SDLInput::quit()
{
    return quit_;
}
