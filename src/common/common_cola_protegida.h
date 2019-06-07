#ifndef COLA_PROTEGIDA_H
#define COLA_PROTEGIDA_H

#include <queue>
#include <map>
#include <vector>
#include <mutex>
#include <condition_variable>

class ColaProtegida {
    private:
        std::queue<std::string> cola;
        std::mutex m;
        bool notificar;
        std::condition_variable cond_var;
        bool terminar_ejecucion;

    public:
        ColaProtegida();
        ~ColaProtegida();

        //Recive por parametro un puntero a un string.
        //Inserta un nuevo elemento a la cola.
        void push(std::string message);

        //En caso que la cola no este vacia devuelve string
        //si la misma esta vacia devuelve un puntero a null.
        std::string pop();

        //Modifica el atributo terminar_ejecucion de la cola, 
        //su valor pasa a ser true.
        void set_terminar_ejecucion();

        //ColaProtegida& operator=(const ColaProtegida&) = delete;
        //ColaProtegida(ColaProtegida&& other);
        //ColaProtegida& operator=(ColaProtegida&& other);
        //ColaProtegida(ColaProtegida&) = delete;
};


#endif
