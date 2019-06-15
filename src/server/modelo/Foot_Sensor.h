#ifndef TP4_FOOT_SENSOR_H
#define TP4_FOOT_SENSOR_H

#include "World.h"
#include "Entity.h"

class Foot_Sensor : public Entity {
    Entity * chell;
    std::string name;
public:
    explicit Foot_Sensor(Entity * chell_player);
    const std::string& getEntityName() override;
    void startContact(b2Vec2 pos) override;
    void endContact()override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity *) override;
    void changePosition() override;
    void startBouncing() override ;

};


#endif //TP4_FOOT_SENSOR_H
