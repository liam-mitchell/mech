#ifndef __PLATFORM_H_
#define __PLATFORM_H_

/**
 * The Platform namespace holds interfaces to platform APIs, and a method
 *  for producing a concrete class of the correct type for each necessary
 *  platform-dependent API.
 *
 * The core interfaces in the Platform namespace include:
 *  - Timers
 *  - Input management
 *  - Renderers
 *  - Sound managers
 *  - Asset loaders
 *
 * This should be the ONLY NAMESPACE which is touching any platform-specific
 *  functions! Everyone else should go through this.
 */

#include "PlatformImage.h"
#include "PlatformInput.h"
#include "PlatformRenderer.h"
#include "PlatformTimer.h"

namespace Platform
{
    /**
     * Platform-independent timer interface
     * 
     * Provides a simple interface - tick() will return the time since the last
     *  time tick() was called (or time since initialization, in case of the
     *  first tick() call on a particular timer).
     */

    // Supported platforms
    enum PlatformType {
        WINDOWS,
        LINUX,
        MAC,
    };

    extern PlatformType platform;

    /**
     * Call platform-specific setup functions
     */
    bool initializePlatform();
}

#endif // __PLATFORM_H_
