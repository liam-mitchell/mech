#include "Platform.h"

#include "SDL/SDLTimer.h"
#include "SDL/SDLRenderer.h"
#include "SDL/SDLImage.h"
#include "SDL/SDLInput.h"

#include <SDL/SDL.h>

namespace Platform {
    PlatformType platform = LINUX;
    const std::string Renderer::WINDOW_TITLE = "mech";

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

    std::shared_ptr<Timer> getTimer()
    {
        return std::shared_ptr<Timer>(new SDLTimer());
    }

    std::shared_ptr<Renderer> getRenderer(unsigned int width,
                                          unsigned int height)
    {
        return std::shared_ptr<Renderer>(new SDLRenderer(width, height));
    }
    
    std::shared_ptr<Input> getInput()
    {
        return std::shared_ptr<Input>(new SDLInput());
    }
    
    std::shared_ptr<Image> getImage(const std::string &path)
    {
        return std::shared_ptr<Image>(new SDLImage(path));
    }
}
