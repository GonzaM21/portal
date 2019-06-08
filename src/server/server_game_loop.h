#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#define PLAYER_CODE 1
#define BLOCK_CODE 2
#define GATE_CODE 3
#define BUTTON_CODE 4
#define ACID_CODE 5
#define PORTAL_CODE 6
#define POWERBALL_CODE 7
#define ROCK_CODE 8
#define ENERGY_BARRIER_CODE 9

#include <iostream>
#include <string>
#include <time.h>
#include <map>
#include "../server/server_sender.h"
#include "../common/Thread.h"
#include "Protected_Data_Base.h"
#include "Encoder.h"
//#include "../server/modelo/doors"


class GameLoop : public Thread {
    private:
        int time;
        bool continue_running;
        std::string getFormat(int time);
        World* world;
        Encoder encoder;

    public:
        GameLoop(World* world,Sender *sender,ProtectedDataBase *data_base);
        ~GameLoop() = default;
        std::string getTime();
        void endGameLoop();
        bool gameLoopStarted();
        void run() override;
        void step();
        void sendWorldSizes();
};

#endif
