#ifndef TP4_STONE_BLOCK_H
#define TP4_STONE_BLOCK_H

#include "World.h"

class Stone_Block {
    b2Body * block;
    b2Vec2 sizes;
    float angle;
public:
    //Contructor de un bloque de piedra cuadrado.
    Stone_Block(World &world,float x_pos, float y_pos,float size);

    //Contructor de un bloque de piedra triangular.
    Stone_Block(World &world,float x_pos, float y_pos,float size ,float angle);

    b2Vec2 getPosition();
    float getAngle();
    b2Vec2 getSizes();
};


#endif
