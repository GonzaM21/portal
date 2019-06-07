#ifndef TP4_CHELL_PLAYER_H
#define TP4_CHELL_PLAYER_H

#include "World.h"
#include "Entity.h"
//#include "Portals.h"

class Chell_Player : public Entity{
    b2Body* chell;
    std::string name;
    World& world;
    bool live;
    bool contact;
    //Portals portals;
public:
    //Contructor del personaje
    Chell_Player(World &world,float x_pos, float y_pos);

    //ignorar este metodo, retornna el tipo de clase
    //Chell_Player* getEntityType() override;

    //El personaje salta
    bool Chell_Jump();

    //El personaje se mueve segun la direccion que se le da
    bool Chell_Move(char& direction);

    //El personaje se teletransporta a la posición indicada, si esta no esta ocupada.
    bool Chell_Teletransport(float x_pos, float y_pos);

    //Pone al atributo contact en true
    void Start_Contact() override;

    //Pone al atributo contact en flase
    void End_Contact() override ;

    std::string Get_Entity_Name() override;

    //Retorna en un vector su posicion en x e y
    b2Vec2 Get_Position();

    //retorna el valor de su angulo
    float Get_Angle();

    //El personaje dispara un portal segun la direccion indicada
    //Portal Chell_Shot_Portal_in(char direction);

    //El personaje dispara un portal segun la direccion indicada
    //Portal Chell_Shot_Portal_out(char direction);

    void Die() override;

    bool Lives() override;

};
#endif //TP4_CHELL_PLAYER_H
