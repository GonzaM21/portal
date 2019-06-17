#ifndef TP4_CHELL_PLAYER_H
#define TP4_CHELL_PLAYER_H

#include "World.h"
#include "Entity.h"
#include "Portal.h"
#include "Player_Portals.h"
#include "Foot_Sensor.h"
#include "Rock.h"

class Chell_Player : public Entity{
    b2Body* chell;
    Player_Portals portals;
    std::string name;
    World& world;
    bool live;
    int contact;
    bool teleport;
    bool bouncing;
    bool winner;
    b2Vec2 sizes;
    b2Vec2 teleport_pos;
    Foot_Sensor * footSensor;
    b2Vec2 velocity;
    int jumper_counter;
    bool direction_right;
    bool take;
    bool taking;
    Rock * rock;
public:
    //Contructor del personaje
    Chell_Player(World &world,float x_pos, float y_pos);

    //El personaje salta
    bool Jump();

    //El personaje se mueve segun la direccion que se le da
    bool Move(char& direction);

    void Brake();

    //El personaje se teletransporta a la posición indicada, si esta no esta ocupada.
    bool setTransform(Entity * body) override;

    //Pone al atributo contact en true
    void startContact(b2Vec2) override;

    //Pone al atributo contact en flase
    void endContact() override;

    void changePosition() override;

    const std::string& getEntityName() override;

    //Retorna en un vector su posicion en x e y
    b2Vec2 getPosition();

    //retorna el valor de su angulo
    float getAngle();

    void grabARock();

    void dropTheRock();

    b2Vec2 getSizes();

    int getStatus();

    //El personaje dispara un portal segun la direccion indicada
    Portal * shotPortalIn(float x_pos, float y_pos);

    Portal * shotPortalOut(float x_pos, float y_pos);

    void die() override;

    bool lives() override;

    void startBouncing() override ;

    void win();

    int getDirection();

    Portal *getPortalIn();

    Portal *getPortalOut();
};
#endif //TP4_CHELL_PLAYER_H
