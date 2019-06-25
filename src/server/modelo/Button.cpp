#include "Button.h"
#include "Filter_Data.h"
#include "Macros.h"
#define BOTTOM_LARGE 1.0
#define BOTTOM_HIGH 0.25

Button::Button(World &world, float x_pos, float y_pos) : world(world) {
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    button = world.addPolygon(x_pos,y_pos,BOTTOM_LARGE/2,BOTTOM_HIGH/2,true,data);
    button->SetUserData(this);
    sizes = b2Vec2(BOTTOM_LARGE,BOTTOM_HIGH);
    contact = 0;
    live = true;
    status = false;
    name = "Button";
}

const std::string& Button::getEntityName() {
    return name;
}

bool Button::lives() {
    return live;
}

void Button::die() {
    live = true;
}

void Button::startContact(b2Vec2) {
    ++contact;
    status = true;
}

void Button::endContact() {
    --contact;
    status = false;
}

bool Button::setTransform(Entity *) {
    return true;
}

void Button::changePosition() {}

b2Vec2 Button::getPosition() {
    if (!live) return b2Vec2(0,0);
    return button->GetPosition();
}

b2Vec2 Button::getSizes() {
    return sizes;
}

bool Button::getStatus(){
    return contact > 0;
}

void Button::win() {}