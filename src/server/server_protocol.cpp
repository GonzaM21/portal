#include <sstream>
#include <memory>
#include <vector>
#include "../server/server_protocol.h"

Protoc :: Protoc(CommandFactory &commandFactory) : 
    commandFactory(commandFactory) {
}

void splitMessage(std::string &message,
  std::vector<std::string> &content) {
    std::stringstream ss(message);
    std::string token;
    while (getline(ss,token, ',')) {
        content.push_back(token);
    }      
}


Command* Protoc :: deserialize(std::string &message) {
    std::vector<std::string> content;    
    splitMessage(message,content);
    if (content.at(1) == "mates") {
        return commandFactory.createCommandMates();
    }
    if (content.at(1) == "join") {
        return commandFactory.createCommandJoin(content.at(0));
    }
    if (content.at(1) == "start") {
        return commandFactory.createCommandStart();
    }
    if (content.at(1) == "d" || content.at(1) == "a" || content.at(1) == "s") {
        char direction = (char)content.at(1)[0];
        return commandFactory.createCommandMove(content.at(0),direction);
    }
    if (content.at(1) == "w") {
        return commandFactory.createCommandJump(content.at(0));
    }
    if (content.at(1) == "p")  {//sender,p,x_dest,y_dest,port_num
        return commandFactory.createCommandShoot(content.at(0),content.at(2),
          content.at(3),content.at(4));
    }
    if (content.at(1) == "r")  {
        return commandFactory.createCommandMoveRock(content.at(0));
    }    
    return nullptr;
}