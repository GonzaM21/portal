#define HOUR 3600000
#define MINUTE 60000
#define SECOND 1000
#define STEP_DURATION 40
#include "../server/server_game_loop.h"
#include "../server/modelo/Macros.h"
#include <chrono>

GameLoop ::GameLoop(World *world, Sender *sender,
    std::map<std::string, Chell_Player *> *players) {
    this->time = 0;
    this->continue_running = true;
    this->world = world;
    this->players = players;
    this->sender = sender;
}

void GameLoop :: sendMessages() {
    this->sendPlayersPositions();
}

void GameLoop ::sendPlayersPositions() {
    std::map<std::string,Chell_Player*>::iterator it;
    int id(1);
    for ( it = (*this->players).begin(); it != (*this->players).end(); it++ ) {
        //std::cout << it->first << std::endl;
        //std::cout << id << std::endl;
        b2Vec2 position = it->second->Get_Position();
        std::string msg = "1,"+std::to_string(id)+ "," + std::to_string(position.x) + "," + 
        std::to_string(position.y) + "," + std::to_string(CHELL_WIDTH)+ "," + 
        std::to_string(CHELL_HIGH);
        this->sender->addMessageToSend(msg);
        std::cout << msg << std::endl;
        id++;        
    }  
}

void GameLoop ::sendWorldSizes() {
    b2Vec2 high_b = this->world->getHigh();
    b2Vec2 width_b = this->world->getWidth();
    std::string msg("0," + std::to_string(width_b.x * 2) + "," + std::to_string(high_b.x * 2) + "\n");
    this->sender->addMessageToSend(msg);
}

void GameLoop :: sendIds() {
    std::map<std::string,Chell_Player*>::iterator it;
    int id(1);
    for ( it = (*this->players).begin(); it != (*this->players).end(); it++ ) {
        std::string msg;
        msg = "0," + std::to_string(id);
        this->sender->sendMessageTo(it->first,msg);
        id++;
    }
}

void GameLoop :: sendMetalBlocks() {
    std::map<std::string,Metal_Block*>::iterator it;
    for (it = (*this->metal_blocks).begin(); it != (*this->metal_blocks).end(); it++) {
        std::string msg;
        b2Vec2 pos = it->second->Get_Position();
        msg = "2,1," + std::to_string(pos.x) + "," + std::to_string(pos.y) +
        "," + std::to_string(it->second->Get_Size()) + "," + std::to_string(it->second->Get_Size());
        this->sender->addMessageToSend(msg);
    }
}

void GameLoop :: sendAcids() {
    std::map<std::string,Acid*>::iterator it;
    for (it = (*this->acids).begin(); it != (*this->acids).end(); it++) {
        std::string msg;
        b2Vec2 pos = it->second->Get_Position();
        msg = "5,"+ std::to_string(pos.x) + "," + std::to_string(pos.y) +
        "," + std::to_string(it->second->Get_Large()) + ",0.2";
        this->sender->addMessageToSend(msg);
    }
}

void GameLoop :: run() {
    this->sendPlayersPositions();
    this->sendIds();
    this->sendMetalBlocks();
    this->sendAcids();
    while (this->continue_running) {
        auto t_start = std::chrono::high_resolution_clock::now();
        world->WorldStep();
        this->sendMessages();
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

void GameLoop :: setMetalBlocks(std::map<std::string,Metal_Block*>* metal_blocks) {
    this->metal_blocks = metal_blocks;
}

void GameLoop :: setAcids(std::map<std::string,Acid*>* acids) {
    std::cout << "Entra a acid set acid\n";
    this->acids = acids;
}

//void GameLoop :: setDoors(std::map<std::string,Acid*>* acids) {
//    this->acids = acids;
//}