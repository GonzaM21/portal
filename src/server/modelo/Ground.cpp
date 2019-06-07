#include "Ground.h"
#include "Macros.h"

Ground::Ground(World &world,float x_pos, float y_pos, float x_size, float y_size){
    ground = world.World_Add_Polygon(x_pos - DELTA_POSITION,y_pos - DELTA_POSITION,x_size,y_size,true);
}