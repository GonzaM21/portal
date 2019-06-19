#include "button.h"

SDLButton::SDLButton(int top_left_y, int down_right_x, int down_left_x,int down_left_y) {
    this->initial_x = down_left_x;
    this->final_x = down_right_x;
    this->initial_y = down_left_y;
    this->final_y = top_left_y;
}

bool SDLButton::clickOnButton(int x, int y) {
    bool in_x_range = (this->initial_x<x && this->final_x>x);
    bool in_y_range = (this->initial_y<y && this->final_y>y);
    return (in_x_range && in_y_range);
}

