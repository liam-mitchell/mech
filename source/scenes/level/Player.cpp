#include "Player.h"

#include <iostream>

class PlayerBehaviour : public Behaviour
{
public:
    PlayerBehaviour(Player &player, int priority);

    bool execute(Level &level, unsigned int dt);
private:
    Player &player;
};

Player::Player(std::shared_ptr<Image> image, std::shared_ptr<Input> input)
    : image(image)
    , input(input)
    , x(0)
    , y(0)
{
    std::shared_ptr<Behaviour> behaviour(new PlayerBehaviour(*this, 0));
    behaviours.insert(behaviour);
}

void Player::create()
{}

void Player::destroy()
{}

std::list<std::shared_ptr<Image>> Player::getImages()
{
    std::list<std::shared_ptr<Image>> images;
    images.push_back(image);
    return images;
}

PlayerBehaviour::PlayerBehaviour(Player &player, int priority)
    : Behaviour(priority)
    , player(player)
{}

bool PlayerBehaviour::execute(Level &level, unsigned int dt)
{
    player.input->update();

    if (player.input->jump()) {
        std::cout << "Player jumping!\n";
    }

    return true;
}
