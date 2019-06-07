#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "../Window.h"
#include "../Acid/Acid.h"

int main(int argc, char** argv){
    try {
        Window window(800, 600);
        Acid acid(window);
        Rect dest(150, 150, 400, 50);
        for (size_t i = 0; i < 25; i++) {
          window.fill();
          acid.render(dest);
          if (i == 12) {
            acid.setTouched();
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