#include "PlatformRenderer.h"

#include "Platform.h"

#include "SDL/SDLRenderer.h"

namespace Platform
{
    Renderer::Renderer(unsigned int width, unsigned int height)
    {
        if (platform == LINUX) {
            impl.reset(new SDLRenderer(width, height));
        }
        else {
            throw "Platform unsupported!";
        }
    }

    void
    Renderer::render(const std::list<Image> &images, const Camera &camera) const
    {
        for (auto & image : images) {
            image.draw(*this, camera);
        }
    }

    void Renderer::draw(const SDLImage &image, const Camera &camera) const
    {
        impl->draw(image, camera);
    }
}
