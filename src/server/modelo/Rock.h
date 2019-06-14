#ifndef TP4_ROCK_H
#define TP4_ROCK_H

#include "World.h"
#include "Entity.h"

class Rock : public Entity {
    b2Body * rock;
    World & world;
    std::string name;
    bool contact;
    bool live;
    float radius;
public:
    Rock(World & world,float x_pos, float y_pos,float radius);
    std::string getEntityName() override;
    void startContact(b2Vec2) override;
    void endContact() override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity *) override;
    void changePosition() override;
    void startBouncing() override ;
    b2Vec2 getPosition();
    float getAngle();
    float getRadius();
    ~Rock() = default;
};


#endif
