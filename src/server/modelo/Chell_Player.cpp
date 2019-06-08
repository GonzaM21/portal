#include "Chell_Player.h"
#include "Macros.h"

//patron build
//ver lo de las colcsiones

Chell_Player::Chell_Player(World &world, float x_pos, float y_pos): world(world) {
    name = "Chell_Player";
    contact = false;
    teleport = false;
    live = true;
    Filter_Data data(2);
    data.addMaskBits(1);
    data.addMaskBits(8);
    data.addMaskBits(16);
    sizes = b2Vec2(CHELL_HIGH,CHELL_WIDTH);
    chell = world.addPolygon(x_pos, y_pos, CHELL_WIDTH/2, CHELL_HIGH/2.f,false,data);
    chell->SetUserData(this);
}

bool Chell_Player::Jump(){
    if(!live) return false;
   if (contact){
       chell->ApplyForceToCenter(b2Vec2(ZERO,CHELL_JUMP_FORCE),true);
       return true;
   }
    return false;
}

bool Chell_Player::Move(char &direction) {
    b2Vec2 actual_speed = this->chell->GetLinearVelocity();
    if(!live) return false;
    if(direction == 'd' && !(actual_speed.x>0)){
        chell->ApplyLinearImpulseToCenter(b2Vec2(CHELL_MOVE_FORCE,ZERO),true);
        return true;
    } else if(direction == 'a' && !(actual_speed.x<0)){
        chell->ApplyLinearImpulseToCenter(b2Vec2(-CHELL_MOVE_FORCE,ZERO),true);
        return true;
    }
    return false;
}

void Chell_Player::Brake(){
    chell->SetLinearVelocity(b2Vec2(0,0));
}

b2Vec2 Chell_Player::getPosition() {
    if(!live) return b2Vec2(0,0);
    return chell->GetPosition();
}

float Chell_Player::getAngle() {
    if(!live) return 0;
    return chell->GetAngle();
}

bool Chell_Player::setTransform(Entity * body) {
    if(!live) return false;

    if(!dynamic_cast<Portal *>(body)->havePartner()) return false;
    b2Vec2 position = dynamic_cast<Portal *>(body)->getPartnerPortal()->getPosition();
    teleport = true;

    if(position.x < 0) teleport_pos = position + b2Vec2(0.5,0.0);
    else teleport_pos = position - b2Vec2(0.5,0.0);
    return true;
}

void Chell_Player::changePosition() {
    if(!teleport){
        //chell->SetLinearVelocity(b2Vec2(0,0));
        return;
    }
    chell->SetTransform(teleport_pos,chell->GetAngle());
    chell->SetLinearVelocity(b2Vec2(0,0));
    teleport = false;
}

void Chell_Player::startContact(b2Vec2 pos) {
    contact = true;
}

void Chell_Player::endContact() {
    contact = false;
}

std::string Chell_Player::getEntityName() {
    return name;
}

b2Vec2 calculatePortalPosition(b2Vec2 position,float x_pos, float y_pos){

    float x = 0;
    float y = position.y;

    if(position.x < x_pos){
        x = position.x + DELTA_ENERGY_BALL_X - 0.02;
    }
    if(position.x > x_pos){
        x = position.x - DELTA_ENERGY_BALL_X - 0.02;
    }

    return b2Vec2(x,y-0.02);
}

Portal Chell_Player::shotPortalIn(float x_pos, float y_pos) {
    //if(!live) return;
    b2Vec2 position = chell->GetPosition();
    b2Vec2 positionportal = calculatePortalPosition(position,x_pos,y_pos);
    Portal ball = portals.shotPortalIn(world,positionportal.x,positionportal.y,x_pos,y_pos);
    return ball;
}

Portal Chell_Player::shotPortalOut(float x_pos, float y_pos) {
    //if(!live) return;
    b2Vec2 position = chell->GetPosition();
    b2Vec2 positionportal = calculatePortalPosition(position,x_pos,y_pos);
    Portal ball = portals.shotPortalOut(world,positionportal.x,positionportal.y,x_pos,y_pos);
    return ball;
}

void Chell_Player::die() {
    std::cout<<"Murio\n";
    live = false;
}

bool Chell_Player::lives() {
    return live;
}

b2Vec2 Chell_Player::getSizes() {
    return sizes;
}