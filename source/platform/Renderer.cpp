#include "Renderer.h"

#include "../cameras/Camera.h"

Renderer::Renderer(unsigned int width, unsigned int height)
    : width(width)
    , height(height)
{}

void Renderer::render(std::list<std::shared_ptr<Image>> &images,
                      const Camera &camera)
{
    camera.cull(images);
    camera.convertCoordinates(images, width, height);

    for (auto &image: images) {
        image->draw(*this);
    }

    flip();
}
