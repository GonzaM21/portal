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
    bool ball;
    bool send_it;
    World& world;
    b2Vec2 position;
    b2Vec2 sizes;
    b2Vec2 normal;
    b2Vec2 body_pos;
    float radius;
    int orientation; //0 = vertical, 1 = horizontal, 2 = inclinado desceciente, 3 = inclinado ascendente
public:
    //Contructor de una bola de energia
    Portal(World& world, float x_pos, float y_pos);

    //Se aplica una fuerza para que la bola de energia se mueva segun la posicion indicada.
    bool Move(float x_pos, float y_pos);

    //Devuelve la posicion de la bola de energia
    b2Vec2 getPosition();

    //devuelve el valor del angulo de la bola de energia
    float getAngle();

    const std::string& getEntityName() override;
    void startContact(b2Vec2 pos) override;
    void endContact() override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity * body) override;
    void changePosition() override;
    void startBouncing() override ;
    bool havePartner();
    b2Vec2 getNormal();
    bool changePortalPosition(float x_pos, float y_pos);
    bool setPartner(Portal * portal);
    Portal* getPartnerPortal();

    b2Vec2 getSizes();
    float getradius();
    bool isValid();
    int getOrientation();
    ~Portal() = default;

};


#endif //TP4_PORTAL_H
