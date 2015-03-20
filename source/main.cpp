#include "Game.h"

#include "platform/Platform.h"
#include "scenes/level/Level.h"

#include <memory>

int main() {
    // Platform-specific setup - see Platform.cpp for details
    if (!Platform::initializePlatform()) {
        return 1;
    }

    std::shared_ptr<Image> background(Platform::createImage("../assets/test-background.png"));
    std::shared_ptr<Scene> scene(new Level(background));

    Game game(scene);

    // Run the game until it's done!
    game.run();
}
