#ifndef __PLATFORM_INPUT_H_
#define __PLATFORM_INPUT_H_

#include <memory>

class Input
{
public:
    virtual void update() = 0;

    virtual bool jumping() const = 0;
};

#endif // __PLATFORM_INPUT_H_
