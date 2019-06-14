#ifndef TP4_ACID_H
#define TP4_ACID_H

#include "World.h"
#include "Entity.h"

class Acid : public Entity {
    b2Body * acid;
    World & world;
    std::string name;
    bool contact;
    bool live;
    b2Vec2 sizes;
public:
    Acid(World & world,float x_pos, float y_pos,float large);
    std::string getEntityName() override;
    void startContact(b2Vec2) override;
    void endContact()override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity *) override;
    void changePosition() override;
    void startBouncing() override ;
    b2Vec2 getPosition();
    b2Vec2 getSizes();
    float getAngle();
    ~Acid() = default;
};
#endif
