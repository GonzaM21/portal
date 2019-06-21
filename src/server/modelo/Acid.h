#ifndef TP4_ACID_H
#define TP4_ACID_H

#include "World.h"
#include "Entity.h"

class Acid : public Entity {
    b2Body * acid;
    World & world;
    std::string name;
    bool contact;
    bool live;
    b2Vec2 sizes;
public:
    Acid(World & world,float x_pos, float y_pos,float large);

    //Retorna el nombre de la clase
    const std::string& getEntityName() override;
    //Setea el contract en true
    void startContact(b2Vec2) override;
    //setea contact en false
    void endContact()override;
    //No hace nada
    void die() override;
    //retiorna si el acido esta vivo
    bool lives() override;
    //No hace nada
    bool setTransform(Entity *) override;
    //no hace nada
    void changePosition() override;
    //devuelve la posicion en el mundo
    b2Vec2 getPosition();
    //devuelve su tamano en (x,y)
    b2Vec2 getSizes();
    //no hace nada
    void win();
    //destructor por defecto
    ~Acid() = default;
};
#endif
