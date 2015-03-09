#ifndef __PLATFORM_INPUT_H_
#define __PLATFORM_INPUT_H_

#include <memory>

namespace Platform
{
    class Input
    {
    public:
        Input();

        void update();

        bool jumping();

        class Implementation
        {
        public:
            virtual void update() = 0;
            virtual bool jumping() = 0;
        };

    private:
        std::unique_ptr<Implementation> impl;
    };
}

#endif // __PLATFORM_INPUT_H_
