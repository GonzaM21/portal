#include "MyContactListener.h"

void Energy_And_Chell(void* bodyUserDataA,void* bodyUserDataB){

    if(static_cast<Entity *>(bodyUserDataA)->Get_Entity_Name() == "Chell_Player"){
        if(static_cast<Entity *>(bodyUserDataB)->Get_Entity_Name() == "Chell_Player") return;
        if (static_cast<Entity *>(bodyUserDataB)->Get_Entity_Name() != "Portal"){
            static_cast<Entity *>(bodyUserDataA)->Die();
        } else {

        }
    } else if(static_cast<Entity *>(bodyUserDataA)->Get_Entity_Name() == "Portal"){
        static_cast<Entity *>(bodyUserDataA)->Die();
    } else{
        std::cout<<static_cast<Entity *>(bodyUserDataA)->Get_Entity_Name()<<std::endl;
    }


    if(static_cast<Entity *>(bodyUserDataB)->Get_Entity_Name() == "Chell_Player"){
        if(static_cast<Entity *>(bodyUserDataA)->Get_Entity_Name() == "Chell_Player") return;
        if (static_cast<Entity *>(bodyUserDataA)->Get_Entity_Name() != "Portal") {
            static_cast<Entity *>(bodyUserDataB)->Die();
        }
    } else if(static_cast<Entity *>(bodyUserDataB)->Get_Entity_Name() == "Portal"){
        static_cast<Entity *>(bodyUserDataB)->Die();
    } else{
        std::cout<<static_cast<Entity *>(bodyUserDataB)->Get_Entity_Name()<<std::endl;
    }

}

void MyContactListener::BeginContact(b2Contact * contact){
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
    if (bodyUserDataA ){
            static_cast<Entity *>(bodyUserDataA)->Start_Contact();
        std::cout<<"Begin Contact "<<static_cast<Entity *>(bodyUserDataA)->Get_Entity_Name()<<std::endl;
    }
    if (bodyUserDataB){
        static_cast<Entity*>(bodyUserDataB)->Start_Contact();
        std::cout<<"Begin Contact "<<static_cast<Entity *>(bodyUserDataB)->Get_Entity_Name()<<std::endl;
    }
    if(bodyUserDataA && bodyUserDataB){
        std::cout<<"2 are true\n";
       Energy_And_Chell(bodyUserDataA,bodyUserDataB);
    }

}

void MyContactListener::EndContact(b2Contact* contact){
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
    std::cout<<"End Contact\n";
    if (bodyUserDataA){
        static_cast<Entity*>(bodyUserDataA)->End_Contact();
        std::cout<<"End Contact "<<static_cast<Entity *>(bodyUserDataA)->Get_Entity_Name()<<std::endl;
    }
    if (bodyUserDataB){
        static_cast<Entity*>(bodyUserDataB)->End_Contact();
        std::cout<<"End Contact "<<static_cast<Entity *>(bodyUserDataB)->Get_Entity_Name()<<std::endl;
    }
}