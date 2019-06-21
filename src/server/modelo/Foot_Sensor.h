#ifndef TP4_FOOT_SENSOR_H
#define TP4_FOOT_SENSOR_H

#include "World.h"
#include "Entity.h"
//Clase que verifica cuando un personaje puede saltar
class Foot_Sensor : public Entity {
    Entity * chell;
    std::string name;
public:
    //Constructor
    explicit Foot_Sensor(Entity * chell_player);
    //retorna el nombre de la clase
    const std::string& getEntityName() override;
    //en caso de colsionar llama a startConctact del personaje alamanceado
    void startContact(b2Vec2 pos) override;
    ////en caso de colsionar llama a endConctact del personaje alamanceado
    void endContact()override;
    //no hace nada
    void die() override;
    //retorna true
    bool lives() override;
    //no hace nada
    bool setTransform(Entity *) override;
    //no hace nada
    void changePosition() override;
    //no hace nada
    void win() override;
};
#endif
