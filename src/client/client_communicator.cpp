#include <thread>
#include <vector>
#include "client_communicator.h"

ClientCommunicator ::ClientCommunicator() {
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
    this->sender_queue.push(message);
}

std::string ClientCommunicator::popMessageReceived() {
    return this->receiver_queue.pop();
}

void ClientCommunicator::receiveMessage() {
    try {
        while (this->continue_running) {
            std::string message;
            this->protocol >> message;
            this->receiver_queue.push(message);
        }
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error inesperado" << std::endl;
    }
}

std::vector<std::string> ClientCommunicator::getMates() {
    std::vector<std::string> vect;
    vect.push_back("la re concha de la lora");
    return std::move(vect);
}

std::string ClientCommunicator::getMode() {
    return "la re concha de la lora";
}

void ClientCommunicator ::sendMessage() {
    try {
        while (this->continue_running) {
            std::string message(this->sender_queue.pop());
            if (!this->continue_running || message == "m") break;
            this->protocol << message;
        }
        this->endExecution();
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Error inesperado" << std::endl;
    }
}

void ClientCommunicator ::run() {
    this->sender = std::thread(&ClientCommunicator::sendMessage, this);
    this->receiveMessage();
}

void ClientCommunicator ::endExecution() {
    this->continue_running = false;
    this->sender_queue.set_terminar_ejecucion();
    this->receiver_queue.set_terminar_ejecucion();
    this->protocol.closeProtocol();
}

bool ClientCommunicator::isRunnning() {
    return this->continue_running;
}