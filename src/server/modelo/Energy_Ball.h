#ifndef TP4_ENERGY_BALL_H
#define TP4_ENERGY_BALL_H

#include "World.h"

class Energy_Ball : public Entity{
    b2Body * energy_ball;
    std::string name;
    float radius;
    bool live;
    bool contact;
    World& world;
    float size;
    b2Vec2 new_velocity;
    bool change_velocity;
    int angle;
    int direction;
    b2Vec2 velocity;
    b2Vec2 position;
public:
    //Contructor de una bola de energia
    Energy_Ball(World& world, float x_pos, float y_pos);

    //Se aplica una fuerza para que la bola de energia se mueva segun la posicion indicada.
    bool Move(char direction);

    //Devuelve la posicion de la bola de energia
    b2Vec2 getPosition();

    //devuelve el valor del angulo de la bola de energia
    float getAngle();

    //Retorna le nomnre de la clase
    const std::string& getEntityName() override;
    //no hace nada
    void startContact(b2Vec2) override;
    //no hace nada
    void endContact() override;
    //en caso de que toque un emisor desaprece del mundo
    void die() override;
    //retorna si esta vida o no
    bool lives() override;
    //no hace nada
    bool setTransform(Entity *) override;
    //No hace nada
    void changePosition() override;
    //no hace nada
    void win() override;
    //retotna para que direcion esta yendo
    int getDirection();
    //retorna el valor de su radio
    float getRadius();
    //destructor
    ~Energy_Ball() = default;
};
#endif
