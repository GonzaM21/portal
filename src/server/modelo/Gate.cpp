#include "Gate.h"
#define UP 0
#define DOWN 1

Gate::Gate(World &world, float x_pos, float y_pos) : world(world){
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BARRIER_BITS);
    gate = world.addPolygon(x_pos,y_pos,GATE_WIDTH/2,GATE_LARGE/2,true,data);
    gate->SetUserData(this);
    name = "Gate";
    sizes = b2Vec2(GATE_WIDTH,GATE_LARGE);
    contact = false;
    live = true;
    status = false;//no lo uso
    door_is_open = false;
    ball = false;
    position = gate->GetPosition();
}

std::string Gate::getEntityName() {
    return name;
}

bool Gate::lives() {
    /*if(buttons.size() == 0) return true;
    for(int i = 0; i < buttons.size(); ++ i){
        if(!buttons[i]->getStatus()) return true;
    }*/
    bool state = true;
    for (auto button: this->buttons) {
      if (button.first->getStatus() != button.second) state=false;
    }
    door_is_open = state;
    world.eraseBody(gate);
    Filter_Data data(0);
    gate = world.addCircle(position.x,position.y + 1,0.0001f,true,data);
    gate->SetUserData(this);
    status = true;//no lo uso
    ball = true;
    return true;
}

void Gate::die() {
    live = false;
}

void Gate::startContact(b2Vec2) {
    status = true;
}

void Gate::endContact() {
    contact = false;
}

bool Gate::setTransform(Entity *) {
    return true;
}

void Gate::changePosition() {
    /*if(buttons.size() == 0) return;
    for(int i = 0; i < buttons.size(); ++ i){
        if(buttons[i]->getStatus()) return;
    }*/
    bool state = true;
    for (auto button: this->buttons) {
      if (button.first->getStatus() != button.second) state=false;
    }
    door_is_open = state;
    if(!ball) return;
    Filter_Data data(0);
    gate = world.addPolygon(position.x,position.y,GATE_WIDTH/2,GATE_LARGE/2,true,data);
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

void Gate::addButton(Button *button, int pos) {
    if (pos == UP) buttons[button] = true;
    if (pos == DOWN) buttons[button] = false;
}

bool Gate::isOpen(){
    return door_is_open;
}
