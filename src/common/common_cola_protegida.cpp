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

void ColaProtegida :: push(std::string &message) {
    std::unique_lock<std::mutex> lock(m);
    cola.push(message);
    cond_var.notify_one();
}

void ColaProtegida :: set_terminar_ejecucion() {
    terminar_ejecucion = true;
    cond_var.notify_all();
}

std::string ColaProtegida :: pop() { 
    std::unique_lock<std::mutex> lock(m);
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
    return message;
}
