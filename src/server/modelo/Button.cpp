#include "Button.h"
#include "Filter_Data.h"

Button::Button(World &world, float x_pos, float y_pos) : world(world) {
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    button = world.addPolygon(x_pos,y_pos,BOTTOM_LARGE/2,BOTTOM_HIGH/2,true,data);
    button->SetUserData(this);
    sizes = b2Vec2(BOTTOM_LARGE,BOTTOM_HIGH);
    contact = false;
    live = true;
    status = false;
    name = "Button";
}

std::string Button::getEntityName() {
    return name;
}

bool Button::lives() {
    return live;
}

void Button::die() {
    live = false;
}

void Button::startContact(b2Vec2) {
    contact = true;
    status = true;
    printf("Boton activado\n");
}

void Button::endContact() {
    contact = false;
    status = false;
    printf("Boton desactivado\n");
}

bool Button::setTransform(Entity *) {
    return true;
}

void Button::changePosition() {}

b2Vec2 Button::getPosition() {
    if (!live) return b2Vec2(0,0);
    return button->GetPosition();
}

float Button::getAngle() {
    if(!live) return 0;
    return button->GetAngle();
}

b2Vec2 Button::getSizes() {
    return sizes;
}

bool Button::getStatus(){
    return status;
}