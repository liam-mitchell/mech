#ifndef __TEST_ENTITY_H_
#define __TEST_ENTITY_H_

#include "Entity.h"

class TestEntity : public Entity {
public:
    void TestEntity(const std::string &image, const Rect &area);
    
    void create()
    { std::cout << "Created test entity!\n"; }
    void destroy()
    { std::cout << "Destroyed test entity!\n"; }

    std::list<std::shared_ptr<Platform::Image>> getImages()
    { std::cout << "Got test entity images!\n"; };

private:
    std::shared_ptr<Platform::Image> image;
    Rect area;
};

#endif // __TEST_ENTITY_H_
