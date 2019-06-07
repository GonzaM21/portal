#include <algorithm>
#include "Filter_Data.h"

Filter_Data::Filter_Data(float cbits) {
    category_bits = cbits;
}

void Filter_Data::Add_Mask_bits(float mb) {
    if (std::find(mask_bits.begin(), mask_bits.end(), mb) != mask_bits.end()){
        return;
    } else {
       mask_bits.push_back(mb);
    }
}
