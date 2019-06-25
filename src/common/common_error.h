#ifndef ERROR_H
#define ERROR_H
#include <iostream>
#include <stdexcept>
#include <exception>
#include <typeinfo>

/*
* Clase para levantar excepciones de desconecxion
*/

class Error : public std::exception {
    public:
        int disconnection_error();
};

#endif
