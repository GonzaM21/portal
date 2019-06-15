#ifndef TP4_ENTITY_H
#define TP4_ENTITY_H

//Clase creada para saber cuando 2 objetos interactuan entre si.

class Entity{
public:
    virtual const std::string& getEntityName() = 0;
    virtual void startContact(b2Vec2 pos) = 0;
    virtual void endContact() = 0;
    virtual void die() = 0;
    virtual bool lives() = 0;
    virtual bool setTransform(Entity * body) = 0;
    virtual void changePosition() = 0;
    virtual void startBouncing() = 0;
    virtual ~Entity() = default;
};
#endif
