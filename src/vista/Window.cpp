#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "SdlException.h"
#include "Window.h"
#include "Constants.h"
#include <iostream>

Window::Window(int width, int height) : width(width), height(height), fullscreened(false)
{
    int errCode = SDL_Init(SDL_INIT_EVERYTHING);
    if (errCode) {
        throw SdlException("Error en la inicialización", SDL_GetError());
    }
    uint32_t flags = SDL_WINDOW_RESIZABLE  | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;
    errCode = SDL_CreateWindowAndRenderer(
        width, height, flags,
        &this->window, &this->renderer);
    if (errCode) {
        throw SdlException("Error al crear ventana", SDL_GetError());
    }
    SDL_Surface *image = IMG_Load(ICON_FILENAME);
    SDL_SetWindowIcon(window, image);
    MusicBase::getInstance()->playMusic(AMBIENT_MUSIC_ID,10);
}

void Window::setBackground(const char *background) {
    SDL_Surface *image = IMG_Load(background);
    this->background = SDL_CreateTextureFromSurface(this->renderer, image);
}

Window::~Window() {
    if (this->renderer) {
        SDL_DestroyRenderer(this->renderer);
        this->renderer = nullptr;
    }

    if (this->window) {
        SDL_DestroyWindow(this->window);
        this->window = nullptr;
    }
}

void Window::fill() {
    SDL_RenderClear(this->renderer);
    int width,height;
    this->getSize(width,height);
    SDL_Rect sdlSrc = {0, 0,1920,1080}; //habria que cambiar esto (harcodeado)
    SDL_Rect sdlDest = {0, 0,width,height};
    SDL_RenderCopyEx(this->renderer, this->background, &sdlSrc, &sdlDest, 0, nullptr, SDL_FLIP_NONE);
}

void Window::render() {
    SDL_RenderPresent(this->renderer);
}

SDL_Renderer *Window::getRenderer() const {
    return this->renderer;
}

void Window::getSize(int &width, int &height) const {
    SDL_GetWindowSize(this->window, &width, &height);
}

void Window::fullscreen() {   
    if (fullscreened == true) {
        SDL_SetWindowFullscreen(this->window, 0);
        SDL_SetWindowSize(this->window, 800, 600);
        fullscreened = false;
    } else {
        SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        fullscreened = true;
    }
}