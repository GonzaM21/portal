#ifndef TP4_INVALIDPOSITION_H
#define TP4_INVALIDPOSITION_H
#include <exception>

class InvalidPosition : public std::exception{
public:
    virtual const char* what() const noexcept override;
};

#endif //TP4_INVALIDPOSITION_H
