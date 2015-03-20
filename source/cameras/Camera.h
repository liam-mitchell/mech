#ifndef __CAMERA_H_
#define __CAMERA_H_

#include "../platform/Platform.h"

#include <list>

class Camera
{
public:
    virtual void cull(std::list<std::shared_ptr<Image>> &images) const = 0;
    virtual void convertCoordinates(std::list<std::shared_ptr<Image>> &images,
                                    unsigned int width,
                                    unsigned int height) const = 0;
    virtual void update(unsigned int dt) = 0;
};

#endif // __CAMERA_H_
