#ifndef END_LEVEL_SCREEN_H
#define END_LEVEL_SCREEN_H
#include "button.h"
#include "../Window.h"

class EndLevelScreen {
private:
    Window window;
    SDLButton next;
    SDLButton exit;
public:
    EndLevelScreen(Window &window);
    ~EndLevelScreen() = default;
    bool clickOnExit(int x,int y);
    bool clickOnNext(int x,int y);
    void renderScene();
};

#endif