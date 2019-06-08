#include "Player_Portals.h"

Player_Portals::Player_Portals() : portal1_shot(false), portal2_shot(false){}

Portal Player_Portals::shotPortalIn(World &world, float x_pos, float y_pos,float x_destiny, float y_destiny) {
    if(portal1_shot){
        portal1->changePortalPosition(x_pos,y_pos);
    } else{
        portal1 = new Portal(world,x_pos,y_pos);
    }
    portal1_shot = true;
    portal1->Move(x_destiny, y_destiny);
    if(portal2_shot){
        portal1->setPartner(portal2);
        portal2->setPartner(portal1);
    }
    return *portal1;
}

Portal Player_Portals::shotPortalOut(World &world, float x_pos, float y_pos, float x_destiny, float y_destiny) {
    if(portal2_shot){
        portal2->changePortalPosition(x_pos,y_pos);
    } else{
        portal2 = new Portal(world,x_pos,y_pos);
    }
    portal2_shot = true;
    portal2->Move(x_destiny,y_destiny);
    if(portal1_shot){
        portal2->setPartner(portal1);
        portal1->setPartner(portal2);
    }
    return *portal2;
}

Player_Portals::~Player_Portals() {
    if(portal1_shot) delete portal1;
    if(portal2_shot) delete portal2;
}