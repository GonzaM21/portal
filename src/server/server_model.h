#ifndef MODEL_H
#define MODEL_H
#include <string>
#include <map> 
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "server_game_loop.h"
#include "server_sender.h"
#include "modelo/World.h"
#include "Protected_Data_Base.h"


class Model {
    private:
        GameLoop *game_loop;
        ProtectedDataBase data_base;
        World world;
        Ground * ground;
        bool levelComplete();

    public:
        explicit Model(Sender *sender);
        ~Model();
        void startGame();
        bool gameRunning(); 
        void endGame();
        std::string getTime();
        void step();
        void addPlayer(std::string &player);
        void sendInfoPlayers();
        void sendInfoRooms();
        World* getWorld();
        void makePlayerJump(std::string &player);
        void makePlayerMove(std::string &player,char &direction);
        void shootPortal(std::string &player,float x_destiny, float y_destiny,int portal_num);
        void makePlayerMoveRock(std::string &player);
        void checkWinState();
        void killPlayer(std::string &player_name);
        void voteToKill(std::string &voter);
        void resetModel();
        void resetGameLoop(); //lo tengo en funciones aparte porque entre que reseteo el modelo y el gameloop tengo que agregar todos los objectos al world en levelManager 

        //Funciones para agregar elementos al mapa
        void addRock(float x_pos, float y_pos, float radius);
        void addAcid(float x_pos, float y_pos, float large);
        void addEnergyBall(float x_pos, float y_pos);
        void addMetalBlock(float x_pos, float y_pos,float size);
        void addStoneBlock(float x_pos, float y_pos,float size);
        void addButton( float x_pos, float y_pos,int door_id,int state_to_open_door);
        void addGate( float x_pos, float y_pos);
        void addEmitter(float x_pos, float y_pos, float size,int direction, bool charged);
        void addEnergyBarrier(float x_pos, float y_pos, float large);
        void addCake(float x_pos, float y_pos);
};

#endif
