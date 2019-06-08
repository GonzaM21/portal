#ifndef TP4_GATE_H
#define TP4_GATE_H

#include "World.h"
#include "Entity.h"
#include "Bottom.h"

class Gate : public Entity{
    b2Body * gate;
    std::string name;
    b2Vec2 sizes;
    bool live;
    bool contact;
    World& world;
    b2Vec2 position;
    std::vector<Bottom*> bottoms;
    bool status;
    bool ball;
public:
    Gate(World & world, float x_pos, float y_pos);
    std::string getEntityName() override;
    void startContact(b2Vec2 pos) override;
    void endContact() override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity * body) override;
    void changePosition() override;
    b2Vec2 getPosition();
    float getAngle();
    b2Vec2 getSizes();
    Bottom addBottom(float x_pos,float y_pos);
    bool isOpen();
    ~Gate();


};


#endif
