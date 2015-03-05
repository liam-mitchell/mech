#include "PlatformImage.h"

#include "Platform.h"

#include "SDL/SDLImage.h"

namespace Platform
{
    Image::Image()
    {
        if (platform == LINUX) {
            impl.reset(new SDLImage());
        }
        else {
            throw "Platform unsupported!";
        }
    }

    void Image::draw(const Renderer &renderer, const Camera &camera) const
    {
        impl->draw(renderer, camera);
    }
}
