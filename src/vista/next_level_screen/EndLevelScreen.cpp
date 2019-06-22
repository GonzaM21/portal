#include "EndLevelScreen.h"
#include "screen_constants.h"
//int top_left_y, int down_right_x, int down_left_x,int down_left_y
EndLevelScreen::EndLevelScreen(Window &window) : window(window),
    next(NEXT_TOP_LEFT_Y,NEXT_DOWN_RIGHT_X,NEXT_DOWN_LEFT_X,NEXT_DOWN_LEFT_Y) ,
    exit(EXIT_TOP_LEFT_Y,EXIT_DOWN_RIGHT_X,EXIT_DOWN_LEFT_X,EXIT_DOWN_LEFT_Y) {
}

bool EndLevelScreen::clickOnExit(int x,int y) {
    return this->exit.clickOnButton(x,y);
}


bool EndLevelScreen::clickOnNext(int x,int y) {
    return this->next.clickOnButton(x,y);
}

void EndLevelScreen::setBackground() {
    this->window.setBackground(BACKGROUND_PATH);
}

void EndLevelScreen::renderScene() {

}