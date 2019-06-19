#ifndef END_LEVEL_SCREEN_H
#define END_LEVEL_SCREEN_H
#include "button.h"

class EndLevelScreen {
private:
    SDLButton next;
    SDLButton exit;
public:
    EndLevelScreen();
    ~EndLevelScreen() = default;
    bool clickOnExit(int x,int y);
    bool clickOnNext(int x,int y);
};

#endif