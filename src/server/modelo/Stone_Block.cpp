#include "Stone_Block.h"

Stone_Block::Stone_Block(World &world,float x_pos, float y_pos, float size){
    block = world.World_Add_Box(x_pos,y_pos,size,true,false);
}

Stone_Block::Stone_Block(World &world,float x_pos, float y_pos, float x_size, float y_size){
    block = world.World_Add_Triangle(x_pos,y_pos,x_size,y_size,true,false);
}