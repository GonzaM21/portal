#ifndef PROTECTED_DATA_BASE_H
#define PROTECTED_DATA_BASE_H
#include <string>
#include <map>
#include <mutex>
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

//puedo tener un mapa acutal y un mapa nuevo, sobre mapa nuevo hago los cambios(actualizo) mientras en mapa
//actual el encoder me va piendo informacion. Cuando el encoder termina de recorrer llamo a un metodo
//actualizar mapa. Puedo manejar booleanos para saber si debo o no acutalizar el mapa. (desventja: el mapá
//de rocas cuando las transportan cambio demasiado y los players tambien. puede traer lag esto)

class ProtectedDataBase {
private:
    std::mutex m;
    std::map<std::string, Chell_Player*> players;
    std::map<size_t, Rock*> rocks;
    std::map<size_t, Acid*> acids;
    std::map<size_t, Energy_Ball*> energy_balls;
    std::map<size_t, Metal_Block*> metal_blocks;
    int width;
    int height;

public:
    ProtectedDataBase() = default;
    ~ProtectedDataBase() = default;
    void makePlayerJump(std::string &player);
    void makePlayerMove(std::string player,char &direction);
    void addPlayer(World &world,std::string &player);
    void addRock(World &world,float x_pos, float y_pos, float radius);
    void addAcid(World &world,float x_pos, float y_pos, float large);
    void addEnergyBall(World &world,float x_pos, float y_pos);
    void addMetalBlock(World &world,float x_pos, float y_pos,float size);
    std::vector<std::string> getIds();
    std::vector<Chell_Player*> getPlayers();
    std::vector<Acid*> getAcids();
    std::vector<Metal_Block*> getMetalBlocks();
    void setWidth(int width);
    void setHeight(int height);
    int getWidth();
    int getHeight();  
};

#endif