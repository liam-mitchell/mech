#include "Platform.h"

#include "SDL/SDLTimer.h"

#include <exception>

namespace Platform
{

    /**
     * Construct the correct timer based on platform
     */
    Timer::Timer()
    {
        if (platform == LINUX) {
            impl.reset(new SDLTimer);
        }
        else {
            throw "Platform unsupported!";
        }
    }

    unsigned int Timer::tick()
    {
        return impl->tick();
    }
}
