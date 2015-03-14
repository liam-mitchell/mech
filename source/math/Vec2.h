#ifndef __VEC2_H_
#define __VEC2_H_

class Vec2 {
public:
    Vec2() = default;
    Vec2(float x, float y);

    Vec2 &operator+=(const Vec2 &other);
    Vec2 &operator-=(const Vec2 &other);
    Vec2 &operator*=(float scale);
    Vec2 &operator/=(float scale);

    Vec2 operator+(const Vec2 &other) const;
    Vec2 operator-(const Vec2 &other) const;
    Vec2 operator*(float scale) const;
    Vec2 operator/(float scale) const;

public:
    float x;
    float y;
};

#endif // __VEC2_H_
