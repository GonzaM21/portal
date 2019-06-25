#define HOUR 3600000
#define MINUTE 60000
#define SECOND 1000
#define STEP_DURATION 40 //tiene que coincidir con el step del world 
#define LEVEL_UNFINISH -1
#define WAIT_ANSWER 0
#define NEXT_LEVEL 1
#define FINISH_GAME 2
#include "server_game_loop.h"
#include "modelo/Macros.h"
#include <chrono>

GameLoop ::GameLoop(World *world, Sender *sender,
    ProtectedDataBase *data_base) : encoder(data_base,sender) {
    this->time = 0;
    this->continue_running = false;
    this->world = world;
    this->data_base = data_base;
    this->next_scenario = LEVEL_UNFINISH;
    this->number_of_levels = -1;
}

void GameLoop::setNumberOfLevels(int n) {
    this->number_of_levels = n;
}

void GameLoop :: sendInfoPlayers() {
    if (!this->gameLoopStarted())
        this->encoder.sendPlayersName();
}

void GameLoop :: sendInitialData() {
    std::cout << "Se manda datos iniciales\n";
    this->encoder.sendMapStart();
    this->encoder.sendPlayersPositions();
    this->encoder.sendPlayerIds();
    //this->encoder.sendWorldSizes();
    this->encoder.sendMetalBlocks();
    this->encoder.sendButtons();    
    this->encoder.sendEnergyBalls();
    this->encoder.sendRocks();
    this->encoder.sendStoneBlocks();
    this->encoder.sendAcids();
    this->encoder.sendGates();
    this->encoder.sendBarriers();
    this->encoder.sendCake();
    this->encoder.sendTriangularBlocks();
    this->encoder.sendEndMap();
    std::cout << "Termina de mandar datos\n";
}

void GameLoop :: sendDynamicData() { 
    this->encoder.sendPlayersPositions();
    this->encoder.sendPortals();
    this->encoder.sendRocks();
    this->encoder.sendGates(); 
    this->encoder.sendButtons();   
    this->encoder.sendEmitters();
    this->encoder.sendSwap();
}

void GameLoop :: run() {
    try {
        this->continue_running = true;
        int level_number = 0;
        this->sendInitialData();
        while (this->continue_running) {
            auto t_start = std::chrono::high_resolution_clock::now();
            world->Step(0.04);//no harcodear esto pasar a constantes
            this->sendDynamicData();
            auto t_end = std::chrono::high_resolution_clock::now();
            int delta_time = std::chrono::duration<double, std::milli>(t_end-t_start).count();
            int wait_time = STEP_DURATION-delta_time;
            if (wait_time <= 0) {
                std::cout << "ALERTA: Servidor no llega a procesar todos los eventos." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
            this->time += STEP_DURATION;
            if (this->checkLevelComplete()) {
                level_number++;
                this->waitNextAction(level_number);
            }
        }
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error: unknown" << std::endl;
    }
}

void GameLoop ::endGameLoop() {
    this->continue_running = false;
}

void GameLoop::resetGameLoop() {
    this->time = 0;
    this->continue_running = true;
    this->next_scenario = LEVEL_UNFINISH;
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

bool GameLoop ::continueRunning() {
    return this->continue_running;
}

bool GameLoop::checkLevelComplete() {
    std::vector<Chell_Player*> chells = this->data_base->getPlayers();
    for (size_t i = 0; i<chells.size(); i++) {
        if (chells[i]->getStatus() != 3) return false;
    }
    return true;
}

void GameLoop::waitNextAction(int level_number) {
    if (level_number == this->number_of_levels) {
        this->next_scenario = FINISH_GAME;
        this->encoder.sendEndGame();
        return;
    }
    this->encoder.sendEndLevel();
    while (true) {
        if (this->next_scenario == NEXT_LEVEL) {
                std::cout << "entra a next level\n" << std::endl;
            this->encoder.sendNextLevelStart();
            this->sendInitialData();
            this->resetGameLoop();
            break;
        } else if (this->next_scenario == FINISH_GAME) {
            std::cout << "entra a finish game\n" << std::endl;
            this->encoder.sendEndGame();
            break;
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(STEP_DURATION));
        }
    }
    std::cout << "se va waitnextlevel\n" << std::endl;
}

void GameLoop::setNextScenario(int action,World* world) {
    //if (!this->checkLevelComplete()) return;
    std::cout << "entro a next scenario" << std::endl;
    this->next_scenario = action;
    if (world != nullptr) this->world = world;
}
