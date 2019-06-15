#include "Stone_Block.h"

Stone_Block::Stone_Block(World &world,float x_pos, float y_pos,float size){
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    block = world.addBox(x_pos,y_pos,size/2.f,true,false,data);
    angle = 90;
    name = "Stone_Block";
    sizes = b2Vec2(size,size);
}

Stone_Block::Stone_Block(World &world,float x_pos, float y_pos,float size,int angle){
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    block = world.addTriangle(x_pos,y_pos,size/2,angle,true,false,data);
    this->angle = angle;
    name = "Stone_Block";
    sizes = b2Vec2(BLOCK_SIZES,BLOCK_SIZES);
}

b2Vec2 Stone_Block::getPosition() {
    return block->GetPosition();
}

float Stone_Block::getAngle() {
    return angle;
}

b2Vec2 Stone_Block::getSizes() {
    return sizes;
}

const std::string& Stone_Block::getEntityName() {
    return name;
}

bool Stone_Block::lives() {
    return true;
}

void Stone_Block::die() {}

void Stone_Block::startContact(b2Vec2) {}

void Stone_Block::endContact() {}

bool Stone_Block::setTransform(Entity *) {
    return true;
}

void Stone_Block::changePosition() {}

void Stone_Block::startBouncing() {}
