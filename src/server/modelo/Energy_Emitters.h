#ifndef TP4_ENERGY_EMITTERS_H
#define TP4_ENERGY_EMITTERS_H

#include "World.h"
#include "Entity.h"
#include "Energy_Ball.h"

class Energy_Emitters : public Entity{
    World & world;
    b2Body * emitter;
    bool charged;
    b2Vec2 sizes;
    int direction;
    std::string name;
    int step_counter;
    std::vector<Energy_Ball *> energy_balls;
public:
    Energy_Emitters(World & world, float x_pos, float y_pos, float size,int direction, bool charged);
    b2Vec2 getPosition();
    b2Vec2 getSizes();
    const std::string& getEntityName() override;
    void startContact(b2Vec2) override;
    void endContact() override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity *) override;
    void startBouncing() override ;
    void changePosition() override;
    Energy_Ball* getEnergyBallShoted();
    ~Energy_Emitters();
};


#endif
