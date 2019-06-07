
#ifndef TP4_WORLD_H
#define TP4_WORLD_H

#include <vector>
#include "Box2D/Box2D.h"
#include "MyContactListener.h"
#include "Macros.h"


class World {
    b2World* world;
    MyContactListener * ContactListener;
    std::vector<b2Body*> Bodies;
    b2Vec2 x_lim;
    b2Vec2 y_lim;

    //Metodo para crear paderes, piso y techo con los limites del mundo.
    void World_Add_Ground_Walls_Roof();
public:

    //World();
    //Contructor del mundo, en caso de preferencia se puede poner limites al mundo o cambiar la gravedad
    World(b2Vec2 gravity = b2Vec2(ZERO,-GRAVITY),b2Vec2 x_lim = b2Vec2(MAX_LIM,-MAX_LIM), b2Vec2 y_lim = b2Vec2(MAX_LIM,-MAX_LIM));

    //Crea y agrega un polygono al mundo
    b2Body* World_Add_Polygon(float x_pos, float y_pos,float x_size, float y_size,bool static_obj);

    //crea y agrega una caja al mundo
    b2Body* World_Add_Box(float x_pos, float y_pos,float size, bool static_obj,bool metal);

    //crea y agrega un circulo al mundo
    b2Body* World_Add_Circle(float x_pos,float y_pos, float radius, bool static_obj);

    //crea y agrega un triangulo al mundo
    b2Body* World_Add_Triangle(float x_pos, float y_pos, float x_size, float y_size, bool static_obj,bool metal);

    //Para que el mundo se "mueva" es necesario llamar a este metodo
    void WorldStep(float time = 1.f/60.f, int velocity = 10, int position = 10);

    //Metodo para validar posiciones, y los objetos no se creen fuera de los limites o se superpongan
    bool Valid_Position(float x_pos, float y_pos);

    bool Delete_Bodies();

    b2Vec2 getWidth();

    b2Vec2 getHigh();

    //Destructor
    ~World();
};
#endif
