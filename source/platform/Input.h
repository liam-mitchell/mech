#ifndef __PLATFORM_INPUT_H_
#define __PLATFORM_INPUT_H_

#include <memory>

class Input
{
public:
    virtual void update() = 0;

public:
    virtual bool jump() = 0;
    virtual bool quit() = 0;
};

#endif // __PLATFORM_INPUT_H_
