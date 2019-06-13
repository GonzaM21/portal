#ifndef TP4_GATE_H
#define TP4_GATE_H

#include "World.h"
#include "Entity.h"
#include "Button.h"

class Gate : public Entity{
    b2Body * gate;
    std::string name;
    b2Vec2 sizes;
    bool live;
    bool contact;
    World& world;
    b2Vec2 position;
    std::vector<Button*> buttons;
    bool status;
    bool ball;
public:
    Gate(World & world, float x_pos, float y_pos);
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
    Button addButton(float x_pos,float y_pos);
    bool isOpen();
    ~Gate();


};


#endif
