#include "Metal_Block.h"
#include "Macros.h"

Metal_Block::Metal_Block(World &world,float x_pos, float y_pos,float size){
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    block = world.addBox(x_pos,y_pos,size/2.f,true,data);
    angle = 90;
    sizes = b2Vec2(size,size);
    block->SetUserData(this);
    name = "Metal_Block";
    contact = false;
    live = true;
    position = block->GetPosition();
}

Metal_Block::Metal_Block(World &world,float x_pos, float y_pos, float size ,int angle){
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    block = world.addTriangle(x_pos,y_pos,size,angle,true,data);
    position = b2Vec2(x_pos + DELTA_POSITION, y_pos + DELTA_POSITION);
    this->angle = angle;
    sizes = b2Vec2(size,size);
    block->SetUserData(this);
    name = "Metal_Block";
    contact = false;
    live = true;
}

b2Vec2 Metal_Block::getPosition() {
    return position;
}

int Metal_Block::getAngle() {
    return angle;
}

b2Vec2 Metal_Block::getSizes() {
    return sizes;
}

const std::string& Metal_Block::getEntityName() {
    return name;
}

bool Metal_Block::lives() {
    return live;
}

void Metal_Block::die() {
    live = false;
}

void Metal_Block::startContact(b2Vec2) {
    contact = true;
}

void Metal_Block::endContact() {
    contact = false;
}

bool Metal_Block::setTransform(Entity *) {
    return true;
}

void Metal_Block::changePosition() {}

void Metal_Block::win(){}
