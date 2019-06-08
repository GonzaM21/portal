#define HOUR 3600000
#define MINUTE 60000
#define SECOND 1000
#define STEP_DURATION 40
#include "../server/server_game_loop.h"
#include "../server/modelo/Macros.h"
#include <chrono>

GameLoop ::GameLoop(World *world, Sender *sender,
    ProtectedDataBase *data_base) : encoder(data_base,sender) {
    this->time = 0;
    this->continue_running = true;
    this->world = world;
}

void GameLoop :: run() {
    this->encoder.sendPlayersPositions();
    this->encoder.sendPlayerIds();
    this->encoder.sendMetalBlocks();
    this->encoder.sendAcids();
    while (this->continue_running) {
        auto t_start = std::chrono::high_resolution_clock::now();
        world->WorldStep();
        this->encoder.sendPlayersPositions(); //aca va todo lo que se puede ir actualizando
        auto t_end = std::chrono::high_resolution_clock::now();
        int delta_time = std::chrono::duration<double, std::milli>(t_end-t_start).count();
        int wait_time = STEP_DURATION-delta_time; //deberia chequear que es mayor a 0
        std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
        this->time += STEP_DURATION;
    }
}

void GameLoop ::endGameLoop() {
    this->continue_running = false;
}

std::string GameLoop ::getFormat(int time) {
    std::string time_s = std::to_string(time);
    if (time_s.size() == 1)
    {
        time_s = "0" + time_s;
    }
    return time_s;
}

std::string GameLoop ::getTime() {
    if (this->time == 0)
        return "NULL";
    int hours = int(this->time / HOUR);
    int minutes = int(this->time % HOUR / MINUTE);
    int seconds = int(this->time % HOUR % MINUTE / SECOND);
    return getFormat(hours) + ":" + getFormat(minutes) + ":" + getFormat(seconds);
}

bool GameLoop ::gameLoopStarted() {
    return this->time != 0;
}
