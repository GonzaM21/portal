#ifndef TP4_STONE_BLOCK_H
#define TP4_STONE_BLOCK_H

#include "World.h"

class Stone_Block : public Entity{
    b2Body * block;
    std::string name;
    b2Vec2 sizes;
    int angle;
public:
    //Contructor de un bloque de piedra cuadrado.
    Stone_Block(World &world,float x_pos, float y_pos,float size);

    //Contructor de un bloque de piedra triangular.
    Stone_Block(World &world,float x_pos, float y_pos,float size ,int angle);
    //Retorna el nombre de la clase
    const std::string& getEntityName() override;
    //no hace nada
    void startContact(b2Vec2) override;
    //no hace nada
    void endContact() override;
    //no hace nada
    void die() override;
    //retorna true, nunca muere
    bool lives() override;
    //no hace nada
    bool setTransform(Entity *) override;
    //no hace nada
    void changePosition() override;
    //no hace nada
    void win() override;
    //retorna la posicion (x,y)
    b2Vec2 getPosition();
    //retorna el angulo que tiene
    int getAngle();
    //retorna el tamano que tiene
    b2Vec2 getSizes();
};
#endif
