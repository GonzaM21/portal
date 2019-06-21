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
    bool gravity;
    bool inmortal;
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

    //En caso de teletraportarse se cambia de posicion
    void changePosition() override;

    //devuelve le nombre de la clase
    const std::string& getEntityName() override;

    //Retorna en un vector su posicion en x e y
    b2Vec2 getPosition();

    //retorna el valor de su angulo
    float getAngle();

    //Agarra una roca
    void grabARock();

    //sueta la roca tomada previamente
    void dropTheRock();

    //devuelve su tamano (x,y)
    b2Vec2 getSizes();

    //devuelve su esta, caminando, saltando, etc.
    int getStatus();

    //El personaje dispara un portal segun la direccion indicada
    Portal * shotPortalIn(float x_pos, float y_pos);

    Portal * shotPortalOut(float x_pos, float y_pos);

    //mata al personaje
    void die() override;

    //retorna si esta vivo ono
    bool lives() override;

    //En caso de tocar una cake, el personaje gana
    void win() override;

    //retorna si esta yendo para la derecha o izquierda
    int getDirection();

    //devueve el portal de entrada disparado
    Portal *getPortalIn();

    //devuelve el portal de salida dispado
    Portal *getPortalOut();

    //De la inicial de esta adivinanza, encontrarás como activar la inmortalidad: (ignorar los articulos)
    //No puedes verla ni sentirla, y ocupa todos los huecos: no puedes olerla ni oírla, está detrás de los astros,
    // y está al pie de las colinas, llega primero, y se queda; mala risas y acaba vidas.
    void inmortalChell();


    //De la inicial de esta adivinanza, encontrarás como quitar la gravedad: (ignorar los articulos)
    // Canta sin voz, vuela sin alas, sin dientes muerde, sin boca habla.
    void antiGravity();

    ~Chell_Player();
};
#endif //TP4_CHELL_PLAYER_H
