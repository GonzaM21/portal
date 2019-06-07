#include <iostream>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include "../common/common_error.h"

int Error :: disconnection_error() {
    throw std::runtime_error("Error: the connection was lost");
}
