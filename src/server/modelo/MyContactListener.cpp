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

    if(nameBodyA == "Chell_Player" && (nameBodyB == "Ground" || nameBodyB == "Button" || nameBodyB == "Rock")){
        static_cast<Entity *>(userDataA)->startContact(bodyB->GetPosition());
    }

    if(nameBodyA == "Chell_Player" && (nameBodyB == "Metal_Block" || nameBodyB == "Stone_Block")){
        static_cast<Entity *>(userDataA)->startContact(bodyB->GetPosition());
    }

    if(nameBodyB == "Chell_Player" && (nameBodyA == "Ground" || nameBodyA == "Button" || nameBodyA == "Rock")){
        static_cast<Entity *>(userDataB)->startContact(bodyA->GetPosition());
    }

    if(nameBodyB == "Chell_Player" && (nameBodyA == "Metal_Block" || nameBodyA == "Stone_Block")){
        static_cast<Entity *>(userDataB)->startContact(bodyA->GetPosition());
    }

    chell_validation(static_cast<Entity *>(userDataA),static_cast<Entity *>(userDataB));

}

void portal_colitions(b2Body * bodyA,b2Body * bodyB,b2Vec2 colition_point){
    void * userDataA = static_cast<Entity *>(bodyA->GetUserData());
    void * userDataB = static_cast<Entity *>(bodyB->GetUserData());

    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();

    std::cout<<"position colision: "<<colition_point.x<<"  "<<colition_point.y<<std::endl;

    if(nameBodyA != "Portal" && nameBodyB != "Portal") return;

    if(nameBodyA == "Portal" && nameBodyB == "Metal_Block"){
        static_cast<Entity *>(userDataA)->startContact(bodyB->GetPosition() + colition_point);
        static_cast<Entity *>(userDataA)->setTransform(static_cast<Entity *>(userDataB));
    }

    if(nameBodyA == "Portal" && nameBodyB == "Ground"){
        b2Vec2 pos = b2Vec2(bodyA->GetPosition().x,bodyB->GetPosition().y);
        static_cast<Entity *>(userDataA)->startContact(pos + colition_point);
        static_cast<Entity *>(userDataA)->setTransform(static_cast<Entity *>(userDataB));
    }

    if(nameBodyB == "Portal" && nameBodyA == "Metal_Block"){
        static_cast<Entity *>(userDataB)->startContact(bodyA->GetPosition() + colition_point);
        static_cast<Entity *>(userDataB)->setTransform(static_cast<Entity *>(userDataA));
    }

    if(nameBodyB == "Portal" && nameBodyA == "Ground"){
        b2Vec2 pos = b2Vec2(bodyB->GetPosition().x,bodyA->GetPosition().y);
        static_cast<Entity *>(userDataB)->startContact(pos + colition_point);
        static_cast<Entity *>(userDataB)->setTransform(static_cast<Entity *>(userDataA));
    }

}

void button_colitions(b2Body * bodyA,b2Body * bodyB){
    void * userDataA = static_cast<Entity *>(bodyA->GetUserData());
    void * userDataB = static_cast<Entity *>(bodyB->GetUserData());

    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();

    if(nameBodyA != "Button" && nameBodyB != "Button") return;

    if(nameBodyA == "Button" && (nameBodyB == "Rock" || nameBodyB == "Chell_Player")){
        static_cast<Entity *>(userDataA)->startContact(bodyB->GetPosition());
    }

    if(nameBodyB == "Button" && (nameBodyA == "Rock" || nameBodyA == "Chell_Player")){
        static_cast<Entity *>(userDataB)->startContact(bodyA->GetPosition());
    }
}

void energy_ball_colition(b2Body * bodyA,b2Body * bodyB){
    void * userDataA = static_cast<Entity *>(bodyA->GetUserData());
    void * userDataB = static_cast<Entity *>(bodyB->GetUserData());

    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();

    if(nameBodyA != "Energy_Ball" && nameBodyB != "Energy_Ball") return;

    if(nameBodyA == "Energy_Ball" && nameBodyB == "Energy_Emitter"){
        static_cast<Entity *>(userDataA)->die();
        static_cast<Entity *>(userDataB)->startContact(b2Vec2(0,0));
    }

    if(nameBodyB == "Energy_Ball" && nameBodyA == "Energy_Emitter"){
        static_cast<Entity *>(userDataB)->die();
        static_cast<Entity *>(userDataA)->startContact(b2Vec2(0,0));
    }
}

void energy_barrier_colition(b2Body * bodyA,b2Body * bodyB){
    void * userDataA = static_cast<Entity *>(bodyA->GetUserData());
    void * userDataB = static_cast<Entity *>(bodyB->GetUserData());

    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();

    if(nameBodyA != "Energy_Barrier" && nameBodyB != "Energy_Barrier") return;

    if(nameBodyA == "Energy_Barrier" && (nameBodyB == "Rock" || nameBodyB == "Portal")){
        static_cast<Entity *>(userDataB)->die();
    }

    if(nameBodyB == "Energy_Barrier" && (nameBodyA == "Rock" || nameBodyA == "Portal")){
        static_cast<Entity *>(userDataA)->die();
    }
}

void MyContactListener::BeginContact(b2Contact * contact){
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    b2Vec2 colition_point = contact->GetManifold()->localPoint;

    std::cout<<"position colision: "<<colition_point.x<<"  "<<colition_point.y<<std::endl;

    if(bodyUserDataA){
        if(static_cast<Entity *>(bodyUserDataA)->getEntityName() == "Chell_Player"){
            printf("Chell choco con el piso\n");
            if(!bodyUserDataB){} static_cast<Entity *>(bodyUserDataA)->startContact(b2Vec2(0,0));
        }
        if(static_cast<Entity *>(bodyUserDataA)->getEntityName() == "Portal"){
            if(!bodyUserDataB){
                b2Body* bodyA = contact->GetFixtureA()->GetBody();
                b2Body* bodyB = contact->GetFixtureB()->GetBody();
                printf("Portal choco con el piso\n");
                b2Vec2 pos = b2Vec2(bodyA->GetPosition().x,bodyB->GetPosition().y);
                static_cast<Entity *>(bodyUserDataA)->startContact(pos + colition_point);
                static_cast<Entity *>(bodyUserDataA)->setTransform(nullptr);
            }
        }
    }

    if(bodyUserDataB){
        if(static_cast<Entity *>(bodyUserDataB)->getEntityName() == "Chell_Player"){
            printf("Chell choco con el piso\n");
            if(!bodyUserDataA) static_cast<Entity *>(bodyUserDataB)->startContact(b2Vec2(0,0));
        }
        if(static_cast<Entity *>(bodyUserDataB)->getEntityName() == "Portal"){
            if(!bodyUserDataA) {
                b2Body *bodyA = contact->GetFixtureA()->GetBody();
                b2Body *bodyB = contact->GetFixtureB()->GetBody();
                printf("Portal choco con el piso\n");
                b2Vec2 pos = b2Vec2(bodyB->GetPosition().x, bodyA->GetPosition().y) + colition_point;
                static_cast<Entity *>(bodyUserDataB)->startContact(pos);
                static_cast<Entity *>(bodyUserDataB)->setTransform(nullptr);
            }

        }
    }
    if (!bodyUserDataA || !bodyUserDataB) return;
    chell_colitions(contact->GetFixtureA()->GetBody(),contact->GetFixtureB()->GetBody());
    portal_colitions(contact->GetFixtureA()->GetBody(),contact->GetFixtureB()->GetBody(),colition_point);
    button_colitions(contact->GetFixtureA()->GetBody(),contact->GetFixtureB()->GetBody());
    energy_ball_colition(contact->GetFixtureA()->GetBody(),contact->GetFixtureB()->GetBody());
    energy_barrier_colition(contact->GetFixtureA()->GetBody(),contact->GetFixtureB()->GetBody());

}

void chell_endContact(void * userDataA, void * userDataB){
    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();

    std::cout<<"Se separo "<<nameBodyA<<" de "<<nameBodyB<<std::endl;

    if(nameBodyA != "Chell_Player" && nameBodyB != "Chell_Player") return;

    if(nameBodyA == "Chell_Player" && nameBodyB == "Ground") static_cast<Entity *>(userDataA)->endContact();
    if(nameBodyA == "Chell_Player" && nameBodyB == "Metal_Block") static_cast<Entity *>(userDataA)->endContact();
    if(nameBodyA == "Chell_Player" && nameBodyB == "Stone_Block") static_cast<Entity *>(userDataA)->endContact();
    if(nameBodyA == "Chell_Player" && nameBodyB == "Button") static_cast<Entity *>(userDataA)->endContact();

    if(nameBodyB == "Chell_Player" && nameBodyA == "Ground") static_cast<Entity *>(userDataB)->endContact();
    if(nameBodyB == "Chell_Player" && nameBodyA == "Metal_Block") static_cast<Entity *>(userDataB)->endContact();
    if(nameBodyB == "Chell_Player" && nameBodyA == "Stone_Block") static_cast<Entity *>(userDataB)->endContact();
    if(nameBodyB == "Chell_Player" && nameBodyA == "Button") static_cast<Entity *>(userDataB)->endContact();
}

void button_endContact(void * userDataA, void * userDataB){
    std::string nameBodyA = static_cast<Entity *>(userDataA)->getEntityName();
    std::string nameBodyB = static_cast<Entity *>(userDataB)->getEntityName();
    if(nameBodyA != "Button" && nameBodyB != "Button") return;

    if(nameBodyA == "Button" && nameBodyB == "Chell_Player") static_cast<Entity *>(userDataA)->endContact();
    if(nameBodyA == "Button" && nameBodyB == "Rock") static_cast<Entity *>(userDataA)->endContact();

    if(nameBodyB == "Button" && nameBodyA == "Chell_Player") static_cast<Entity *>(userDataB)->endContact();
    if(nameBodyB == "Button" && nameBodyA == "Rock") static_cast<Entity *>(userDataB)->endContact();
}

void MyContactListener::EndContact(b2Contact* contact){
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if(bodyUserDataA){
        if(static_cast<Entity *>(bodyUserDataA)->getEntityName() == "Chell_Player"){
            if(!bodyUserDataB){
                printf("Chell se separo del piso\n");
                static_cast<Entity *>(bodyUserDataA)->endContact();
            }
        }
    }

    if(bodyUserDataB){
        if(static_cast<Entity *>(bodyUserDataB)->getEntityName() == "Chell_Player"){

            if(!bodyUserDataA){
                printf("Chell se separo del piso\n");
                static_cast<Entity *>(bodyUserDataB)->endContact();
            }
        }
    }

    if (!bodyUserDataA || !bodyUserDataB) return;
    chell_endContact(bodyUserDataA,bodyUserDataB);
    button_endContact(bodyUserDataA,bodyUserDataB);
}