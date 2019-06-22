#ifndef TP4_PLAYER_PORTALS_H
#define TP4_PLAYER_PORTALS_H

#include "Portal.h"

//Clase contenedora de los portales dsiparados por el personaje

class Player_Portals {
    Portal * portal1;
    bool portal1_shot;
    Portal * portal2;
    bool portal2_shot;
public:
    Player_Portals();
    //dispara un portal de entrada en la direcion pasada, y lo retorna
    Portal* shotPortalIn(World & world,float x_pos, float y_pos, float x_destiny, float y_destiny);
    //dispara un portal de salida en la direcion pasada, y lo retorna
    Portal* shotPortalOut(World & world,float x_pos, float y_pos, float x_destiny, float y_destiny);
    //retonna le portal de entrada disparado
    Portal* getPortalIn();
    //dispara el portal de salida disparado
    Portal* getPortalOut();
    //destructor, destruye a los portales creados
    //reseta los portales
    void resetPortal();
    ~Player_Portals();
};
#endif
