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

public:
    Encoder(ProtectedDataBase *data_base,Sender *sender);
    ~Encoder() = default;
    void sendPlayerIds();
    void sendPlayersPositions();
    void sendMetalBlocks();
    void sendAcids();
    //void sendWorldSizes();
};

#endif
