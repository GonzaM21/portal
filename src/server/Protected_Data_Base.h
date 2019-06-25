#ifndef PROTECTED_DATA_BASE_H
#define PROTECTED_DATA_BASE_H
#include <string>
#include <map>
#include <mutex>
#include <vector>
#include "../common/Constants.h"
#include "modelo/World.h"
#include "modelo/Ground.h"
#include "modelo/Chell_Player.h"
#include "modelo/MyContactListener.h"
#include "modelo/Acid.h"
#include "modelo/Energy_Ball.h"
#include "modelo/Entity.h"
#include "modelo/Filter_Data.h"
#include "modelo/Metal_Block.h"
#include "modelo/Rock.h"
#include "modelo/Stone_Block.h"
#include "modelo/Player_Portals.h"
#include "modelo/Gate.h"
#include "modelo/Button.h"
#include "modelo/Energy_Barrier.h"
#include "modelo/Energy_Emitters.h"
#include "modelo/Cake.h"

/* Esta clase es un monitor de modelo, que contiene
*  todos los datos de la partida y estan protegidos
*/

class ProtectedDataBase {
private:
    std::mutex m;
    std::map<std::string,size_t> player_ids;
    std::map<std::string, Chell_Player*> players;
    std::map<std::string,std::string> vote_to_kill;
    std::map<std::string,bool> player_reach_cake;
    std::map<size_t, Rock*> rocks;
    std::map<size_t, Acid*> acids;
    std::map<size_t, Energy_Ball*> energy_balls;
    std::map<size_t, Metal_Block*> metal_blocks;
    std::map<size_t, Stone_Block*> stone_blocks;
    std::map<size_t, Gate*> gates;
    std::map<size_t, Button*> buttons;
    std::map<size_t, Energy_Barrier*> barriers;
    std::map<size_t, Energy_Emitters*> emitters;
    std::map<Button*,std::vector<size_t>> pending_buttons;
    std::map<size_t, Cake*> cakes;
    std::map<size_t,Metal_Block*> triangular_blocks;
    int width;
    int height;
    bool win_state = false;

    void setVotes(std::map<std::string, size_t> &votes);
    //std::string getPlayerToKill();
    void checkPlayerToKill(std::string &player_to_kill);

    //Funciones para eliminar todos los elementos del juego.
    void resetPlayers();
    void resetAcids();
    void resetRocks();
    void resetEnergyBalls();
    void resetMetalBlocks();
    void resetStoneBlocks();
    void resetGates();
    void resetButtons();
    void resetEnergyBarriers();
    void resetEnergyEmitters();
    void resetCakes();
    void resetTriangularBlocks();
    void resetButtonsToAdd();

public:
    ProtectedDataBase() = default;
    ~ProtectedDataBase();
    void setLevel(World &world);

    //Toma como parametro un string (nombre de un jugador)
    //y le indica al modelo que debe saltar 
    void makePlayerJump(std::string &player);

    //Toma como parametro un string (nombre de un jugador)
    //y le indica al modelo que debe moverse
    void makePlayerMove(std::string &player,char &direction);

    //Toma como parametro un string (nombre de un jugador)
    //y le indica al modelo que debe levantar/dejar una roca    
    void makePlayerMoveRock(std::string &player);

    //Toma como parametro un string (nombre de un jugador)
    //y le indica al modelo que debe disparar un portal
    void shootPortal(std::string &player,float x_destiny, float y_destiny,int portal_num);
    
    //Toma como parametro un string (nombre de un jugador)
    //y se setea que votamatar a otro jugador
    void voteToKill(std::string &voter);

    //Toma como parametro un jugador y le indica al modelo 
    //que debe morir
    void killPlayer(std::string &player_name);

    //Setea al juego en estado de ganar. Todos los jugadores
    //llegaron al pastel menos uno.
    void setWinState();

    //Toma como parametro un string (nombre de un jugador)
    //y le indica al modelo que debe ser inmortal
    void makePlayerInmortal(std::string &player);

    //Toma como parametro un string (nombre de un jugador)
    //y le indica al modelo que no lo debe afectar la gravedad
    void makePlayerAntiGravity(std::string &player);

    //Asocia todos los botones a su respectiva puerta
    void addButtonToDoor();

    //Agrega al mapa players un jugador y le indica al mundo que lo
    //debe agregar
    void addPlayer(World &world,std::string &player);

    //Agrega al mapa rocks una roca y le indica al mundo que lo
    //debe agregar
    void addRock(World &world,float x_pos, float y_pos, float radius);

    //Agrega al mapa acids un acido y le indica al mundo que lo
    //debe agregar
    void addAcid(World &world,float x_pos, float y_pos, float large);

    //Agrega al mapa energy_balls una bola de energia y le indica al mundo que lo
    //debe agregar
    void addEnergyBall(World &world,float x_pos, float y_pos);

    //Agrega al mapa metal_blocks un bloque de metal y 
    //le indica al mundo que lo debe agregar
    void addMetalBlock(World &world,float x_pos, float y_pos,float size);

    //Agrega al mapa stone_blocks un bloque de piedra y 
    //le indica al mundo que lo debe agregar
    void addStoneBlock(World &world,float x_pos, float y_pos,float size);

    //Agrega al mapa buttons un boton y 
    //le indica al mundo que lo debe agregar
    void addButton(World &world, float x_pos, float y_pos,int door_id,int state_to_open_door);

    //Agrega al mapa gates una puerta y 
    //le indica al mundo que lo debe agregar
    void addGate(World &world, float x_pos, float y_pos, int id);

    //Agrega al mapa emitters un emisor y 
    //le indica al mundo que lo debe agregar
    void addEmitter(World &world,float x_pos, float y_pos, float size,
      int direction, bool charged);

    //Agrega al mapa barriers una barrera de energia y 
    //le indica al mundo que lo debe agregar
    void addEnergyBarrier(World &world,float x_pos, float y_pos, float large, int orientation);

    //Agrega al mapa cakes una cake y 
    //le indica al mundo que lo debe agregar
    void addCake(World &world, float x_pos, float y_pos);

    //Agrega al mapa triangular_blocks un bloque triangular y 
    //le indica al mundo que lo debe agregar
    void addTriangularBlock(World &world, float x_pos, float y_pos, float size, int type);

    //Getters
    std::vector<std::string> getIds();
    std::vector<Chell_Player*> getPlayers();
    std::vector<Acid*> getAcids();
    std::vector<Metal_Block*> getMetalBlocks();
    std::vector<Rock*> getRocks();
    std::vector<Energy_Ball*> getEnergyBalls();
    std::vector<Stone_Block*> getStoneBlocks();
    std::vector<Gate*> getGates();
    std::vector<Button*> getButtons();
    std::vector<Energy_Barrier*> getBarriers();
    std::vector<Energy_Emitters*> getEmitters(); 
    std::vector<Cake*> getCakes();
    std::vector<Metal_Block*> getTriangularBlocks();     
    float getWidth();
    float getHeight();
    std::map<std::string,Chell_Player*> getPlayersMap();
    std::string getPlayersName();
    bool getWinState();
    std::map<std::string,std::string> getVoteToKill();  

    //Borra todos los datos de la base de datos protegida
    void resetDataBase();
};

#endif
