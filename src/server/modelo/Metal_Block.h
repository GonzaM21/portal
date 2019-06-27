#ifndef TP4_METAL_BLOCK_H
#define TP4_METAL_BLOCK_H

#include "World.h"

class Metal_Block : public Entity{
    b2Body * block;
    b2Vec2 sizes;
    int angle;
    std::string name;
    bool live;
    bool contact;
    b2Vec2 position;
public:
    //Contructor de un bloque de metal cuadrado. hay que pasarle la mital de lado
    Metal_Block(World &world,float x_pos, float y_pos, float size);

    //Contructor de un bloque de metal triangular. Hay que pasarle la itad de los largos
    Metal_Block(World &world,float x_pos,float y_pos,float size,int angle);

    //retorna el nombre de la clase
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
    //no hace nda
    void changePosition() override;
    //no hace nada
    void win() override;
    //Retorna la posicion en el mundo (x,y)
    b2Vec2 getPosition();
    //retorna el angulo que tiene
    int getAngle();
    //retorna el tamano (x,y)
    b2Vec2 getSizes();
    //destructor
    ~Metal_Block() = default;
};
#endif
