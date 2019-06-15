#ifndef TP4_STONE_BLOCK_H
#define TP4_STONE_BLOCK_H

#include "World.h"

class Stone_Block : public Entity{
    b2Body * block;
    std::string name;
    b2Vec2 sizes;
    int angle;
public:
    //Contructor de un bloque de piedra cuadrado.
    Stone_Block(World &world,float x_pos, float y_pos,float size);

    //Contructor de un bloque de piedra triangular.
    Stone_Block(World &world,float x_pos, float y_pos,float size ,int angle);
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
};


#endif
