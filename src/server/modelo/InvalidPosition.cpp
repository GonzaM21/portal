#include "InvalidPosition.h"

const char* InvalidPosition::what() const noexcept{
    return "Error position outside the world\n";
}