#include <string>
#include <vector>
#include <sstream>
#include <mutex>
#include <memory>
#include "server_room_game.h"
#include "server_model.h"
#include "server_command.h"
#include "server_command_factory.h"
#include "server_protocol.h"
#include "level_creator/map_parser.h"
#include "server_level_manager.h"

RoomGame :: RoomGame(std::string &name, size_t size) : sender() {
    this->name = name;
    this->size = size;
    this->continue_running = true;
    std::cout << "Se construye una room\n";
    this->messages = new ColaProtegida();
    this->room_is_active = true;
}

bool RoomGame :: addPlayer(std::string &name) {
    std::unique_lock<std::mutex> lock(m);
    if (this->playerInRoom(name)) return false;
    this->sender.addPlayer(name);
    this->players[name] = true;
    return true;
}

std::string RoomGame :: getName() {
    return this->name;
}

RoomGame :: ~RoomGame() {
    std::cout << "Se destruye una room\n";
    delete this->messages;
}

bool RoomGame :: playerInRoom(const std::string &name) {
    for (auto player: this->players) {
      if (player.first == name) return true;
    }
    return false;
}

void RoomGame :: addMessageToSend(std::string &message) {
    this->messages->push(message);
}

void RoomGame :: run() {
    try {
        Model model(&sender);
        LevelManager level_manager(&model,&this->players);
        CommandFactory commandFactory(&model,&level_manager,&this->players);                                                                       //los parametros que necesite algun comando se lo debo pasar aca
        Protoc protocol(commandFactory);
        level_manager.loadFirstLevel();
        while (this->continue_running) {
            std::string new_message = this->messages->pop();
            if (new_message == "NULL") continue;
            Command* command = protocol.deserialize(new_message);                                          
            if (command == nullptr) continue;
            command->execute();
            delete command;
            if (model.getFinishGame()) break;
            this->roomStillActive();
            model.checkWinState();                                              
        }
        model.endGame();
        this->room_is_active = false;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        std::cout << "room game exp\n";
    } 
}

void RoomGame::roomStillActive() {
    for (auto player: this->players) {
      if (player.second) return;
    }
    this->room_is_active = false;
}

void RoomGame :: endExecution() {
    this->continue_running = false;
    this->sender.endExecution();
    this->messages->set_terminar_ejecucion();
}

Sender* RoomGame :: getSender() {
    return &this->sender;
}

bool RoomGame ::getRoomIsActive() {
    return this->room_is_active;
}

void RoomGame ::closeSender() {
    this->sender.endExecution();
}