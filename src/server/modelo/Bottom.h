#ifndef TP4_BOTTOM_H
#define TP4_BOTTOM_H

#include "World.h"
#include "Entity.h"

class Bottom : public Entity{
    b2Body * bottom;
    std::string name;
    b2Vec2 sizes;
    bool live;
    bool contact;
    World& world;
    bool status;
public:
    Bottom(World & world, float x_pos, float y_pos);
    std::string getEntityName() override;
    void startContact(b2Vec2) override;
    void endContact() override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity *) override;
    void changePosition() override;
    b2Vec2 getPosition();
    float getAngle();
    b2Vec2 getSizes();
    bool getStatus();

};


#endif
