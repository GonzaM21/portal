#ifndef TP4_FILTER_DATA_H
#define TP4_FILTER_DATA_H

#include <iostream>

//Clase para los filtros de colsiones

class Filter_Data {
    uint16_t mask_bits;
    uint16_t category_bits;
public:
    //Constructor
    Filter_Data(uint16_t cbits);
    //agrega un ot de bits para las colsiones
    void addMaskBits(uint16_t mb);
    //retirna el valor asignaod para sus colsiones
    uint16_t getCategoryBits();
    //retorna los valoresde bits con lo que peude colisionar
    uint16_t getMaskBits();

};
#endif
