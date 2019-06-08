#include "Gate.h"

Gate::Gate(World &world, float x_pos, float y_pos) : world(world){
    gate = world.addPolygon(x_pos,y_pos,GATE_WIDTH/2,GATE_LARGE/2,true);
    gate->SetUserData(this);
    name = "Gate";
    sizes = b2Vec2(GATE_WIDTH,GATE_LARGE);
    contact = false;
    live = true;
    status = false;
    ball = false;
    position = gate->GetPosition();
}

std::string Gate::getEntityName() {
    return name;
}

bool Gate::Lives() {
    for(int i = 0; i < bottoms.size(); ++ i){
        if(!bottoms[i]->getStatus()) return true;
    }
    world.eraseBody(gate);
    gate = world.addCircle(position.x,position.y + 1,0.0001f,true);
    gate->SetUserData(this);
    status = true;
    ball = true;
    return true;
}

void Gate::Die() {
    live = false;
}

void Gate::startContact(b2Vec2 pos) {
    status = true;
}

void Gate::endContact() {
    contact = false;
}

bool Gate::setTransform(Entity *body) {
    return true;
}

void Gate::changePosition() {
    for(int i = 0; i < bottoms.size(); ++ i){
        if(bottoms[i]->getStatus()) return;
    }
    if(!ball) return;
    gate = world.addPolygon(position.x,position.y,GATE_WIDTH/2,GATE_LARGE/2,true);
    gate->SetUserData(this);
    status = false;
    ball = false;
}

b2Vec2 Gate::getPosition() {
    if (!live) return b2Vec2(0,0);
    return position;
}

float Gate::getAngle() {
    return 0;
}

b2Vec2 Gate::getSizes() {
    return sizes;
}

Bottom Gate::addBottom(float x_pos, float y_pos) {
    Bottom bottom = Bottom(world,x_pos,y_pos);
    bottoms.push_back(&bottom);
    return bottom;
}

bool Gate::isOpen(){
    return status;
}

Gate::~Gate(){
    for(int i = 0; i < bottoms.size(); ++ i){
        //delete bottoms[i];
    }
}