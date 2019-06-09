#include "Portal.h"
#include "Macros.h"

Portal::Portal(World& world, float x_pos, float y_pos): world(world) {
    Filter_Data data(8);
    data.addMaskBits(1);
    data.addMaskBits(4);
    data.addMaskBits(16);
    portal = world.addCircle(x_pos,y_pos,ENERGY_BALL,false,data);
    portal->SetGravityScale(0);
    portal->SetUserData(this);
    contact = false;
    have_partner = false;
    name = "Portal";
    live = true;
    position = portal->GetPosition();
    radius = ENERGY_BALL;
    sizes = b2Vec2(0.02,1);
}

bool Portal::Move(float x_pos, float y_pos){
    std::cout<<"pos: "<<x_pos<<" "<<y_pos<<std::endl;
    b2Vec2 position = portal->GetPosition();
    std::cout<<"pos: "<<position.x<<" "<<position.y<<std::endl;
    float x = (x_pos * position.x);
    std::cout<<"X: "<<x<<std::endl;
    float y = (y_pos * position.y);
    std::cout<<"Y: "<<y<<std::endl;
    float u1 = sqrt(x_pos*x_pos + y_pos*y_pos);
    std::cout<<"u1: "<<u1<<std::endl;
    float u2 = sqrt(position.x*position.x + position.y*position.y);
    std::cout<<"u2: "<<u2<<std::endl;
    float result = (x + y) /(u1 * u2);

    std::cout<<"resultado: "<<result<<std::endl;

    float angle = acos(result);

    std::cout<<"angulo: "<<angle<<std::endl;
    float x_force = 5.f;
    float y_force = 5.f;
    if (x_pos < position.x) x_force = -5.f;
    if (y_pos < position.y) y_force = -5.f;

    //std::cout<<"Portal force: "<<x_force * sin(angle)<<"  "<<y_force * cos(angle)<<std::endl;
    //portal->SetLinearVelocity(b2Vec2(x_force * sin(angle),y_force * cos(angle)));
    portal->SetLinearVelocity(b2Vec2(x_force,0));
    std::cout<<std::endl;
    return false;
}

void Portal::changePosition() {
    std::cout<<"change position\n";
    if(!contact) return;
    std::cout<<"change position2\n";
    if(contact){
        std::cout<<"change position3\n";
        portal->SetLinearVelocity(b2Vec2(0,0));
        world.eraseBody(portal);
        Filter_Data data(8);
        data.addMaskBits(1);
        data.addMaskBits(2);
        data.addMaskBits(8);
        portal = world.addPolygon(position.x,position.y,0.01,0.5f,true,data);
        portal->SetUserData(this);
        contact = false;
        live = true;
    }
    portal->SetLinearVelocity(b2Vec2(0,0));
}

b2Vec2 Portal::getPosition(){
    std::cout<<"portal vido: "<<live<<std::endl;
    if(!live) return b2Vec2(0,0);
    std::cout<<"Portal vel: "<<portal->GetLinearVelocity().x<<" "<<portal->GetLinearVelocity().y<<std::endl;
    return portal->GetPosition();
}

float Portal::getAngle() {
    if(!live) return 0;
    return portal->GetAngle();
}

void Portal::startContact(b2Vec2 pos) {
    contact = true;
    //live = false;
    if(portal->GetLinearVelocity().x < 0) position = pos + b2Vec2(0.5,0);
    if(portal->GetLinearVelocity().x > 0) position = pos - b2Vec2(0.5,0);

    std::cout<<"Otro cuerpo"<<pos.x<<" "<<pos.y<<std::endl;
    std::cout<<"Nueva pos"<<position.x<<" "<<position.y<<std::endl;
    portal->SetLinearVelocity(b2Vec2(0,0));
}

void Portal::endContact() {
    contact = false;
}

std::string Portal::getEntityName() {
    return name;
}

void Portal::die() {
    live = false;
}

bool Portal::lives(){
    return live;
}

bool Portal::setPartner(Portal *portal) {
    partner = portal;
    have_partner = true;
    return true;
}

Portal * Portal::getPartnerPortal() {
    if(!partner) return nullptr;
    return partner;
}

bool Portal::changePortalPosition(float x_pos, float y_pos) {
    if(!world.validPosition(x_pos,y_pos)) return false;
    std::cout<<"Change portal position\n";
    world.eraseBody(portal);
    Filter_Data data(8);
    data.addMaskBits(1);
    data.addMaskBits(4);
    data.addMaskBits(16);
    portal = portal = world.addCircle(x_pos,y_pos,ENERGY_BALL,false,data);
    portal->SetGravityScale(0);
    portal->SetUserData(this);
    contact = false;
    return true;
}

bool Portal::havePartner() {
    return have_partner;
}

float Portal::getradius() {
    return radius;
}

b2Vec2 Portal::getSizes() {
    return sizes;
}

bool Portal::setTransform(Entity * body){
    return true;
}