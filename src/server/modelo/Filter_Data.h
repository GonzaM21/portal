#ifndef TP4_FILTER_DATA_H
#define TP4_FILTER_DATA_H

#include <iostream>

class Filter_Data {
    uint16_t mask_bits;
    uint16_t category_bits;
public:
    Filter_Data(uint16_t cbits);
    void addMaskBits(uint16_t mb);
    uint16_t getCategoryBits();
    uint16_t getMaskBits();

};
#endif
