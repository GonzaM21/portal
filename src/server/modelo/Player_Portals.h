//
// Created by gonzalo on 03/06/19.
//

#ifndef TP4_PLAYER_PORTALS_H
#define TP4_PLAYER_PORTALS_H


#include "Portal.h"

class Player_Portals {
    Portal * portal1;
    bool portal1_shot;
    Portal * portal2;
    bool portal2_shot;
public:
    Player_Portals();
    Portal* shotPortalIn(World & world,float x_pos, float y_pos, float x_destiny, float y_destiny);
    Portal* shotPortalOut(World & world,float x_pos, float y_pos, float x_destiny, float y_destiny);
    Portal* getPortalIn();
    Portal* getPortalOut();
    ~Player_Portals();

};


#endif //TP4_PLAYER_PORTALS_H
