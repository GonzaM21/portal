#ifndef MODEL_H
#define MODEL_H
#include <string>
#include <map> 
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "../server/server_game_loop.h"
#include "../server/server_sender.h"
#include "../server/modelo/World.h"
#include "Protected_Data_Base.h"


class Model {
    private:
        GameLoop *game_loop;
        ProtectedDataBase data_base;
        World world;

    public:
        explicit Model(Sender *sender);
        ~Model() = default;
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

        //Funciones para agregar elementos al mapa
        void addRock(float x_pos, float y_pos, float radius);
        void addAcid(float x_pos, float y_pos, float large);
        void addEnergyBall(float x_pos, float y_pos);
        void addMetalBlock(float x_pos, float y_pos,float size);
        void addStoneBlock(float x_pos, float y_pos,float size);
        void addBottom( float x_pos, float y_pos);
        void addGate( float x_pos, float y_pos);
        //void addEmitter(float x_pos, float y_pos, float size,std::string& direction, bool charged);
        //void addEnergyBarrier(float x_pos, float y_pos, float large);
        //void addPlayerPortals();
};

#endif
