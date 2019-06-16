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
    const std::string& getEntityName() override;
    void startContact(b2Vec2) override;
    void endContact() override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity *) override;
    void changePosition() override;
    void startBouncing() override ;
    void win();
    void applyForce(b2Vec2 force);
    void setVelocity(b2Vec2 velocity);
    void changePositionChell(b2Vec2 pos);
    b2Vec2 getPosition();
    void setGravity(int gravity);
    float getAngle();
    float getRadius();
    ~Rock() = default;
};


#endif
