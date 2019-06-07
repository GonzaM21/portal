#ifndef SENDER_H
#define SENDER_H
#include <string>
#include <map>
#include "../common/common_cola_protegida.h"

class Sender {
    private:
        std::map<std::string,ColaProtegida*> colas;
        
    public:
        Sender() = default;
        ~Sender();
        void endExecution(); 
        void addPlayer(const std::string &name);
        void addMessageToSend(std::string &message);
        std::string getMessageFor(const std::string &name);
        void sendMessageTo(const std::string &player,std::string &message); 

};

#endif
