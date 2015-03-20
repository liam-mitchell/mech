#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "Entity.h"

#include <list>
#include <memory>

class Player : public Entity {
public:
    Player(std::shared_ptr<Image> image, std::shared_ptr<Input> input);

    virtual void create();
    virtual void destroy();

    virtual std::list<std::shared_ptr<Image>> getImages();

    friend class PlayerBehaviour;

private:
    std::shared_ptr<Image> image;
    std::shared_ptr<Input> input;

    float x;
    float y;
};

#endif // __PLAYER_H_
