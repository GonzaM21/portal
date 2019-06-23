#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H
#include "../server_model.h"
#include "object.h"
#include "object_rock.h"
#include "object_acid.h"
#include "object_energy_ball.h"
#include "object_metal_block.h"
#include "object_stone_block.h"
#include "object_gate.h"
#include "object_button.h"
#include "object_energy_barrier.h"
#include "object_emitter.h"
#include "object_cake.h"
#include "object_triangular_block.h"

class ObjectFactory {
private:
    Model *model;

public:
    ObjectFactory(Model *model);
    ~ObjectFactory() = default;
    ObjectRock* createObjectRock(float x_pos, float y_pos, float radius);
    ObjectGate *createObjectGate(float x_pos, float y_pos, int id);
    ObjectAcid* createObjectAcid(float x_pos, float y_pos, float large);
    ObjectEnergyBall* createObjectEnergyBall(float x_pos, float y_pos);
    ObjectMetalBlock* createObjectMetalBlock(float x_pos, float y_pos,float size);
    ObjectStoneBlock* createObjectStoneBlock(float x_pos, float y_pos,float size);
    ObjectButton* createObjectButton(float x_pos, float y_pos,int door_id,int state_to_open_door);
    ObjectEnergyBarrier* createObjectEnergyBarrier(float x_pos,float y_pos,float large,
    int orientation);
    ObjectEmitter* createObjectEmitter(float x_pos, float y_pos, float size,int 
       direction, int charged);
    ObjectCake* createObjectCake(float x_pos, float y_pos);
    ObjectTriangularBlock* createObjectTriangularBlock(float x_pos, float y_pos, float size,int 
       type);
};




#endif