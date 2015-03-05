#include "Game.h"

#include "platform/Platform.h"
#include "scenes/Level.h"

#include <memory>

int main() {
    // Platform-specific setup - see Platform.cpp for details
    if (!Platform::initializePlatform()) {
        return 1;
    }

    // The game should probably just take ownership of a raw scene pointer...
    std::unique_ptr<Scene> scene(new Level());
    Game game(std::move(scene));

    // Run the game until it's done!
    game.run();
}
