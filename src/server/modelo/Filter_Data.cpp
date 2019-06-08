#include <algorithm>
#include "Filter_Data.h"

Filter_Data::Filter_Data(uint16_t cbits) {
    category_bits = cbits;
    mask_bits = 0;
}

void Filter_Data::addMaskBits(uint16_t mb) {
    mask_bits |= mb;
}

uint16_t Filter_Data::getCategoryBits() {
    return category_bits;
}

uint16_t Filter_Data::getMaskBits() {
    return mask_bits;
}