//
// Created by gonzalo on 07/06/19.
//

#include "Energy_Emitters.h"

Energy_Emitters::Energy_Emitters(World &world, float x_pos, float y_pos, float size, std::string& direction, bool charged)
                                : world(world), charged(charged), direction(direction), step_counter(0) {
    Filter_Data data(1);
    data.addMaskBits(1);
    data.addMaskBits(2);
    data.addMaskBits(4);
    data.addMaskBits(8);
    data.addMaskBits(16);
    emitter = world.addBox(x_pos,y_pos,size/2.f,true,false,data);
    emitter->SetUserData(this);
    sizes = b2Vec2(size,size);
    std::cout<<size<<std::endl;
    name = "Energy_Emitter";
}

b2Vec2 Energy_Emitters::getPosition() {
    return emitter->GetPosition();
}

b2Vec2 Energy_Emitters::getSizes() {
    return sizes;
}

std::string Energy_Emitters::getEntityName() {
    return name;
}

void Energy_Emitters::startContact(b2Vec2 pos) {
    charged = true;
    printf("Energy emitter cargadooooooo\n");
}

void Energy_Emitters::endContact() {
    charged = false;
}

void Energy_Emitters::die(){}

bool Energy_Emitters::lives(){
    ++step_counter;
    return true;
}

b2Vec2 calculate_postion(b2Vec2 position,b2Vec2 sizes ,std::string& direction){
    float x = position.x - 0.02;
    float y = position.y - 0.02;
    if(direction == "Right") x += (sizes.x/2.f + .7);
    if(direction == "Left") x -= (sizes.x/2.f + .7);
    if(direction == "Up") y += (sizes.y/2.f + .7);
    if(direction == "Down") y -= (sizes.y/2.f + .7);

    std::cout<<"Nueva position: "<<x<<"     "<<y<<std::endl;
    return b2Vec2(x,y);
}

void Energy_Emitters::changePosition() {
    if(!charged) return;
    if(step_counter % 10 != 0) return;
    b2Vec2 pos = calculate_postion(emitter->GetPosition(),sizes,direction);

    printf("Disparandoooooooooooooooooooooooooooooooooo\n");
    energy_balls.push_back(new Energy_Ball(world,pos.x,pos.y));
    if(direction == "Right") energy_balls[energy_balls.size()-1]->Move('R');
    if(direction == "Left") energy_balls[energy_balls.size()-1]->Move('L');
    if(direction == "Up") energy_balls[energy_balls.size()-1]->Move('U');
    if(direction == "Down") energy_balls[energy_balls.size()-1]->Move('D');
    charged = false;
}

bool Energy_Emitters::setTransform(Entity *body) {
    return true;
}

Energy_Ball Energy_Emitters::getEnergyBallShoted() {
    return *energy_balls[energy_balls.size()-1];
}

Energy_Emitters::~Energy_Emitters() {
    for(int i = 0;i < energy_balls.size();++i){
        delete energy_balls[i];
    }
}