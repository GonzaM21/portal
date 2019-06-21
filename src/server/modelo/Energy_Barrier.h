#ifndef TP4_ENERGY_BARRIER_H
#define TP4_ENERGY_BARRIER_H

#include "World.h"
#include "Entity.h"

class Energy_Barrier : public Entity {
    b2Body * barrier;
    World & world;
    std::string name;
    b2Vec2 sizes;
    int orientation;
public:
    //Contructor
    Energy_Barrier(World & world,float x_pos, float y_pos, float large, int orientation);
    //retorna le nombre de la clase
    const std::string& getEntityName() override;
    //no hace nada
    void startContact(b2Vec2) override;
    //no hac nada
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
    //retorna su posicion en el mundo.
    b2Vec2 getPosition();
    //retorna su tamaño (x,y)
    b2Vec2 getSizes();
    //devuelve su orietacion, horizontal o vertical
    int getOrientation();
    //destructor
    ~Energy_Barrier() = default;
};
#endif
