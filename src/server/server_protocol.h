#ifndef PROTOC_H
#define PROTOC_H
#include <string>
#include "server_command_factory.h"
#include "server_command.h"

class Protoc {
private:
    CommandFactory &commandFactory;

public:
    Protoc(CommandFactory &commandFactory);
    ~Protoc() = default;
    Command *deserialize(std::string &message);
};

#endif