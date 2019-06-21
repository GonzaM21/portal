#ifndef TP4_ENERGY_BARRIER_H
#define TP4_ENERGY_BARRIER_H

#include "World.h"
#include "Entity.h"

class Energy_Barrier : public Entity {
    b2Body * barrier;
    World & world;
    std::string name;
    b2Vec2 sizes;
    int orientation;
public:
    Energy_Barrier(World & world,float x_pos, float y_pos, float large, int orientation);
    const std::string& getEntityName() override;
    void startContact(b2Vec2) override;
    void endContact() override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity *) override;
    void changePosition() override;
    void startBouncing() override ;
    void win();
    b2Vec2 getPosition();
    b2Vec2 getSizes();
    int getOrientation();
    ~Energy_Barrier() = default;

};


#endif
