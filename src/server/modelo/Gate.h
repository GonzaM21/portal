#ifndef TP4_GATE_H
#define TP4_GATE_H

#include "World.h"
#include "Entity.h"
#include "Button.h"
#include <map>

class Gate : public Entity{
    b2Body * gate;
    std::string name;
    b2Vec2 sizes;
    bool live;
    bool contact;
    World& world;
    std::map<Button*,bool> buttons;
    bool door_is_open;
public:
    //Constructor
    Gate(World & world, float x_pos, float y_pos);
    //Retorna el nombre de la clase
    const std::string& getEntityName() override;
    //no hace nada
    void startContact(b2Vec2) override;
    //no hace nada
    void endContact() override;
    //no nace nada
    void die() override;
    //retorna true, nunca muere
    bool lives() override;
    //no hace nada
    bool setTransform(Entity *) override;
    //En caso de que los botones esten activados, se abre la puerta
    void changePosition() override;
    //no hace nada
    void win() override;
    //retorna la posicion en el mundo (x,y)
    b2Vec2 getPosition();
    //Retorna el tamaño de la puerta (x,y)
    b2Vec2 getSizes();
    //Agrega un boton a su mapa de botones
    void addButton(Button* button,int pos);
    //retorna si la puerta esta abierta o no
    bool isOpen();
    //destructor
    ~Gate() = default;


};


#endif
