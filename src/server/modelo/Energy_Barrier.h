#ifndef TP4_ENERGY_BARRIER_H
#define TP4_ENERGY_BARRIER_H

#include "World.h"
#include "Entity.h"

class Energy_Barrier : public Entity {
    b2Body * barrier;
    World & world;
    std::string name;
    b2Vec2 sizes;
public:
    Energy_Barrier(World & world,float x_pos, float y_pos, float large);
    std::string getEntityName() override;
    void startContact(b2Vec2 pos) override;
    void endContact() override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity * body) override;
    void changePosition() override;
    b2Vec2 getPosition();
    b2Vec2 getSizes();

};


#endif