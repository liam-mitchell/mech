#include "Renderer.h"

#include "../Camera.h"

void Renderer::render(std::list<std::shared_ptr<Image>> &images,
                      const Camera &camera) const
{
    camera.cull(images);
    camera.convertCoordinates(images);

    for (auto &i: images) {
        i->draw(*this);
    }
}
