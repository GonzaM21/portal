#include <math.h>
#include "Energy_Ball.h"
#include "Macros.h"
#include "Metal_Block.h"

Energy_Ball::Energy_Ball(World& world, float x_pos, float y_pos): world(world) {
    Filter_Data data(BALL_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(OTHER_BITS);
    energy_ball = world.addCircle(x_pos,y_pos,ENERGY_BALL,false,data,false);
    energy_ball->SetUserData(this);
    energy_ball->SetGravityScale(0);
    contact = false;
    change_velocity = false;
    name = "Energy_Ball";
    live = true;
    radius = ENERGY_BALL;
}

bool Energy_Ball::Move(char direction){
    if(direction == 'R'){
        energy_ball->ApplyForceToCenter(b2Vec2(ENERGY_BALL_FORCE,ZERO),true);
        return true;
    }
    if(direction == 'L'){
        energy_ball->ApplyForceToCenter(b2Vec2(-ENERGY_BALL_FORCE,ZERO),true);
        return true;
    }
    if(direction == 'U'){
        energy_ball->ApplyForceToCenter(b2Vec2(ZERO,ENERGY_BALL_FORCE),true);
        return true;
    }
    if(direction == 'D'){
        energy_ball->ApplyForceToCenter(b2Vec2(ZERO,-ENERGY_BALL_FORCE),true);
        return true;
    }
    return false;
}

b2Vec2 Energy_Ball::getPosition(){
    if(!live) return b2Vec2(0,0);
    b2Vec2 veloc = energy_ball->GetLinearVelocity();
    std::cout<<"Energy Ball velocity: "<<veloc.x<<"   "<<veloc.y<<std::endl;
    return energy_ball->GetPosition();
}

float Energy_Ball::getAngle() {
    if(!live) return 0;
    return energy_ball->GetAngle();
}

void Energy_Ball::startContact(b2Vec2) {
    /*std::cout<<pos.x<<""<<pos.y<<std::endl;
    b2Vec2 ball_velocity = energy_ball->GetLinearVelocity();
    std::cout<<"Veloc "<<ball_velocity.x<<"  "<<ball_velocity.y<<std::endl;

    std::cout<<"Veloc antes"<<new_velocity.x<<"  "<<new_velocity.y<<std::endl;
    std::cout<<(-2.0/3.0) * size<<(-1.0/3.0) * size<<std::endl;
    std::cout<<pos.x - ((-2.0/3) * size)<<"  "<<(pos.y - (-1.0/3) * size)<<std::endl;

    if( ball_velocity.x != 0 && ball_velocity.y != 0){
        printf("entro\n");
        new_velocity = b2Vec2(0,ball_velocity.x);
        change_velocity = true;
    }

    std::cout<<"Veloc dps "<<new_velocity.x<<"  "<<new_velocity.y<<std::endl;*/

    contact = true;
}

void Energy_Ball::endContact() {
    contact = false;
}

const std::string& Energy_Ball::getEntityName() {
    return name;
}

void Energy_Ball::die() {
     live = false;
}

bool Energy_Ball::lives(){
    return live;
}

float Energy_Ball::getRadius() {
    return radius;
}

bool Energy_Ball::setTransform(Entity *) {
    /*angle = dynamic_cast<Metal_Block *>(body)->getAngle();
    size = dynamic_cast<Metal_Block *>(body)->getSizes().x;
    std::cout<<size<<std::endl;*/
    return true;
}

void Energy_Ball::changePosition() {
}

void Energy_Ball::startBouncing() {}

void Energy_Ball::win(){}