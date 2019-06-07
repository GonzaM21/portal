#include "Acid.h"

Acid::Acid(World &world, float x_pos, float y_pos, float large) : world(world) {
    name = "Acid";
    contact = false;
    live = true;
    acid = world.World_Add_Polygon(x_pos, y_pos, large/2, 0.1f,true);
    acid->SetUserData(this);
    this->large = large;
}

std::string Acid::Get_Entity_Name() {
    return name;
}

void Acid::Start_Contact() {
    contact = true;
}

void Acid::End_Contact() {
    contact = false;
}

void Acid::Die() {
    live = true; //No tiene que morir
}

bool Acid::Lives() {
    return live;
}

b2Vec2 Acid::Get_Position() {
    return acid->GetPosition();
}

float Acid::Get_Angle() {
    return acid->GetAngle();
}

float Acid::Get_Large() {
    return this->large;
}