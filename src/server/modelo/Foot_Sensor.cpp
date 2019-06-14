//
// Created by gm21 on 12/06/19.
//

#include "Foot_Sensor.h"

Foot_Sensor::Foot_Sensor(Entity *chell_player) {
    chell = chell_player;
    name = "Foot_Sensor";
}

std::string Foot_Sensor::getEntityName(){
    return name;
}

void Foot_Sensor::startContact(b2Vec2 pos){
    printf("COntacto\n");
    chell->startContact(pos);
}

void Foot_Sensor::endContact(){
    printf("fuera contacto\n");
    chell->endContact();
}

void Foot_Sensor::die(){}
bool Foot_Sensor::lives(){return true;}
bool Foot_Sensor::setTransform(Entity*){return true;}
void Foot_Sensor::changePosition(){}
void Foot_Sensor::startBouncing() {}