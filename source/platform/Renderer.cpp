#include "Renderer.h"

#include "../Camera.h"

void Renderer::render(std::list<std::shared_ptr<Image>> &images,
                      const Camera &camera) const
{
    camera.cull(images);

    for (auto &i: images) {
        i->resize(camera);
        i->draw(*this, camera);
    }
}
