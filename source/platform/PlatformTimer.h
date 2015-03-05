#ifndef __PLATFORM_TIMER_H_
#define __PLATFORM_TIMER_H_

#include <memory>

/**
 * Platform-agnostic timer inteface
 *
 * Dispatches the tick() function to the correct platform-specific timer.
 *
 * Like most platform-agnostic intefaces, maintains a unique_ptr to the correct
 *  interface implementation based on the platform chosen by Platform::platform.
 */
namespace Platform
{
    class Timer
    {
    public:
        Timer();

        /**
         * Returns the time in milliseconds since the last tick() call (or since
         *  construction, in the case of the first tick() call on a particular
         *  timer).
         */
        unsigned int tick();

        /**
         * Implementation to be overriden by platform-specific interfaces
         */
        class Implementation
        {
        public:
            virtual unsigned int tick() = 0;
        };

    private:
        std::unique_ptr<Implementation> impl;
    };
}

#endif // __PLATFORM_TIMER_H_