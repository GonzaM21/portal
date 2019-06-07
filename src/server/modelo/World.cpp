#include <iostream>
#include "World.h"
#include "Box2D/Box2D.h"
#include "InvalidPosition.h"
#include "MyContactListener.h"
#include "Macros.h"

/*World::World(){
    world = new b2World(b2Vec2(ZERO,GRAVITY));
    ContactListener = new MyContactListener;
    world->SetContactListener(ContactListener);
    this->x_lim = b2Vec2(MAX_LIM + 1,-MAX_LIM - 1);
    this->y_lim = b2Vec2(MAX_LIM + 1,-MAX_LIM - 1);
    World_Add_Ground_Walls_Roof();
}*/

World::World(b2Vec2 gravity,b2Vec2 x_lim, b2Vec2 y_lim){
    world = new b2World(gravity);
    ContactListener = new MyContactListener;
    world->SetContactListener(ContactListener);
    this->x_lim = x_lim + b2Vec2(1,-1);
    this->y_lim = y_lim + b2Vec2(1,-1);
    World_Add_Ground_Walls_Roof();
}

void World::World_Add_Ground_Walls_Roof() {
    //std::cout<<"wALL 1\n";
    Bodies.push_back(World_Add_Polygon(ZERO,y_lim.x - DELTA_WALLS ,x_lim.x, DELTA_WALLS ,true));
    //std::cout<<"wALL 2\n";
    Bodies.push_back(World_Add_Polygon(ZERO,y_lim.y + DELTA_WALLS,x_lim.x,DELTA_WALLS,true));
    //std::cout<<"wALL 3\n";
    Bodies.push_back(World_Add_Polygon(x_lim.x - DELTA_WALLS,ZERO,DELTA_WALLS,x_lim.x,true));
    //std::cout<<"wALL 4\n";
    Bodies.push_back(World_Add_Polygon(x_lim.y + DELTA_WALLS,ZERO,DELTA_WALLS,x_lim.x,true));
    //std::cout<<"fin\n";

}

bool World::Valid_Position(float x_pos, float y_pos) {

    std::cout<<"x pos: "<<x_pos<<" x_lim_x: "<<x_lim.x<<" x_lim_y: "<<x_lim.y<<std::endl;
    std::cout<<"y pos: "<<y_pos<<" y_lim_x: "<<y_lim.x<<" y_lim_y: "<<y_lim.y<<std::endl;

    if (x_pos > x_lim.x || x_pos < x_lim.y){
        return false;
    }
    if (y_pos > y_lim.x || y_pos < y_lim.y) {
        return false;
    }
    for(int i = 0; i < Bodies.size(); ++i){
        b2Vec2 pos_item = Bodies[i]->GetPosition();
        if(pos_item.x == x_pos && pos_item.y == y_pos){
            return false;
        }
    }
    return true;
}

b2Body* World::World_Add_Polygon(float x_pos, float y_pos,float x_size, float y_size,bool static_obj) {
    b2Body* polygonBody;
    b2BodyDef polygonBodyDef;
    b2FixtureDef polygonFixtureDef;

    polygonBodyDef.type = static_obj ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;

    if (!Valid_Position(x_pos,y_pos)){
        throw InvalidPosition();
    }
    polygonBodyDef.position = b2Vec2(x_pos + DELTA_POSITION, y_pos + DELTA_POSITION);
    polygonBody = world->CreateBody(&polygonBodyDef);
    b2PolygonShape shape_ground;
    shape_ground.SetAsBox(x_size,y_size);
    polygonFixtureDef.shape = &shape_ground;
    polygonFixtureDef.density = DENSITY;
    polygonFixtureDef.friction = FRICTION;
    polygonBody->SetFixedRotation(true);
    polygonBody->CreateFixture(&polygonFixtureDef);
    Bodies.push_back(polygonBody);
    return polygonBody;
}

b2Body* World::World_Add_Box(float x_pos, float y_pos,float size,bool static_obj,bool metal){
    b2Body* boxBody;
    b2BodyDef boxBodyDef;
    b2FixtureDef boxFixtureDef;

    boxBodyDef.type = static_obj ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;

    if (!Valid_Position(x_pos,y_pos)){
        throw InvalidPosition();
    }
    boxBodyDef.position = b2Vec2(x_pos + DELTA_POSITION,y_pos + DELTA_POSITION);
    boxBody = world->CreateBody(&boxBodyDef);
    b2PolygonShape shape_ground;
    shape_ground.SetAsBox(size,size);
    boxFixtureDef.shape = &shape_ground;
    boxFixtureDef.density = DENSITY;
    boxFixtureDef.friction = FRICTION;
    boxFixtureDef.restitution = metal ? METAL_RESITUTION : ZERO;
    boxBody->SetFixedRotation(true);
    boxBody->CreateFixture(&boxFixtureDef);
    Bodies.push_back(boxBody);
    return boxBody;
}

b2Body* World::World_Add_Circle(float x_pos, float y_pos,float radius, bool static_obj) {
    b2Body * circleBody;
    b2BodyDef circleBodyDef;
    b2FixtureDef circleFixtureDef;

    circleBodyDef.type = static_obj ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;

    if (!Valid_Position(x_pos,y_pos)){
        throw InvalidPosition();
    }
    circleBodyDef.position = b2Vec2(x_pos + DELTA_POSITION,y_pos + DELTA_POSITION);

    circleBody = world->CreateBody(&circleBodyDef);

    b2CircleShape shape_circle;
    shape_circle.m_radius = radius;
    circleFixtureDef.shape = &shape_circle;
    circleFixtureDef.density = DENSITY;
    circleFixtureDef.friction = FRICTION;
    circleFixtureDef.restitution = ZERO;
    circleBody->CreateFixture(&circleFixtureDef);
    return circleBody;
}

b2Body* World::World_Add_Triangle(float x_pos, float y_pos, float x_size, float y_size, bool static_obj,bool metal){
    b2Body* triangleBody;
    b2BodyDef triangleBodyDef;
    b2FixtureDef triangleFixtureDef;

    triangleBodyDef.type = static_obj ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;

    if (!Valid_Position(x_pos,y_pos)){
        throw InvalidPosition();
    }
    triangleBodyDef.position = b2Vec2(x_pos + DELTA_POSITION,y_pos + DELTA_POSITION);
    triangleBody = world->CreateBody(&triangleBodyDef);
    b2PolygonShape shape_triangle;
    b2Vec2 vertices[3];
    vertices[0].Set(x_size,0);
    vertices[1].Set(0,y_size);
    vertices[2].Set(x_size,y_size);
    shape_triangle.Set(vertices,3);
    triangleFixtureDef.shape = &shape_triangle;
    triangleFixtureDef.density = DENSITY;
    triangleFixtureDef.friction = FRICTION;
    triangleFixtureDef.restitution = metal ? METAL_RESITUTION : ZERO;
    triangleBody->CreateFixture(&triangleFixtureDef);
    Bodies.push_back(triangleBody);
    return triangleBody;
}

void World::WorldStep(float time, int velocity, int position){
    Delete_Bodies();
    world->Step(time, velocity, position);
}


bool World::Delete_Bodies(){
    for(int i = 0; i < Bodies.size(); ++i) {
        if (Bodies[i]->GetUserData()) {
            //std::cout<<"Con data "<<static_cast<Entity *>(Bodies[i]->GetUserData())->Get_Entity_Name()<<std::endl;
            if (!static_cast<Entity *>(Bodies[i]->GetUserData())->Lives()) {
                std::cout<<"Matar\n";
                world->DestroyBody(Bodies[i]);
                Bodies.erase(Bodies.begin() + i);
                return true;
            }
        }
    }
    return false;
}

b2Vec2 World :: getWidth() {
    return x_lim;
}

b2Vec2 World :: getHigh() {
    return y_lim;
}

World::~World() {
    delete ContactListener;
    delete world;
}
