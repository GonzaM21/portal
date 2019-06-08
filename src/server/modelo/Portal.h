//
// Created by gonzalo on 03/06/19.
//

#ifndef TP4_PORTAL_H
#define TP4_PORTAL_H

#include "World.h"
#include "Entity.h"

class Portal : public Entity {
    b2Body * portal;
    Portal * partner;
    bool have_partner;
    std::string name;
    bool live;
    bool contact;
    World& world;
    float x_destiny;
    float y_destiny;
    b2Vec2 position;
    b2Vec2 sizes;
    float radius;
public:
    //Contructor de una bola de energia
    Portal(World& world, float x_pos, float y_pos);

    //Se aplica una fuerza para que la bola de energia se mueva segun la posicion indicada.
    bool Move(float x_pos, float y_pos);

    //Devuelve la posicion de la bola de energia
    b2Vec2 getPosition();

    //devuelve el valor del angulo de la bola de energia
    float getAngle();

    std::string getEntityName() override;
    void startContact(b2Vec2 pos = b2Vec2(0,0)) override;
    void endContact() override;
    void Die() override;
    bool Lives() override;
    bool setTransform(Entity * body) override{return true;}
    void changePosition() override;
    bool havePartner();

    bool changePortalPosition(float x_pos, float y_pos);
    bool setPartner(Portal * portal);
    Portal* getPartnerPortal();

    b2Vec2 getSizes();
    float getradius();

};


#endif //TP4_PORTAL_H
