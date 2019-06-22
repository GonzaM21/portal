#ifndef TP4_BOTTOM_H
#define TP4_BOTTOM_H

#include "World.h"
#include "Entity.h"

class Button : public Entity{
    b2Body * button;
    std::string name;
    b2Vec2 sizes;
    bool live;
    int contact;
    World& world;
    bool status;
public:
    //Contructor
    Button(World & world, float x_pos, float y_pos);
    //devuelve el nombre de la clase
    const std::string& getEntityName() override;
    //setea true cuando tiene un objeto encima
    void startContact(b2Vec2) override;
    //setea false cuando no tiene ningun contacto encima
    void endContact() override;
    //no hace nada
    void die() override;
    //devuelve que esta vido
    bool lives() override;
    //no hace nada
    bool setTransform(Entity *) override;
    //no hace nada
    void changePosition() override;
    //no hace nada
    void win() override;
    //devuelve su posicion en el mundo (x,y)
    b2Vec2 getPosition();
    //devuelve su tamaño en (x,y)
    b2Vec2 getSizes();
    //devulve si esta activado o no
    bool getStatus();
    //destructor por defecto
    ~Button() = default;

};


#endif
