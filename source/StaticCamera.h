#ifndef __STATIC_CAMERA_H_
#define __STATIC_CAMERA_H_

#include "Camera.h"

class StaticCamera : public Camera
{
public:
    virtual void cull(std::list<std::shared_ptr<Image>> &images) const;
    virtual void convertCoordinates(std::list<std::shared_ptr<Image>> &images,
                                    unsigned int width,
                                    unsigned int height) const;
    virtual void update(unsigned int dt);
private:
    float width;
    float height;
};

#endif // __STATIC_CAMERA_H_
