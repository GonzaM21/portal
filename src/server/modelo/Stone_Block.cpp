#include "Stone_Block.h"

Stone_Block::Stone_Block(World &world,float x_pos, float y_pos,float size){
    Filter_Data data(0);
    data.addMaskBits(2);
    data.addMaskBits(4);
    data.addMaskBits(8);
    data.addMaskBits(16);
    block = world.addBox(x_pos,y_pos,size/2.f,true,false,data);
    angle = 0; //HAY QUE CAMBIARLO
    sizes = b2Vec2(size,size);
}

Stone_Block::Stone_Block(World &world,float x_pos, float y_pos,float size,float angle){
    Filter_Data data(0);
    data.addMaskBits(2);
    data.addMaskBits(4);
    data.addMaskBits(8);
    data.addMaskBits(16);
    block = world.addTriangle(x_pos,y_pos,size/2,size/2,true,false,data);
    angle = 0; //HAY QUE CAMBIARLO
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
