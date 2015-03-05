#include "Platform.h"

#include <SDL/SDL.h>

namespace Platform {
    PlatformType platform = LINUX;

    static bool initializeSDL()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            return false;
        }

        return true;
    }
    
    bool initializePlatform()
    {
        if (platform == LINUX) {
            return initializeSDL();
        }

        return false;
    }
}
