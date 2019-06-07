#ifndef TP4_FILTER_DATA_H
#define TP4_FILTER_DATA_H

#include <vector>


class Filter_Data {
    std::vector<float> mask_bits;
    float category_bits;
public:
    Filter_Data(float cbits);
    void Add_Mask_bits(float mb);
};
#endif
