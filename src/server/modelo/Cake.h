#ifndef TP4_CAKE_H
#define TP4_CAKE_H

#include "World.h"

class Cake : public Entity {
    b2Body *  cake;
    std::string name;
    b2Vec2 sizes;
public:
    //Contrcutor
    Cake(World & world, float x_pos, float y_pos);
    //devuelve el nombre de la clase
    const std::string& getEntityName() override;
    //no hace nada
    void startContact(b2Vec2) override;
    //no hace nada
    void endContact()override;
    //no hace nada
    void die() override;
    //deuelve true, nunca muere
    bool lives() override;
    //no hace nada
    bool setTransform(Entity *) override;
    //no hace nada
    void changePosition() override;
    //no hace nada
    void win();
    //devuelve la posicion en el mundo (x,y)
    b2Vec2 getPosition();
    //devuelve su tamalo (x,y)
    b2Vec2 getSizes();
    //destrcutor por defecto
    ~Cake() = default;

};


#endif
