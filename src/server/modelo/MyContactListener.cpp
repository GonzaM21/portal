#include "MyContactListener.h"

void chell_validation(Entity * bodyA, Entity * bodyB){

    std::string nameBodyA = (bodyA)->getEntityName();
    std::string nameBodyB = (bodyB)->getEntityName();

    if(nameBodyA == "Chell_Player" && nameBodyB == "Portal") bodyA->setTransform(bodyB);
    if(nameBodyA == "Chell_Player" && nameBodyB == "Energy_Ball") bodyA->die();
    if(nameBodyA == "Chell_Player" && nameBodyB == "Acid") bodyA->die();

    if(nameBodyB == "Chell_Player" && nameBodyA == "Portal") bodyB->setTransform(bodyB);
    if(nameBodyB == "Chell_Player" && nameBodyA == "Energy_Ball") bodyB->die();
    if(nameBodyB == "Chell_Player" && nameBodyA == "Acid") bodyB->die();
}

void chell_colitions(b2Body * bodyA,b2Body * bodyB){

    void * userDataA = static_cast<Entity *>(bodyA->GetUserData());
    void * userDataB = static_cast<Entity *>(bodyB->GetUserData());

    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();

    std::cout<<"Colisionaron "<<nameBodyA<<" con "<<nameBodyB<<std::endl;

    if(nameBodyA != "Chell_Player" && nameBodyB != "Chell_Player") return;

    if(nameBodyA == "Chell_Player" && (nameBodyB == "Ground" || nameBodyB == "Bottom")){
        static_cast<Entity *>(userDataA)->startContact(bodyB->GetPosition());
    }

    if(nameBodyA == "Chell_Player" && (nameBodyB == "Metal_Block" || nameBodyB == "Stone_Block")){
        static_cast<Entity *>(userDataA)->startContact(bodyB->GetPosition());
    }

    if(nameBodyB == "Chell_Player" && (nameBodyA == "Ground" || nameBodyA == "Bottom")){
        static_cast<Entity *>(userDataB)->startContact(bodyA->GetPosition());
    }

    if(nameBodyB == "Chell_Player" && (nameBodyA == "Metal_Block" || nameBodyA == "Stone_Block")){
        static_cast<Entity *>(userDataB)->startContact(bodyA->GetPosition());
    }

    chell_validation(static_cast<Entity *>(userDataA),static_cast<Entity *>(userDataB));

}

void portal_colitions(b2Body * bodyA,b2Body * bodyB){
    void * userDataA = static_cast<Entity *>(bodyA->GetUserData());
    void * userDataB = static_cast<Entity *>(bodyB->GetUserData());

    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();

    if(nameBodyA != "Portal" && nameBodyB != "Portal") return;

    if(nameBodyA == "Portal" && (nameBodyB == "Metal_Block" || nameBodyB == "Ground")){
        static_cast<Entity *>(userDataA)->startContact(bodyB->GetPosition());
    }

    if(nameBodyB == "Portal" && (nameBodyA == "Metal_Block" || nameBodyA == "Ground")){
        static_cast<Entity *>(userDataB)->startContact(bodyA->GetPosition());
    }
}

void bottom_colitions(b2Body * bodyA,b2Body * bodyB){
    void * userDataA = static_cast<Entity *>(bodyA->GetUserData());
    void * userDataB = static_cast<Entity *>(bodyB->GetUserData());

    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();

    if(nameBodyA != "Bottom" && nameBodyB != "Bottom") return;

    if(nameBodyA == "Bottom" && (nameBodyB == "Rock" || nameBodyB == "Chell_Player")){
        static_cast<Entity *>(userDataA)->startContact(bodyB->GetPosition());
    }

    if(nameBodyB == "Bottom" && (nameBodyA == "Rock" || nameBodyA == "Chell_Player")){
        static_cast<Entity *>(userDataB)->startContact(bodyA->GetPosition());
    }
}

void MyContactListener::BeginContact(b2Contact * contact){
    printf("bg 1\n");
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    printf("bg 2\n");
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
    printf("bg 3\n");
    if(bodyUserDataA){
        if(static_cast<Entity *>(bodyUserDataA)->getEntityName() == "Chell_Player"){
            if(!bodyUserDataB) static_cast<Entity *>(bodyUserDataA)->startContact(b2Vec2(0,0));
        }
    }

    if(bodyUserDataB){
        if(static_cast<Entity *>(bodyUserDataB)->getEntityName() == "Chell_Player"){
            if(!bodyUserDataA) static_cast<Entity *>(bodyUserDataB)->startContact(b2Vec2(0,0));
        }
    }

    if (!bodyUserDataA || !bodyUserDataB) return;
    chell_colitions(contact->GetFixtureA()->GetBody(),contact->GetFixtureB()->GetBody());
    portal_colitions(contact->GetFixtureA()->GetBody(),contact->GetFixtureB()->GetBody());
    bottom_colitions(contact->GetFixtureA()->GetBody(),contact->GetFixtureB()->GetBody());
}

void chell_endContact(void * userDataA, void * userDataB){
    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();

    std::cout<<"Se separo "<<nameBodyA<<" de "<<nameBodyB<<std::endl;

    if(nameBodyA != "Chell_Player" && nameBodyB != "Chell_Player") return;

    if(nameBodyA == "Chell_Player" && nameBodyB == "Ground") static_cast<Entity *>(userDataA)->endContact();
    if(nameBodyA == "Chell_Player" && nameBodyB == "Metal_Block") static_cast<Entity *>(userDataA)->endContact();
    if(nameBodyA == "Chell_Player" && nameBodyB == "Stone_Block") static_cast<Entity *>(userDataA)->endContact();
    if(nameBodyA == "Chell_Player" && nameBodyB == "Bottom") static_cast<Entity *>(userDataA)->endContact();

    if(nameBodyB == "Chell_Player" && nameBodyA == "Ground") static_cast<Entity *>(userDataB)->endContact();
    if(nameBodyB == "Chell_Player" && nameBodyA == "Metal_Block") static_cast<Entity *>(userDataB)->endContact();
    if(nameBodyB == "Chell_Player" && nameBodyA == "Stone_Block") static_cast<Entity *>(userDataB)->endContact();
    if(nameBodyB == "Chell_Player" && nameBodyA == "Bottom") static_cast<Entity *>(userDataB)->endContact();
}

void bottom_endContact(void * userDataA, void * userDataB){
    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();
    if(nameBodyA != "Bottom" && nameBodyB != "Bottom") return;

    if(nameBodyA == "Bottom" && nameBodyB == "Chell_Player") static_cast<Entity *>(userDataA)->endContact();
    if(nameBodyA == "Bottom" && nameBodyB == "Rock") static_cast<Entity *>(userDataA)->endContact();

    if(nameBodyB == "Bottom" && nameBodyA == "Chell_Player") static_cast<Entity *>(userDataB)->endContact();
    if(nameBodyB == "Bottom" && nameBodyA == "Rock") static_cast<Entity *>(userDataB)->endContact();
}

void MyContactListener::EndContact(b2Contact* contact){
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if(bodyUserDataA){
        if(static_cast<Entity *>(bodyUserDataA)->getEntityName() == "Chell_Player"){
            if(!bodyUserDataB) static_cast<Entity *>(bodyUserDataA)->endContact();
        }
    }

    if(bodyUserDataB){
        if(static_cast<Entity *>(bodyUserDataB)->getEntityName() == "Chell_Player"){
            if(!bodyUserDataA) static_cast<Entity *>(bodyUserDataB)->endContact();
        }
    }

    if (!bodyUserDataA || !bodyUserDataB) return;
    chell_endContact(bodyUserDataA,bodyUserDataB);
    bottom_endContact(bodyUserDataA,bodyUserDataB);
}