#ifndef METAL_BLOCK_H
#define METAL_BLOCK_H

#include "World.h"

class Metal_Block{
    b2Body * block;
    float size;
public:
    //Contructor de un bloque de metal cuadrado. hay que pasarle la mital de lado
    Metal_Block(World &world,float x_pos, float y_pos, float size);

    //Contructor de un bloque de metal triangular. Hay que pasarle la mitad de los largos
    Metal_Block(World &world,float x_pos, float y_pos, float x_size, float y_size);

    b2Vec2 Get_Position();
    float Get_Angle();
    float Get_Size();
};
#endif
