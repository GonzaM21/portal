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
public:
    //Contructor de un bloque de metal cuadrado. hay que pasarle la mital de lado
    Metal_Block(World &world,float x_pos, float y_pos, float size);

    //Contructor de un bloque de metal triangular. Hay que pasarle la itad de los largos
    Metal_Block(World &world,float x_pos,float y_pos,float size,int angle);

    const std::string& getEntityName() override;
    void startContact(b2Vec2) override;
    void endContact() override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity *) override;
    void changePosition() override;
    void startBouncing() override ;
    void win();

    b2Vec2 getPosition();
    int getAngle();
    b2Vec2 getSizes();
    ~Metal_Block() = default;
};
#endif
