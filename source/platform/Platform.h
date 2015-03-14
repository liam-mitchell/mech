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

#include "Image.h"
#include "Input.h"
#include "Renderer.h"
#include "Timer.h"

#include <memory>

namespace Platform {
    /**
     * Call platform-specific setup functions
     */
    bool initializePlatform();

    /**
     * Platform-agnostic allocations
     */
    std::shared_ptr<Timer> createTimer();
    std::shared_ptr<Renderer> createRenderer(unsigned int width,
                                          unsigned int height);
    std::shared_ptr<Input> createInput();
    std::shared_ptr<Image> createImage(const std::string &path);
}

#endif // __PLATFORM_H_
