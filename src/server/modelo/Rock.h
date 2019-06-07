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
public:
    Rock(World & world,float x_pos, float y_pos,float radius);
    virtual std::string Get_Entity_Name();
    virtual void Start_Contact();
    virtual void End_Contact();
    virtual void Die();
    virtual bool Lives();
    b2Vec2 Get_Position();
    float Get_Angle();

    //Elimino copias y creo constructor por movimiento
    //Rock(const Rock&) = delete;
    //Rock& operator=(const Rock&) = delete;
    //Rock(Rock&& other);
    //Rock& operator=(Rock&& other);
};


#endif
