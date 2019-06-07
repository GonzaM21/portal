#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "../Window.h"
#include "../Button/Button.h"
#include "../Constants.h"

int main(int argc, char** argv){
    try {
        Window window(800, 600);
        Button button(window);
        Rect dest(150, 150, WIDTH_BUTTON_OFF, HEIGHT_BUTTON_OFF);
        button.setUnpressed();
        for (size_t i = 0; i < 25; i++) {
          window.fill();
          button.render(dest);
          if (i == 12) {
            button.setPressed();
          }
          
          window.render();
          SDL_Delay(200);
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}