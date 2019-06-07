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


class Model {
    private:
        GameLoop *game_loop;
        std::map<std::string, Chell_Player*> players;
        std::map<std::string, Rock*> rocks;
        std::map<std::string, Acid*> acids;
        std::map<std::string, Energy_Ball*> energy_balls;
        std::map<std::string, Metal_Block*> metal_blocks;
        World world;

    public:
        explicit Model(Sender *sender);
        ~Model();
        void startGame();
        bool gameStarted(); 
        void endGame();
        std::string getTime();
        void step();
        void addPlayer(std::string &player);
        std::string getJugadores();
        World* getWorld();
        void makePlayerJump(std::string &player);
        void makePlayerMove(std::string player,char &direction);

        //Funciones para agregar elementos al mapa
        void addRock(float x_pos, float y_pos, float radius);
        void addAcid(float x_pos, float y_pos, float large);
        void addEnergyBall(float x_pos, float y_pos);
        void addMetalBlock(float x_pos, float y_pos,float size);
};

#endif
