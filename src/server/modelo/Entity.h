#ifndef TP4_ENTITY_H
#define TP4_ENTITY_H

//Clase creada para saber cuando 2 objetos interactuan entre si.

class Entity{
public:
    //virtual Entity* getEntityType() = 0;
    virtual std::string Get_Entity_Name() = 0;
    virtual void Start_Contact() = 0;
    virtual void End_Contact() = 0;
    virtual void Die() = 0;
    virtual bool Lives() = 0;
};
#endif
