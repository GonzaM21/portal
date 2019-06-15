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

RoomGame :: RoomGame(std::string &name, size_t size) : sender() {
    this->name = name;
    this->size = size;
    this->continue_running = true;
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
    Model model(&sender);
    std::string json("json_file");
    MapParser map_parser(&model,json);
    CommandFactory commandFactory(&model,&map_parser,&this->players);                                                                       //los parametros que necesite algun comando se lo debo pasar aca
    Protoc protocol(commandFactory);
    map_parser.addObjectsToModel(); //TENGO QUE CAMBIAR ESTO POR UN COMANDO "CREATE WORLD O PARSE_WORLD"
    while (this->continue_running) {
        std::string new_message = this->messages->pop();
        if (new_message == "NULL") continue; // OJO CON ESTO continue o break
        Command* command = protocol.deserialize(new_message);                                                   //std::shared_ptr<Command*> command(protocol.deserialize(new_message)); //recomendo que use share_ptr (?)
        if (command == nullptr) continue;
        command->execute();
        this->roomStillActive();
    }
    model.endGame();
}

void RoomGame::roomStillActive() {
    for (auto player: this->players) {
      if (player.second) return;
    }
    this->room_is_active = false;
}

void RoomGame :: endExecution() {
    this->continue_running = false;
    this->messages->set_terminar_ejecucion();
    this->sender.endExecution();
}

Sender* RoomGame :: getSender() {
    return &this->sender;
}

bool RoomGame ::getRoomIsActive() {
    return this->room_is_active;
}