#include "Chell_Player.h"
#include "Macros.h"

Chell_Player::Chell_Player(World &world, float x_pos, float y_pos): world(world) {
    name = "Chell_Player";
    contact = false;
    live = true;
    chell = world.World_Add_Polygon(x_pos, y_pos, CHELL_WIDTH/2, CHELL_HIGH/2,false);
    chell->SetUserData(this);
}

bool Chell_Player::Chell_Jump(){
    if(!live) return false;
   if (contact){
       chell->ApplyForceToCenter(b2Vec2(ZERO,CHELL_JUMP_FORCE),true);
       return true;
   }
    return false;
}

bool Chell_Player::Chell_Move(char &direction) {
    if(!live) return false;
    if(direction == 'd'){
        chell->ApplyLinearImpulseToCenter(b2Vec2(CHELL_MOVE_FORCE,ZERO),true);
        return true;
    } else if(direction == 'a'){
        chell->ApplyLinearImpulseToCenter(b2Vec2(-CHELL_MOVE_FORCE,ZERO),true);
        return true;
    }
    return false;
}

b2Vec2 Chell_Player::Get_Position() {
    if(!live) return b2Vec2(0,0);
    //std::cout<<"Velocity: "<<chell->GetLinearVelocity().x<<" "<<chell->GetLinearVelocity().y<<std::endl;
    return chell->GetPosition();
}

float Chell_Player::Get_Angle() {
    if(!live) return 0;
    return chell->GetAngle();
}

bool Chell_Player::Chell_Teletransport(float x_pos, float y_pos){
    if(!live) return false;
    if (!world.Valid_Position(x_pos,y_pos)) return false;
    chell->SetTransform(b2Vec2(x_pos,y_pos),ZERO);
    return true;
}

void Chell_Player::Start_Contact() {
    contact = true;
}

void Chell_Player::End_Contact() {
    contact = false;
}

std::string Chell_Player::Get_Entity_Name() {
    return name;
}

/*Portal Chell_Player::Chell_Shot_Portal_in(char direction) {
    //if(!live) return;
    b2Vec2 position = chell->GetPosition();
    float x = 0;
    float y = 0;
    if(direction == 'L'){
        x = position.x - DELTA_ENERGY_BALL_X;
        y = position.y - DELTA_ENERGY_BALL_Y;
    } else{
        x = position.x + DELTA_ENERGY_BALL_X;
        y = position.y + DELTA_ENERGY_BALL_Y;
    }
    Portal ball = portals.Shot_Portal_in(x,y);
    std::cout<<ball.Move(direction)<<std::endl;
    return ball;
}

Portal Chell_Player::Chell_Shot_Portal_out(char direction) {
    //if(!live) return;
    b2Vec2 position = chell->GetPosition();
    float x = 0;
    float y = 0;
    if(direction == 'L'){
        x = position.x - DELTA_ENERGY_BALL_X;
        y = position.y - DELTA_ENERGY_BALL_Y;
    } else{
        x = position.x + DELTA_ENERGY_BALL_X;
        y = position.y + DELTA_ENERGY_BALL_Y;
    }
    Portal ball = portals.Shot_Portal_out(x,y);
    std::cout<<ball.Move(direction)<<std::endl;
    return ball;
}*/

void Chell_Player::Die() {
    std::cout<<"Murio\n";
    live = false;
}

bool Chell_Player::Lives() {
    return live;
}