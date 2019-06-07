#include <string>
#include <vector>
#include <sstream>
#include <mutex>
#include <memory>
#include "../server/server_room_game.h"
#include "../server/server_model.h"
#include "../server/server_command.h"
#include "../server/server_command_factory.h"
#include "../server/server_protocol.h"
#include "level_creator/map_parser.h"

RoomGame :: RoomGame(std::string &name, size_t size) : sender() {
    this->name = name;
    this->size = size;
    this->continue_running = true;
    this->messages = new ColaProtegida();
}

bool RoomGame :: addPlayer(std::string &name) {
    std::unique_lock<std::mutex> lock(m);
    if (this->playerInRoom(name)) return false;
    this->players.push_back(name);
    this->sender.addPlayer(name);
    return true;
}

std::string RoomGame :: getName() {
    return this->name;
}

RoomGame :: ~RoomGame() {
    delete this->messages;
}

bool RoomGame :: playerInRoom(const std::string &name) {
    for (std::string & player : this->players) {
        if (player == name) {
            return true;
        }
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
    CommandFactory commandFactory(&model,&map_parser);                                                                       //los parametros que necesite algun comando se lo debo pasar aca
    Protoc protocol(commandFactory);
    map_parser.addObjectsToModel(); //TENGO QUE CAMBIAR ESTO POR UN COMANDO "CREATE WORLD O PARSE_WORLD"
    while (this->continue_running) {
        std::string new_message = this->messages->pop();
        if (new_message == "NULL") continue; // OJO CON ESTO continue o break
        Command* command = protocol.deserialize(new_message);                                                   //std::shared_ptr<Command*> command(protocol.deserialize(new_message)); //recomendo que use share_ptr (?)
        if (command == nullptr) continue;
        command->execute();
    }
    model.endGame();
}

void RoomGame :: endExecution() {
    this->continue_running = false;
    this->messages->set_terminar_ejecucion();
    this->sender.endExecution();
}

Sender* RoomGame :: getSender() {
    return &this->sender;
}
