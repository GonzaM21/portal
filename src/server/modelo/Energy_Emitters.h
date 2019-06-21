#ifndef TP4_ENERGY_EMITTERS_H
#define TP4_ENERGY_EMITTERS_H

#include "World.h"
#include "Entity.h"
#include "Energy_Ball.h"

class Energy_Emitters : public Entity{
    World & world;
    b2Body * emitter;
    bool charged;
    b2Vec2 sizes;
    int direction;
    std::string name;
    int step_counter;
    int frequency;
    std::vector<Energy_Ball *> energy_balls;
public:
    //Constructor
    Energy_Emitters(World & world, float x_pos, float y_pos, float size,int direction, bool charged, int frequency = 50);
    //Retorna su posicion en el mundo (x,y)
    b2Vec2 getPosition();
    //retrona su tamaño (x,y)
    b2Vec2 getSizes();
    //retorna su direccion al cual sale el disparo
    int getDirection();
    //retorna si esta cargada
    int isCharged();
    //retorna el nombre de la clase
    const std::string& getEntityName() override;
    //si es tocada por una bola de energia, es cargada
    void startContact(b2Vec2) override;
    //se descarga cuando dispara
    void endContact() override;
    //no hace nada
    void die() override;
    //retorna true, nunca muere
    bool lives() override;
    //no hace nada
    bool setTransform(Entity *) override;
    ///en caso de pasar la cantidad de step dispara una bola de energia
    void changePosition() override;
    //no hace nada
    void win() override;
    //retorna la ultima bola de energia disparada
    Energy_Ball* getEnergyBallShoted();
    //destructor
    ~Energy_Emitters();
};


#endif
