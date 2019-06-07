#ifndef TP4_MYCONTACTLISTENER_H
#define TP4_MYCONTACTLISTENER_H

#include <iostream>
#include "Box2D/Box2D.h"
#include "Entity.h"

class MyContactListener : public b2ContactListener{
    void BeginContact(b2Contact * contact) override;
    void EndContact(b2Contact* contact) override;
};
#endif