#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include "../common/common_cola_protegida.h"

ColaProtegida :: ColaProtegida() {
    terminar_ejecucion = false;
}

ColaProtegida :: ~ColaProtegida() { 
    /*No hace nada*/
}

void ColaProtegida :: push(std::string message) {
    std::unique_lock<std::mutex> lock(m);
    //std::cout << "Se pusheo: " << message << "\n";
    cola.push(message);
    cond_var.notify_one();
}

void ColaProtegida :: set_terminar_ejecucion() {
    terminar_ejecucion = true;
    cond_var.notify_all();
}

std::string ColaProtegida :: pop() { 
    //std::cout << "Se entro al pop\n";
    std::unique_lock<std::mutex> lock(m);
    //std::cout << cola.size() << std::endl;
    while (cola.empty() && !terminar_ejecucion) {
        cond_var.wait(lock);
    }
    if (terminar_ejecucion) {
        if (cola.empty()) {
            return "NULL";
        } 
    }
    std::string message = cola.front();
    cola.pop();
    //std::cout << cola.size() << std::endl;
    //std::cout << "Se popeo: " << message << "\n";
    return message;
}

//ColaProtegida :: ColaProtegida(ColaProtegida&& other) {
//    this->cola = std::move(other.cola);
//    this->notificar = std::move(other.notificar);
//    this->terminar_ejecucion = std::move(other.terminar_ejecucion);
//}
//
//ColaProtegida& ColaProtegida :: operator=(ColaProtegida&& other) {
//    this->cola = std::move(other.cola);
//    this->notificar = std::move(other.notificar);
//    this->terminar_ejecucion = std::move(other.terminar_ejecucion);
//    return *this;
//}