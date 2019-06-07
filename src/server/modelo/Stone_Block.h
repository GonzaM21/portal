#ifndef TP4_STONE_BLOCK_H
#define TP4_STONE_BLOCK_H

#include "World.h"

class Stone_Block {
    b2Body * block;
public:
    //Contructor de un bloque de piedra cuadrado. hay que pasarle la mital de lado
    Stone_Block(World &world,float x_pos, float y_pos, float size);

    //Contructor de un bloque de piedra triangular. Hay que pasarle la itad de los largos
    Stone_Block(World &world,float x_pos, float y_pos, float x_size, float y_size);
};


#endif
