#ifndef TP4_GROUND_H
#define TP4_GROUND_H

#include "World.h"

class Ground {
    b2Body* ground;
public:

    //Contructor de la clase Ground. Hay que pasarle la mitad de largo y la mitad de la altura
    Ground(World &world,float x_pos, float y_pos, float x_size, float y_size);
};


#endif //TP4_GROUND_H
