#ifndef TP4_CAKE_H
#define TP4_CAKE_H

#include "World.h"

class Cake : public Entity {
    b2Body *  cake;
    std::string name;
    b2Vec2 sizes;
public:
    Cake(World & world, float x_pos, float y_pos);
    const std::string& getEntityName() override;
    void startContact(b2Vec2) override;
    void endContact()override;
    void die() override;
    bool lives() override;
    bool setTransform(Entity *) override;
    void changePosition() override;
    void startBouncing() override ;
    void win();
    b2Vec2 getPosition();
    b2Vec2 getSizes();
    ~Cake() = default;

};


#endif
