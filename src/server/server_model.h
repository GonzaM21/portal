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

    public:
        explicit Model(Sender *sender);
        ~Model(); //= default;
        void startGame();
        bool gameStarted(); 
        void endGame();
        std::string getTime();
        void step();
        void addPlayer(std::string &player);
        std::string getJugadores(); //HAY QUE BORRAR
        World* getWorld();
        void makePlayerJump(std::string &player);
        void makePlayerMove(std::string &player,char &direction);
        void shootPortal(std::string &player,float x_destiny, float y_destiny,int portal_num);//portal num es 0 o 1, 0 in 1 out
        void makePlayerMoveRock(std::string &player);

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
};

#endif
