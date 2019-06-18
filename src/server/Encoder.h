#ifndef ENCODER_H
#define ENCODER_H
#include "modelo/Macros.h"
#include "Protected_Data_Base.h"
#include "server_sender.h"
#include <mutex>
#include <string>

class Encoder {
private:
    ProtectedDataBase *data_base;
    Sender *sender;
    std::mutex m;
    void sendEnergyBall(Energy_Emitters* emitter);

public:
    Encoder(ProtectedDataBase *data_base,Sender *sender);
    ~Encoder() = default;
    void sendPlayerIds();
    void sendPlayersPositions();
    void sendMetalBlocks();
    void sendAcids();
    void sendWorldSizes();
    void sendRocks();
    void sendButtons();
    void sendEnergyBalls();
    void sendStoneBlocks();
    void sendGates();
    void sendEndMap();
    void sendPortals();
    void sendBarriers();
    void sendCake();
    void sendEmitters();
    void sendEndLevel();
    void sendEndGame();
    void sendNextLevelStart();
    void sendMapStart();
    void sendPlayersName();
    void sendRoomsName();
};

#endif
