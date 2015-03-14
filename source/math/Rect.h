#ifndef __RECT_H_
#define __RECT_H_

class Rect {
public:
    Rect();
    Rect(float x, float y, float width, float height);

public:
    float x;
    float y;
    float width;
    float height;
};

#endif // __RECT_H_
