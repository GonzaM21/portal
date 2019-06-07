#include <sstream>
#include <memory>
#include "../server/server_protocol.h"

Protoc :: Protoc(CommandFactory &commandFactory) : 
    commandFactory(commandFactory) {
}

void splitMessage(std::string &message,std::string &first_place,
  std::string &second_place) {
    std::stringstream ss(message);
    std::string token;
    size_t word_num(0);
    while (getline(ss,token, ',')) {
        if (word_num == 0) first_place = token;
        if (word_num == 1) second_place = token;
        word_num++;
    }      
}


Command* Protoc :: deserialize(std::string &message) {
    std::cout << message << std::endl;
    std::string sender;
    std::string content;    
    splitMessage(message,sender,content);
    if (content == "mates") {// cambiar string por SerializedCommand
        return commandFactory.createCommandMates();
    }
    if (content == "join") {
        return commandFactory.createCommandJoin(sender);
    }
    if (content == "start") {
        return commandFactory.createCommandStart();
    }
    if (content == "d" || content == "a") {
        char direction = (char)content[0];
        return commandFactory.createCommandMove(sender,direction);
    }
    if (content == "w") {
        return commandFactory.createCommandJump(sender);
    }
    return nullptr;
}