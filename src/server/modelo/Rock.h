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
    float radius;
    bool teleport;
    b2Vec2 teleport_pos;
    b2Vec2 velocity;
public:
    //Contructor
    Rock(World & world,float x_pos, float y_pos,float radius);
    //retorna el nombre de la clase
    const std::string& getEntityName() override;
    //no hace nada
    void startContact(b2Vec2) override;
    //no hace nada
    void endContact() override;
    //muere si toca una barrera de energia
    void die() override;
    //retorna si esta viva o no
    bool lives() override;
    //Obtiene los valores necesarios para teletransportarse
    bool setTransform(Entity * body) override;
    //Se teletrasporta si toca un portal
    void changePosition() override;
    //no hace nada
    void win() override;
    //Cambia la posicion cuando chell la toma
    void changePositionChell(b2Vec2 pos);
    //retorna su posicion (x,y)
    b2Vec2 getPosition();
    //le seta una gravedad
    void setGravity(int gravity);
    //retorna su radio
    float getRadius();
    //destructor
    ~Rock() = default;
};


#endif
