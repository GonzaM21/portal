//
// Created by gonzalo on 31/05/19.
//

#include "Rock.h"

Rock::Rock(World &world, float x_pos, float y_pos, float radius) : world(world){
    rock = world.World_Add_Circle(x_pos,y_pos,radius,false);
    rock->SetUserData(this);
    name = "Rock";
    contact = false;
    live = true;
}

std::string Rock::Get_Entity_Name() {
    return name;
}

b2Vec2 Rock::Get_Position() {
    return rock->GetPosition();
}

float Rock::Get_Angle(){
    return rock->GetAngle();
}

void Rock::Start_Contact() {
    contact = true;
}

void Rock::End_Contact() {
    contact = false;
}

void Rock::Die() {
    live = true; //No tiene que morir
}

bool Rock::Lives() {
    return live;
}
