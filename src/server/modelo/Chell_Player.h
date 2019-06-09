#ifndef TP4_CHELL_PLAYER_H
#define TP4_CHELL_PLAYER_H

#include "World.h"
#include "Entity.h"
#include "Portal.h"
#include "Player_Portals.h"

class Chell_Player : public Entity{
    b2Body* chell;
    Player_Portals portals;
    std::string name;
    World& world;
    bool live;
    bool contact;
    bool teleport;
    bool bouncing;
    bool win;
    b2Vec2 sizes;
    b2Vec2 teleport_pos;
    int contact_counter;
    int jumper_counter;
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
    void startContact(b2Vec2 pos) override;

    //Pone al atributo contact en flase
    void endContact() override;

    void changePosition() override;

    std::string getEntityName() override;

    //Retorna en un vector su posicion en x e y
    b2Vec2 getPosition();

    //retorna el valor de su angulo
    float getAngle();

    b2Vec2 getSizes();

    int getStatus();

    //El personaje dispara un portal segun la direccion indicada
    Portal * shotPortalIn(float x_pos, float y_pos);

    Portal * shotPortalOut(float x_pos, float y_pos);

    void die() override;

    bool lives() override;

};
#endif //TP4_CHELL_PLAYER_H
