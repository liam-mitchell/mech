#ifndef __RENDER_DATA_H_
#define __RENDER_DATA_H_

#include "../math/Rect.h"
#include "../platform/Platform.h"

class RenderData {
public:
    Platform::Image image;
    Rect area;
};

#endif // __RENDER_DATA_H_
