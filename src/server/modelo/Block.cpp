#include "Block.h"
#include "World.h"

Block::Block(World &world,float x_pos, float y_pos, float size){
    block = world.World_Add_Polygon(x_pos,y_pos,size,size,true);
}

Block::Block(World &world,float x_pos, float y_pos, float x_size, float y_size){
    block = world.World_Add_Triangle(x_pos,y_pos,x_size,y_size,true,true);
}
