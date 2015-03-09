#include "PlatformInput.h"

#include "Platform.h"

#include "SDL/SDLInput.h"

namespace Platform
{
    Input::Input()
    {
        if (platform == LINUX) {
            impl.reset(new SDLInput);
        }
        else {
            throw "Platform unsupported!";
        }
    }

    void Input::update()
    {
        impl->update();
    }

    bool Input::jumping()
    {
        return impl->jumping();
    }
}
