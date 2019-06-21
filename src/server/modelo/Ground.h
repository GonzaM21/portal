#ifndef TP4_GROUND_H
#define TP4_GROUND_H

#include "World.h"

class Ground : public Entity{
    b2Body* ground;
    b2Vec2 sizes;
    std::string name;
public:
    //Contructor de la clase Ground.
    Ground(World &world,float x_pos, float y_pos,  float width, float high);
    //Retorna el nombre de la clase
    const std::string& getEntityName() override;
    //no hace nada
    void startContact(b2Vec2) override;
    //no hace nada
    void endContact() override;
    //no hace nada
    void die() override;
    //Retorna true, no muere
    bool lives() override;
    //no hace nada
    bool setTransform(Entity *) override;
    //no hace nada
    void changePosition() override;
    //no hace nada
    void win() override;
    //retorna el tamaño (x,y)
    b2Vec2 getSizes();
    //retorna su posicion (x,y)
    b2Vec2 getPosition();
    //destructor
    ~Ground() = default;
};


#endif //TP4_GROUND_H
