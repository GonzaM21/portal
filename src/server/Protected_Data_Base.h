#ifndef PROTECTED_DATA_BASE_H
#define PROTECTED_DATA_BASE_H
#include <string>
#include <map>
#include <mutex>
#include "../common/Constants.h"
#include "../server/modelo/World.h"
#include "../server/modelo/Block.h"
#include "../server/modelo/Ground.h"
#include "../server/modelo/Chell_Player.h"
#include "../server/modelo/MyContactListener.h"
#include "../server/modelo/Acid.h"
#include "../server/modelo/Energy_Ball.h"
#include "../server/modelo/Entity.h"
#include "../server/modelo/Filter_Data.h"
#include "../server/modelo/Metal_Block.h"
#include "../server/modelo/Rock.h"
#include "../server/modelo/Stone_Block.h"
#include "../server/modelo/Player_Portals.h"
#include "../server/modelo/Gate.h"
#include "../server/modelo/Bottom.h"
#include "../server/modelo/Energy_Barrier.h"
#include "../server/modelo/Energy_Emitters.h"

//puedo tener un mapa acutal y un mapa nuevo, sobre mapa nuevo hago los cambios(actualizo) mientras en mapa
//actual el encoder me va piendo informacion. Cuando el encoder termina de recorrer llamo a un metodo
//actualizar mapa. Puedo manejar booleanos para saber si debo o no acutalizar el mapa. (desventja: el mapá
//de rocas cuando las transportan cambio demasiado y los players tambien. puede traer lag esto)

class ProtectedDataBase {
private:
    std::mutex m;
    std::map<std::string,size_t> player_ids;
    std::map<std::string, Chell_Player*> players;
    std::map<size_t, Rock*> rocks;
    std::map<size_t, Acid*> acids;
    std::map<size_t, Energy_Ball*> energy_balls;
    std::map<size_t, Metal_Block*> metal_blocks;
    std::map<size_t, Stone_Block*> stone_blocks;
    std::map<size_t, Gate*> gates;
    std::map<size_t, Bottom*> bottoms;
    //std::map<size_t, Player_Portals*> player_portals;
    std::map<size_t, Energy_Barrier*> barriers;
    std::map<size_t, Energy_Emitters*> emitters;
    int width;
    int height;

public:
    ProtectedDataBase() = default;
    ~ProtectedDataBase() = default;

    void makePlayerJump(std::string &player);
    void makePlayerMove(std::string &player,char &direction);
    void shootPortal(World &world,std::string &player,float x_destiny, float y_destiny,int portal_num);

    void addPlayer(World &world,std::string &player);
    void addRock(World &world,float x_pos, float y_pos, float radius);
    void addAcid(World &world,float x_pos, float y_pos, float large);
    void addEnergyBall(World &world,float x_pos, float y_pos);
    void addMetalBlock(World &world,float x_pos, float y_pos,float size);
    void addStoneBlock(World &world,float x_pos, float y_pos,float size);
    void addBottom(World &world, float x_pos, float y_pos);
    void addGate(World &world, float x_pos, float y_pos);
    //void addPlayerPortals();
    void addEmitter(World &world,float x_pos, float y_pos, float size,
      std::string& direction, bool charged);
    void addEnergyBarrier(World &world,float x_pos, float y_pos, float large);

    //Getters
    std::vector<std::string> getIds();
    std::vector<Chell_Player*> getPlayers();
    std::vector<Acid*> getAcids();
    std::vector<Metal_Block*> getMetalBlocks();
    std::vector<Rock*> getRocks();
    std::vector<Energy_Ball*> getEnergyBalls();
    std::vector<Stone_Block*> getStoneBlocks();
    std::vector<Gate*> getGates();
    std::vector<Bottom*> getBottoms();
    //std::vector<Player_Portals*> getPlayerPortals();
    std::vector<Energy_Barrier*> getBarriers();
    std::vector<Energy_Emitters*> getEmitters();      
    float getWidth();
    float getHeight();  
};

#endif