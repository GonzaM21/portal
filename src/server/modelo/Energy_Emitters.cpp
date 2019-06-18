//
// Created by gonzalo on 07/06/19.
//
#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3
#include "Energy_Emitters.h"

Energy_Emitters::Energy_Emitters(World &world, float x_pos, float y_pos, float size,int direction, bool charged,int frequency)
                                : world(world), charged(charged), step_counter(0),frequency(frequency) {
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    emitter = world.addBox(x_pos,y_pos,size/2.f,true,data);
    emitter->SetUserData(this);
    sizes = b2Vec2(size,size);
    name = "Energy_Emitter";
    this->direction = direction;
}

b2Vec2 Energy_Emitters::getPosition() {
    return emitter->GetPosition();
}

b2Vec2 Energy_Emitters::getSizes() {
    return sizes;
}

const std::string& Energy_Emitters::getEntityName() {
    return name;
}

void Energy_Emitters::startContact(b2Vec2) {
    charged = true;
}

void Energy_Emitters::endContact() {
    charged = false;
}

void Energy_Emitters::die(){}

bool Energy_Emitters::lives(){
    ++step_counter;
    return true;
}

b2Vec2 calculate_postion(b2Vec2 position,b2Vec2 sizes ,int direction){
    float x = position.x - 0.02;
    float y = position.y - 0.02;
    std::cout<< x << "  " << y <<std::endl;
    if(direction == RIGHT) x += (sizes.x/2.f + .7);
    if(direction == LEFT) x -= (sizes.x/2.f + .7); 
    if(direction == UP) y += (sizes.y/2.f + .7);   
    if(direction == DOWN) y -= (sizes.y/2.f + .7); 
    return b2Vec2(x,y);
}

void Energy_Emitters::changePosition() {
    if(!charged) return;
    if(step_counter % frequency != 0) return;
    b2Vec2 pos = calculate_postion(emitter->GetPosition(),sizes,direction);

    std::cout<<"Pos bola: "<<pos.x<<"  "<<pos.y<<std::endl;

    energy_balls.push_back(new Energy_Ball(world,pos.x,pos.y));
    if(direction == RIGHT) energy_balls[energy_balls.size()-1]->Move('R');
    if(direction == LEFT) energy_balls[energy_balls.size()-1]->Move('L');
    if(direction == UP) energy_balls[energy_balls.size()-1]->Move('U');
    if(direction == DOWN) energy_balls[energy_balls.size()-1]->Move('D');
    charged = false;
}

bool Energy_Emitters::setTransform(Entity *) {
    return true;
}

Energy_Ball* Energy_Emitters::getEnergyBallShoted() {
    if (energy_balls.size() == 0) return nullptr;
    return energy_balls[energy_balls.size()-1];
}

Energy_Emitters::~Energy_Emitters() {
    for(size_t i = 0;i < energy_balls.size();++i){
        delete energy_balls[i];
    }
}

void Energy_Emitters::startBouncing() {}

void Energy_Emitters::win(){}

int Energy_Emitters::isCharged() {
    if(charged) return 1;
    return 0;
}

int Energy_Emitters::getDirection() {
    return direction;
}