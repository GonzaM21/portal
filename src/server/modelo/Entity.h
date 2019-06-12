#ifndef TP4_ENTITY_H
#define TP4_ENTITY_H

//Clase creada para saber cuando 2 objetos interactuan entre si.

class Entity{
public:
    virtual std::string getEntityName() = 0;
    virtual void startContact(b2Vec2) = 0;
    virtual void endContact() = 0;
    virtual void die() = 0;
    virtual bool lives() = 0;
    virtual bool setTransform(Entity *) = 0;
    virtual void changePosition() = 0;
};
#endif
