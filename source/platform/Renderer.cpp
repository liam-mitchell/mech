#include "Renderer.h"

#include "../Camera.h"

Renderer::Renderer(unsigned int width, unsigned int height)
    : width(width)
    , height(height)
{}

void Renderer::render(std::list<std::shared_ptr<Image>> &images,
                      const Camera &camera) const
{
    camera.cull(images);
    camera.convertCoordinates(images, width, height);

    for (auto &image: images) {
        image->draw(*this);
    }
}
