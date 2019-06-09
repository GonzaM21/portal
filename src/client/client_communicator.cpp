#include <thread>
#include <vector>
#include <sstream>
#include "../client/client_communicator.h"

ClientCommunicator ::ClientCommunicator(SocketConnect socket, std::string &mode,
    std::string &room_name, std::string &player_name, ModelFacade *model_facade) 
    : protocol(std::move(socket)), model_facade(model_facade) {
    this->continue_running = true;
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
    while (this->continue_running) {
        std::string message;
        this->protocol >> message;
        std::cout << message << std::endl;
        std::vector<std::string> arguments;
        splitMessage(message, arguments);
        this->model_facade->decodeMessages(arguments);
    }
}

void ClientCommunicator::splitMessage(std::string &message, std::vector<std::string> &arguments) {
    std::stringstream ss(message);
    std::string token;
    size_t word_num(0);
    while (getline(ss, token, ',')) {
        arguments.push_back(token);
    }
}

void ClientCommunicator ::sendMessage() {
    try {
        while (this->continue_running)
        {
            std::string message;
            message = this->message_queue.pop();
            std::cout << message << std::endl;
            if (!this->continue_running)
              break;
            if (message == "q")
                break;
            if (message == "fullscreen") {
                model_facade->setFullscreen();
                continue;
            }
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
