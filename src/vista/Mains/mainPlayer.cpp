#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include <chrono>
#include "../Window.h"
#include "../Player/Player.h"
#include "../Camara.h"

int main(int argc, char** argv){
    try {
        Window window(800, 600);
        Camara camara(window);
        Player player(window);
        // player.setIdle();
        // Rect dest_a(0,0,200,400);
        // for (size_t i = 0; i < 25; i++) {
        //   window.fill();
        //   player.render(dest_a);
        //   window.render();
        //   SDL_Delay(100);
        // }
        player.setRunningShooting();
        int x = 0;
        int y = 0;
        Rect dest(x,y,200,400);
        // for (size_t i = 0; i < 25; i++) {
        //   window.fill();
        //   x += 50;
        //   x %= 800;
        //   dest.set(x,y,200,400);
        //   player.render(dest);
        //   window.render();
        //   SDL_Delay(25);
        // }

        player.setStop();
        // player.setDying();
        // x = 0;
        // y = 0;
        for (size_t i = 0; i < 75; i++) {
          window.fill();
          dest.set(x,y,200,400);
          // x += 50;
          // x %= 800;
          player.render(dest);
          window.render();
          SDL_Delay(20);
        }
        // player.setDying();
        // for (size_t i = 0; i < 50; i++) {
        //   window.fill();
        //   player.render();
        //   window.render();
        //   SDL_Delay(80);
        // }
        // player.setRestIdle();
        // for (size_t i = 0; i < 200; i++) {
        //   window.fill();
        //   player.render(dest);
        //   window.render();
        //   SDL_Delay(50);
        // }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}