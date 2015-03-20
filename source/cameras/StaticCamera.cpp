#include "StaticCamera.h"

StaticCamera::StaticCamera(float width, float height)
    : width(width)
    , height(height)
{}

void StaticCamera::cull(std::list<std::shared_ptr<Image>> &images) const
{

}

void StaticCamera::convertCoordinates(std::list<std::shared_ptr<Image>> &images,
                                      unsigned int pixwidth,
                                      unsigned int pixheight) const
{
    float xPixPerMeter = pixwidth / width;
    float yPixPerMeter = pixheight / height;

    for (auto &image: images) {
        unsigned int x = xPixPerMeter * image->position.x;
        unsigned int y = yPixPerMeter * image->position.y;
        unsigned int w = xPixPerMeter * image->size.x;
        unsigned int h = yPixPerMeter * image->size.y;

        image->setPixelPosition(x, y);
        image->setPixelSize(w, h);
    }
}

void StaticCamera::update(unsigned int dt)
{

}
