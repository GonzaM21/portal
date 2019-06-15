#include "Chell_Player.h"
#include "Macros.h"
//patron build
//ver lo de las colcsiones

Chell_Player::Chell_Player(World &world, float x_pos, float y_pos): world(world),contact_counter(0),jumper_counter(0){
    name = "Chell_Player";
    contact = true;
    teleport = false;
    live = true;
    bouncing = true;
    win = false;
    Filter_Data data(CHELL_BITS);
    data.addMaskBits(OTHER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    sizes = b2Vec2(CHELL_HIGH,CHELL_WIDTH);
    footSensor = new Foot_Sensor(this);
    std::cout<<"Chell "<<footSensor<<std::endl;
    chell = world.addPlayer(x_pos, y_pos, CHELL_WIDTH/2, CHELL_HIGH/2.f,data,footSensor);
    chell->SetUserData(this);
    direction_right = true;
}

bool Chell_Player::Jump(){
    if(!live) return false;
    std::cout<<"contact_counter: "<<contact<<"   "<<"Jumper_Counter: "<<jumper_counter<<std::endl;
   if (contact && jumper_counter == 0){
       chell->ApplyForceToCenter(b2Vec2(ZERO,CHELL_JUMP_FORCE),true);
       jumper_counter = 1;
       return true;
   }
    return false;
}

bool Chell_Player::Move(char &direction) {
    b2Vec2 actual_speed = this->chell->GetLinearVelocity();
    if(!live) return false;
    if(direction == 'd' && (actual_speed.x <= 0)){
        direction_right = true;
        if (actual_speed.y != 0) {
            chell->ApplyLinearImpulseToCenter(b2Vec2(CHELL_MOVE_FORCE/2,ZERO),true);
        } else {
        chell->ApplyLinearImpulseToCenter(b2Vec2(CHELL_MOVE_FORCE,ZERO),true);
        }
        return true;
    } else if(direction == 'a' && (actual_speed.x >= 0)){
        direction_right = false;
        if (actual_speed.y != 0) {
            chell->ApplyLinearImpulseToCenter(b2Vec2(-CHELL_MOVE_FORCE/2,ZERO),true);
        } else {
            chell->ApplyLinearImpulseToCenter(b2Vec2(-CHELL_MOVE_FORCE,ZERO),true);
        }
        return true;
    } else if(direction == 's') {
        this->Brake();
        return true;
    }
    return false;
}

void Chell_Player::Brake(){
    if(chell->GetLinearVelocity().y == 0){
        chell->SetLinearVelocity(b2Vec2(0,0));
    } else{
        if(chell->GetLinearVelocity().x < 0) chell->ApplyForceToCenter(b2Vec2(100.f,0),true);
        if(chell->GetLinearVelocity().x > 0) chell->ApplyForceToCenter(b2Vec2(-100.f,0),true);
    }
}

int Chell_Player::getStatus(){
    if(!live) return CHELL_DYING;
    if(win) return CHELL_DANCING;
    b2Vec2 velocity = chell->GetLinearVelocity();
    if(velocity.x == 0 && velocity.y == 0) return CHELL_QUIET;
    if(velocity.y < 0) return CHELL_FALLING;
    if(velocity.y > 0) return CHELL_JUMPING;
    if(velocity.x != 0) return CHELL_RUNNING;
    return CHELL_DANCING;
}

int Chell_Player::getDirection() {
    return this->direction_right;
} 

b2Vec2 Chell_Player::getPosition() {
    if(!live) return teleport_pos;
    return chell->GetPosition();
}

float Chell_Player::getAngle() {
    if(!live) return 0;
    return chell->GetAngle();
}

bool Chell_Player::setTransform(Entity * body) {
    if(!live) return false;

    if(!dynamic_cast<Portal *>(body)->havePartner()) return false;
    if(!dynamic_cast<Portal *>(body)->getPartnerPortal()->lives()) return false;

    teleport_pos = dynamic_cast<Portal *>(body)->getPartnerPortal()->getPosition();
    b2Vec2 normal = dynamic_cast<Portal *>(body)->getPartnerPortal()->getNormal();

    teleport = true;
    //b2Vec2 velocity_actual = chell->GetLinearVelocity();
    if(normal.x > 1){
        teleport_pos = teleport_pos + b2Vec2(0.7,0.0);
    } else {
        teleport_pos = teleport_pos - b2Vec2(0.7,0.0);
    }
    if(normal.y > 1){
        teleport_pos = teleport_pos + b2Vec2(0,0.7);
    } else {
        teleport_pos = teleport_pos - b2Vec2(0,0.7);
    }
    std::cout<<"Normal "<<normal.x<<" "<<normal.y<<std::endl;
    //velocity = b2Vec2(abs(velocity_actual.x/2) * normal.x/2,velocity_actual.y * normal.y);
    return true;
}

void Chell_Player::changePosition() {
    if(bouncing){
        std::cout<<"frenate"<<std::endl;
        chell->SetLinearVelocity(b2Vec2(0,0));
        bouncing = false;
        //jumper_counter = 0;
    }
    if(!teleport) return;
    chell->SetTransform(teleport_pos,chell->GetAngle());
    chell->SetLinearVelocity(b2Vec2(0,0));
    jumper_counter = 0;
    teleport = false;
}

void Chell_Player::startBouncing(){
    bouncing = true;
}

void Chell_Player::startContact(b2Vec2) {
    contact = true;
    printf("Empezo el contacto\n");
    //++contact_counter;
    jumper_counter = 0;
}

void Chell_Player::endContact() {
    std::cout<<"Chell end contact\n";
    if(chell->GetLinearVelocity().y < 0){
        contact = false;
    }
    jumper_counter = 1;
    //bouncing = true;
    //--contact_counter;
}

std::string Chell_Player::getEntityName() {
    return name;
}

Portal * Chell_Player::shotPortalIn(float x_pos, float y_pos) {
    if(!live) return nullptr;
    b2Vec2 position = chell->GetPosition();
    Portal * ball = portals.shotPortalIn(world,position.x - DELTA_POSITION,position.y - DELTA_POSITION,x_pos,y_pos);
    return ball;
}

Portal * Chell_Player::shotPortalOut(float x_pos, float y_pos) {
    if(!live) return nullptr;
    b2Vec2 position = chell->GetPosition();
    Portal * ball = portals.shotPortalOut(world,position.x - DELTA_POSITION,position.y - DELTA_POSITION,x_pos,y_pos);
    return ball;
}

void Chell_Player::die() {
    teleport_pos = chell->GetPosition();
    live = false;
}

bool Chell_Player::lives() {
    return live;
}

b2Vec2 Chell_Player::getSizes() {
    return sizes;
}

Portal* Chell_Player::getPortalIn() {
    return this->portals.getPortalIn();
}

Portal* Chell_Player::getPortalOut() {
    return this->portals.getPortalOut();
}