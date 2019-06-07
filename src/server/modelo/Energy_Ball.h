#ifndef TP4_ENERGY_BALL_H
#define TP4_ENERGY_BALL_H

#include "World.h"

class Energy_Ball : public Entity{
    b2Body * energy_ball;
    std::string name;
    bool live;
    bool contact;
    World& world;
public:
    //Contructor de una bola de energia
    Energy_Ball(World& world, float x_pos, float y_pos);

    //Se aplica una fuerza para que la bola de energia se mueva segun la posicion indicada.
    bool move(char direction);

    //Devuelve la posicion de la bola de energia
    b2Vec2 Get_Position();

    //devuelve el valor del angulo de la bola de energia
    float Get_Angle();

    std::string Get_Entity_Name() override;
    void Start_Contact() override;
    void End_Contact() override;
    void Die() override;
    bool Lives() override;
};
#endif
