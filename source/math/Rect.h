#ifndef __RECT_H_
#define __RECT_H_

class Rect {
public:
    Rect();
    Rect(int x, int y, int width, int height);

public:
    int x;
    int y;
    int width;
    int height;
};

#endif // __RECT_H_
