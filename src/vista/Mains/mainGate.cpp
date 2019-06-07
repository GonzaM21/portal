#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "../Window.h"
#include "../Gate/Gate.h"
#include "../Rect.h"

int main(int argc, char** argv){
    try {
        Window window(800, 600);
        window.fill();
        Gate gate(window);
        Rect dest(0,0,200,400);
        gate.render(dest);
        window.render();
        SDL_Delay(2000);
        gate.setOpening();
        while (!gate.isOpen()){
            window.fill();
            gate.setOpening();
            gate.render(dest);
            window.render();
            SDL_Delay(100);
        }        
        gate.setClosing();
        while (!gate.isClosed()){
            window.fill();
            gate.setClosing();
            gate.render(dest);
            window.render();
            SDL_Delay(100);
        }        
        SDL_Delay(2000);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
