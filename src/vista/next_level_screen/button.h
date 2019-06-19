#ifndef SDL_BUTTON_H
#define SDL_BUTTON_H

class SDLButton {
private:
    int final_x;
    int final_y;
    int initial_x;
    int initial_y;

public:
    SDLButton(int top_left_y, int down_right_x, int down_left_x,int down_left_y);
    ~SDLButton() = default;
    bool clickOnButton(int x,int y);
};

#endif