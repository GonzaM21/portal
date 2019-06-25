#ifndef CLIENT_ACCEPTOR_H
#define CLIENT_ACCEPTOR_H
#include <vector>
#include "server_socket_accept.h"
#include "server_communicator.h"
#include "../common/Thread.h"

/* Esta clase se encarga de aceptar nuevos clientes
*  al servidor.
*/

class ClientAcceptor : public Thread {
    private:
        SocketAccept *socket;
        bool continue_running;
        int current_id;

    public:
        ClientAcceptor(SocketAccept &socket);
        ~ClientAcceptor() = default;
        virtual void run() override;
        void endExecution(); 
};


#endif
