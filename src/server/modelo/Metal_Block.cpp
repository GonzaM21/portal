#include "Metal_Block.h"

Metal_Block::Metal_Block(World &world,float x_pos, float y_pos,float size){
    Filter_Data data(1);
    data.addMaskBits(2);
    data.addMaskBits(4);
    data.addMaskBits(8);
    data.addMaskBits(16);
    block = world.addBox(x_pos,y_pos,size/2.f,true,true,data);
    angle = 0;
    sizes = b2Vec2(size,size);
    block->SetUserData(this);
    name = "Metal_Block";
    contact = false;
    live = true;
}

Metal_Block::Metal_Block(World &world,float x_pos, float y_pos, float size ,float angle){
    Filter_Data data(1);
    data.addMaskBits(2);
    data.addMaskBits(4);
    data.addMaskBits(8);
    data.addMaskBits(16);
    block = world.addTriangle(x_pos,y_pos,size/2.f,size/2.f,true,true,data);
    angle = 0; //HAY QUE CAMBIARLO
    sizes = b2Vec2(size,size);
    block->SetUserData(this);
    name = "Metal_Block";
    contact = false;
    live = true;
}

b2Vec2 Metal_Block::getPosition() {
    return block->GetPosition();
}

float Metal_Block::getAngle() {
    return angle;
}

b2Vec2 Metal_Block::getSizes() {
    return sizes;
}

std::string Metal_Block::getEntityName() {
    return name;
}

bool Metal_Block::lives() {
    return live;
}

void Metal_Block::die() {
    live = false;
}

void Metal_Block::startContact(b2Vec2 pos) {
    contact = true;
}

void Metal_Block::endContact() {
    contact = false;
}

bool Metal_Block::setTransform(Entity *body) {
    return true;
}

void Metal_Block::changePosition() {}
