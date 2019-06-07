#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "../Window.h"
#include "../Blocks/Metal_block.h"
#include "../Blocks/Stone_block.h"
#include "../Blocks/Launch_block.h"
#include "../Blocks/Shoot_block.h"
#include "../Constants.h"

int main(int argc, char** argv){
    try {
        Window window(800, 600);
        MetalBlock metal(window);
        Rect dest_metal(150, 150, WIDTH_BLOCK_LAUNCH, HEIGHT_BLOCK_LAUNCH);
        LaunchBlock launch(window);
        Rect dest_launch(300, 300, WIDTH_BLOCK_LAUNCH, HEIGHT_BLOCK_LAUNCH);
        StoneBlock stone(window);
        Rect dest_stone(200, 100, WIDTH_BLOCK_LAUNCH, HEIGHT_BLOCK_LAUNCH);
        ShootBlock shoot(window);
        Rect dest_shoot(0, 0, WIDTH_BLOCK_SHOOT, HEIGHT_BLOCK_SHOOT);
        window.fill();
        metal.render(dest_metal);
        launch.render(dest_launch);
        stone.render(dest_stone);
        shoot.render(dest_shoot);
        window.render();
        SDL_Delay(2000);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}