#include "PlatformRenderer.h"

#include "Platform.h"

#include "SDL/SDLRenderer.h"
#include "../Camera.h"

namespace Platform
{
    void
    Renderer::render(std::list<std::shared_ptr<Platform::Image>> &images,
                     const Camera &camera)
        const
    {
        camera.cull(images);

        for (auto &image : images) {
            image->resize(camera);
            image->draw(*this, camera);
        }
    }

    void Renderer::draw(const SDLImage &image, const Camera &camera) const
    {

    }
}
