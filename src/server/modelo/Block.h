#ifndef TP4_BLOCK_H
#define TP4_BLOCK_H

#include "World.h"


class Block {
    b2Body* block;
public:
    //Contructor para crear bloques cuadradros
    Block(World &world,float x_pos, float y_pos, float size);
    //Constructor para crear bloques triangulares
    Block(World &world,float x_pos, float y_pos, float x_size, float y_size);
};


#endif //TP4_BLOCK_H
