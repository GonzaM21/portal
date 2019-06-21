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
    int angle;
    int orientation; //0 = vertical, 1 = horizontal, 2 = inclinado desceciente, 3 = inclinado ascendente
public:
    //Contructor de una bola de energia
    Portal(World& world, float x_pos, float y_pos);

    //Se aplica una fuerza para que la bola de energia se mueva segun la posicion indicada.
    bool Move(float x_pos, float y_pos);

    //Devuelve la posicion de la bola de energia
    b2Vec2 getPosition();

    //devuelve el valor del angulo
    float getAngle();

    //retorna el nombre de la clase
    const std::string& getEntityName() override;

    //se setea para poder crear un portal de salida
    void startContact(b2Vec2 pos) override;

    //setea su contact en false
    void endContact() override;

    //en caso de chocar con algo indevido setea live en false
    void die() override;

    //retorna si esta vivo o no
    bool lives() override;

    //en caso de colisionar obtiene la posicion del otro objeto para crear un portal de salida/entrada
    bool setTransform(Entity * body) override;

    //Cmabia de forma para ser un portal de salida o de entrada
    void changePosition() override;
    //no hace nada
    void win() override;

    //retorna si tiene un compañero asignado
    bool havePartner();
    //retorna su normal luego de colsionar
    b2Vec2 getNormal();
    //cambia a un bola, si el portal fue disparado nuevamente
    bool changePortalPosition(float x_pos, float y_pos);
    //setea su compañero de salida
    bool setPartner(Portal * portal_partner);
    //retorna su compaero de salida
    Portal* getPartnerPortal();
    //retorna si es una bola disparada
    bool isABall();
    //retorna su tamaño (x,y)
    b2Vec2 getSizes();
    //retorna el tamalo de la esfera
    float getradius();
    //retorna si es un portal (no esfera)
    bool isValid();
    //devuelve la orietacion (su angulo)
    int getOrientation();
    //destructor
    ~Portal() = default;
};
#endif
