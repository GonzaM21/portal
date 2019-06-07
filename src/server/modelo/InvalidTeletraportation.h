#ifndef TP4_INVALIDTELETRAPORTATION_H
#define TP4_INVALIDTELETRAPORTATION_H

#include <exception>

class InvalidTeletraportation : public std::exception{
public:
    virtual const char* what() const noexcept override;
};


#endif //TP4_INVALIDTELETRAPORTATION_H
