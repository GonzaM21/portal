#ifndef TP4_GATE_H
#define TP4_GATE_H

#include "World.h"
#include "Entity.h"
#include "Button.h"
#include <map>

class Gate : public Entity{
    b2Body * gate;
    std::string name;
    b2Vec2 sizes;
    bool live;
    bool contact;
    World& world;
    std::map<Button*,bool> buttons;
    bool door_is_open;
public:
    Gate(World & world, float x_pos, float y_pos);
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
    b2Vec2 getSizes();
    void addButton(Button* button,int pos);
    bool isOpen();
    ~Gate() = default;


};


#endif
