#include "Metal_Block.h"

Metal_Block::Metal_Block(World &world,float x_pos, float y_pos, float size){
    block = world.World_Add_Box(x_pos,y_pos,size,true,true);
    this->size = size;
}

Metal_Block::Metal_Block(World &world,float x_pos, float y_pos, float x_size, float y_size){
    block = world.World_Add_Triangle(x_pos,y_pos,x_size,y_size,true,true);
}

b2Vec2 Metal_Block::Get_Position() {
    return block->GetPosition();
}

float Metal_Block::Get_Angle() {
    return block->GetAngle();
}

float Metal_Block::Get_Size() {
    return this->size;
}
