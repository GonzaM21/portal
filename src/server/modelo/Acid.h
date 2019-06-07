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
    float large;
public:
    Acid(World & world,float x_pos, float y_pos,float large);
    virtual std::string Get_Entity_Name();
    virtual void Start_Contact();
    virtual void End_Contact();
    virtual void Die();
    virtual bool Lives();
    b2Vec2 Get_Position();
    float Get_Angle();
    float Get_Large();
};
#endif
