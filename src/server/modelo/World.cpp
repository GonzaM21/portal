#include <iostream>
#include "World.h"
#include "Box2D/Box2D.h"
#include "InvalidPosition.h"
#include "MyContactListener.h"
#include "Macros.h"

World::World(b2Vec2 gravity,b2Vec2 x_lim, b2Vec2 y_lim){
    world = new b2World(gravity);
    ContactListener = new MyContactListener;
    world->SetContactListener(ContactListener);
    this->x_lim = x_lim + b2Vec2(1,-1);
    this->y_lim = y_lim + b2Vec2(1,-1);
    addGroundWallsRoof();
}

void World::addGroundWallsRoof() {
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    addPolygon(ZERO,y_lim.x - DELTA_WALLS ,x_lim.x, DELTA_WALLS ,true,data);
    addPolygon(ZERO,y_lim.y + DELTA_WALLS,x_lim.x,DELTA_WALLS,true,data);
    addPolygon(x_lim.x - DELTA_WALLS,ZERO,DELTA_WALLS,x_lim.x,true,data);
    addPolygon(x_lim.y + DELTA_WALLS,ZERO,DELTA_WALLS,x_lim.x,true,data);

}

bool World::validPosition(float x_pos, float y_pos) {
    if (x_pos > x_lim.x || x_pos < x_lim.y){
        return false;
    }
    if (y_pos > y_lim.x || y_pos < y_lim.y) {
        return false;
    }
    for(size_t i = 0; i < Bodies.size(); ++i){
        b2Vec2 pos_item = Bodies[i]->GetPosition();
        if(pos_item.x == x_pos && pos_item.y == y_pos){
            return false;
        }
    }
    return true;
}

b2Body* World::addPolygon(float x_pos, float y_pos,float x_size, float y_size,bool static_obj,Filter_Data & data) {
    b2Body* polygonBody;
    b2BodyDef polygonBodyDef;
    b2FixtureDef polygonFixtureDef;

    polygonBodyDef.type = static_obj ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;

    if (!validPosition(x_pos,y_pos)){
        throw InvalidPosition();
    }
    polygonBodyDef.position = b2Vec2(x_pos + DELTA_POSITION, y_pos + DELTA_POSITION);
    polygonBody = world->CreateBody(&polygonBodyDef);
    b2PolygonShape shape_ground;
    shape_ground.SetAsBox(x_size,y_size);
    polygonFixtureDef.shape = &shape_ground;
    polygonFixtureDef.density = DENSITY;
    polygonFixtureDef.friction = FRICTION;
    polygonFixtureDef.filter.categoryBits = data.getCategoryBits();
    polygonFixtureDef.filter.maskBits = data.getMaskBits();
    polygonBody->SetFixedRotation(true);
    polygonBody->CreateFixture(&polygonFixtureDef);
    Bodies.push_back(polygonBody);
    return polygonBody;
}

b2Body* World::addBox(float x_pos, float y_pos,float size,bool static_obj,bool metal,Filter_Data & data){
    b2Body* boxBody;
    b2BodyDef boxBodyDef;
    b2FixtureDef boxFixtureDef;

    boxBodyDef.type = static_obj ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;

    if (!validPosition(x_pos,y_pos)){
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
    boxFixtureDef.filter.categoryBits = data.getCategoryBits();
    boxFixtureDef.filter.maskBits = data.getMaskBits();
    boxBody->CreateFixture(&boxFixtureDef);
    Bodies.push_back(boxBody);
    return boxBody;
}

b2Body* World::addCircle(float x_pos, float y_pos,float radius, bool static_obj,Filter_Data & data) {
    b2Body * circleBody;
    b2BodyDef circleBodyDef;
    b2FixtureDef circleFixtureDef;

    circleBodyDef.type = static_obj ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;

    if (!validPosition(x_pos,y_pos)){
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
    circleFixtureDef.filter.categoryBits = data.getCategoryBits();
    circleFixtureDef.filter.maskBits = data.getMaskBits();
    circleBody->CreateFixture(&circleFixtureDef);
    Bodies.push_back(circleBody);
    return circleBody;
}

b2Body* World::addTriangle(float x_pos, float y_pos, float x_size, float y_size, bool static_obj,bool metal,Filter_Data & data){
    b2Body* triangleBody;
    b2BodyDef triangleBodyDef;
    b2FixtureDef triangleFixtureDef;

    triangleBodyDef.type = static_obj ? b2BodyType::b2_staticBody : b2BodyType::b2_dynamicBody;

    if (!validPosition(x_pos,y_pos)){
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
    triangleFixtureDef.filter.categoryBits = data.getCategoryBits();
    triangleFixtureDef.filter.maskBits = data.getMaskBits();
    triangleBody->CreateFixture(&triangleFixtureDef);
    Bodies.push_back(triangleBody);
    return triangleBody;
}

void World::Step(float time, int velocity, int position){
    deleteBodies();
    moveBodies();
    world->Step(time, velocity, position);
}

void World::moveBodies(){
    for(size_t i = 0; i < Bodies.size(); ++i) {
        if (Bodies[i]->GetUserData()) {
            static_cast<Entity *>(Bodies[i]->GetUserData())->changePosition();
        }
    }
}

void World::eraseBody(b2Body *body) {
    for(size_t i = 0; i < Bodies.size(); ++i) {
        if (Bodies[i] == body) {
            world->DestroyBody(Bodies[i]);
            Bodies.erase(Bodies.begin() + i);
        }
    }
}

bool World::deleteBodies(){

    //std::cout<<"bodies sizes: "<<Bodies.size()<<std::endl;
    for(size_t i = 0; i < Bodies.size(); ++i) {
        if (Bodies[i]->GetUserData()) {
            //std::cout<<"Nombre: "<<static_cast<Entity *>(Bodies[i]->GetUserData())->getEntityName()<<std::endl;
            if (!static_cast<Entity *>(Bodies[i]->GetUserData())->lives()) {
                //std::cout<<"Mato a "<<static_cast<Entity *>(Bodies[i]->GetUserData())->getEntityName()<<std::endl;
                world->DestroyBody(Bodies[i]);
                Bodies.erase(Bodies.begin() + i);
                return true;
            }
        }
    }
    return false;
}

World::~World() {
    delete ContactListener;
    delete world;
}

b2Vec2 World::getWidth() {
    return x_lim;
}

b2Vec2 World::getHigh() {
    return y_lim;
}
