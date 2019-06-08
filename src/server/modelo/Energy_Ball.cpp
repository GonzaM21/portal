// #include <cmath>
#include "Energy_Ball.h"
#include "Macros.h"

Energy_Ball::Energy_Ball(World& world, float x_pos, float y_pos): world(world) {
    energy_ball = world.World_Add_Circle(x_pos,y_pos,ENERGY_BALL,false);
    energy_ball->SetGravityScale(0);
    contact = false;
    name = "Energy_Ball";
    live = true;
    energy_ball->SetUserData(this);
}

bool Energy_Ball::move(char direction){
    if(direction == 'R'){
        energy_ball->ApplyForceToCenter(b2Vec2(ENERGY_BALL_FORCE,ZERO),true);
        return true;
    }
    if(direction == 'L'){
        energy_ball->ApplyForceToCenter(b2Vec2(-ENERGY_BALL_FORCE,ZERO),true);
        return true;
    }
    return false;
}

b2Vec2 Energy_Ball::Get_Position(){
    if(!live) return b2Vec2(0,0);
    return energy_ball->GetPosition();
}

float Energy_Ball::Get_Angle() {
    if(!live) return 0;
    return energy_ball->GetAngle();
}

void Energy_Ball::Start_Contact() {
    contact = true;
}

void Energy_Ball::End_Contact() {
    contact = false;
}

std::string Energy_Ball::Get_Entity_Name() {
    return name;
}

void Energy_Ball::Die() {
     live = false;
}

bool Energy_Ball::Lives(){
    return live;
}