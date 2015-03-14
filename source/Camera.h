#ifndef __CAMERA_H_
#define __CAMERA_H_

#include "platform/Platform.h"

#include <list>

class Camera
{
public:
    void cull(std::list<std::shared_ptr<Image>> &images) const;
};

#endif // __CAMERA_H_
