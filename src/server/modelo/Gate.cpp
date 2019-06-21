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
    door_is_open = false;
}

const std::string& Gate::getEntityName() {
    return name;
}

bool Gate::lives() {
    /*bool state = true;
    for (auto button: buttons) {
      if (button.first->getStatus() != button.second) state = false;
    }
    door_is_open = state;
    bool op_state = !state;
    gate->IsActive(op_state);*/
    return true;
}

void Gate::die() {
    live = false;
}

void Gate::startContact(b2Vec2) {
    contact = true;
}

void Gate::endContact() {
    contact = false;
}

bool Gate::setTransform(Entity *) {
    return true;
}

void Gate::changePosition() {
    bool state = true;
    for (auto button: buttons) {
      if (button.first->getStatus() != button.second) state = false;
      std::cout<<"for: "<<button.first->getStatus()<<button.second<<std::endl;
    }
    door_is_open = state;
    //std::cout<<"Puerta activada"<<door_is_open<<" true "<<true<<std::endl;
    gate->SetActive(!door_is_open);
}

b2Vec2 Gate::getPosition() {
    if (!live) return b2Vec2(0,0);
    return gate->GetPosition();
}

float Gate::getAngle() {
    return 0;
}

b2Vec2 Gate::getSizes() {
    return sizes;
}

void Gate::addButton(Button *button, int pos) {
    std::cout<<"boton agregado "<<std::endl;
    if (pos == UP) buttons.insert({button,true});
    if (pos == DOWN) buttons.insert({button,false});
}

bool Gate::isOpen(){
    return door_is_open;
}

void Gate::startBouncing() {}

void Gate::win(){}
