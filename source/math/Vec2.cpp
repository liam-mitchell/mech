#include "Vec2.h"

#include <assert.h>

Vec2::Vec2(float x, float y)
    : x(x)
    , y(y)
{}

Vec2 &Vec2::operator+=(const Vec2 &other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vec2 &Vec2::operator-=(const Vec2 &other)
{
    x -= other.x;
    y -= other.y;

    return *this;
}

Vec2 &Vec2::operator*=(float scale)
{
    x *= scale;
    y *= scale;

    return *this;
}

Vec2 &Vec2::operator/=(float scale)
{
    assert(scale != 0);

    x /= scale;
    y /= scale;

    return *this;
}

Vec2 Vec2::operator+(const Vec2 &other) const
{
    Vec2 temp(*this);
    temp += other;

    return temp;
}

Vec2 Vec2::operator-(const Vec2 &other) const
{
    Vec2 temp(*this);
    temp -= other;

    return temp;
}

Vec2 Vec2::operator*(float scale) const
{
    Vec2 temp(*this);
    temp *= scale;

    return temp;
}

Vec2 Vec2::operator/(float scale) const
{
    Vec2 temp(*this);
    temp /= scale;

    return temp;
}
