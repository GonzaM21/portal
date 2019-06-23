#ifndef CLIENT_CONTROLLER_H
#define CLIENT_CONTROLLER_H
#include "event_handler_thread.h"
#include "qt_executor.h"
#include "renderable.h"
#include "scene_manager.h"
#include "Joiner.h"
#include "client_deserializer.h"
#include "client_communicator.h"
#include "data_container.h"
#include "local_scene_logic.h"

/*
* Clase principal encargada de controlar al cliente
* a lo largo de la ejecucion del programa.
*/

class ClientController {
private:
    ClientCommunicator* communicator;
    EventHandlerThread* handler;
    Renderable* renderer_thread;
    bool continue_running;
    bool map_received;
    bool end_game;
    bool waiting_next_level;
    bool end_level;
    bool receive_error;

    //Inicializa los hilos necesarios para comunicacion 
    //con el servidor.
    void initializeCommunication(); 

    //Evalua las variables locales realizando las acciones que correspon.
    void evaluateLocalVariables(LocalSceneLogic &local_scene_logic,
      SceneManager &scene_manager);
    
    //Actualiza las variables de client_controller con la informacion
    //de data_container
    void updateControllerVariables(DataContainer *data_container);

    void updateLocalScene(LocalSceneLogic &local_scene_logic,
      SceneManager &scene_manager);

    //Indica si hubo una accion en la escena local que produsca
    //el envio de un mensaje al servidor (el cliente esta en la
    //pantalla de fin de juego o siguiente nivel y realizo una accion)
    //bool localSceneAction(LocalSceneLogic &local_scene_logic);

    void updateClientAction(LocalSceneLogic &local_scene_logic,
      SceneManager &scene_manager);

public:
    ClientController();
    ~ClientController() =default;

    //Se encarga de ejecutar la ventana inicial de qt. 
    //La misma contendra el editor de mapa o un menu
    //que pida los datos para conectarse al servidor.
    int runInitialWindow(int argc, char *argv[]);

    //Setea las variables necesarias para finalizar 
    //la ejecucion del ClientController
    void endExecution();

    //Loop principal del cliente
    void mainLoop();

    //En caso que falle la ventana de qt se produce una 
    //salida fallida donde se cierran los hilos ya inicializados
    void failureExit();
};

#endif
