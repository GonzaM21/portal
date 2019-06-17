#include <thread>
#include <vector>
#include <sstream>
#include "client/client_communicator.h"

ClientCommunicator ::ClientCommunicator(ModelFacade *model_facade) 
    : model_facade(model_facade) {
    this->continue_running = true;
}

void ClientCommunicator::set(SocketConnect socket,
        std::string mode, std::string room_name,
        std::string player_name) {
    this->protocol.setSocket(std::move(socket)); 
    this->protocol << mode;
    this->protocol << room_name;
    this->protocol << player_name;
}

ClientCommunicator::~ClientCommunicator() {
    sender.join();
}

void ClientCommunicator::addMessageToSend(std::string message) {
    this->message_queue.push(message);
}

void ClientCommunicator::receiveMessage() {
    this->receiveMap();
    while (this->continue_running) {
        std::string message;
        this->protocol >> message;
        std::vector<std::string> arguments;
        std::cout << message << std::endl;
        splitMessage(message, arguments);
        if (arguments.at(0).substr(0,5) == "Error") {
            this->endExecution();
            message_queue.set_terminar_ejecucion();
            break;
        };
        this->model_facade->decodeMessages(arguments);
    }
}

std::vector<std::string> ClientCommunicator::getMates() {
    std::cout << "lleho" << std::endl;
    std::string mates("mates"); 
    this->protocol << mates;
    std::string message;
    this->protocol >> message;
    std::vector<std::string> arguments;
    std::cout << message << std::endl;
    splitMessage(message, arguments);
    return arguments;
}

void ClientCommunicator::splitMessage(std::string &message, std::vector<std::string> &arguments) {
    std::stringstream ss(message);
    std::string token;
    while (getline(ss, token, ',')) {
        arguments.push_back(token);
    }
}

void ClientCommunicator ::receiveMap()
{
    while (!this->received_map)
    {
        std::string msg;
        this->protocol >> msg;
        // std::cout << msg << std::endl;
        if (msg == "F")
        {
            this->received_map = true;
            return;
        }
        std::vector<std::string> arguments;
        splitMessage(msg, arguments);
        if (arguments.at(0).substr(0,5) == "Error") {
            this->endExecution();
            message_queue.set_terminar_ejecucion();
            break;
        };
        this->model_facade->decodeMessages(arguments);
    }
}

bool ClientCommunicator::getReceivedMap()
{
    return this->received_map;
}

void ClientCommunicator ::sendMessage() {
    try {
        while (this->continue_running)
        {
            std::string message("NULL");
            message = this->message_queue.pop();
            if (!this->continue_running)
              break;
            if (message == "q")
                break;
            this->protocol << message;
        }
        this->endExecution();
        message_queue.set_terminar_ejecucion();
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error inesperado(?)" << std::endl;
    }
}

void ClientCommunicator ::startExecution() {
    this->sender = std::thread(&ClientCommunicator::sendMessage, this);
    this->receiveMessage();
}

void ClientCommunicator ::endExecution() {
    this->continue_running = false;
    this->protocol.closeProtocol();
}

bool ClientCommunicator::isRunnning() {
    return this->continue_running;
}