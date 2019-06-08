#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include "SdlException.h"
#include "Window.h"
#include "Constants.h"
#include <iostream>

Window::Window(int width, int height) : width(width), height(height), fullscreened(false)
{
    int errCode = SDL_Init(SDL_INIT_VIDEO);
    if (errCode)
    {
        throw SdlException("Error en la inicialización", SDL_GetError());
    }
    uint32_t flags = SDL_WINDOW_RESIZABLE | SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    errCode = SDL_CreateWindowAndRenderer(
        width, height, flags,
        &this->window, &this->renderer);
    if (errCode)
    {
        throw SdlException("Error al crear ventana", SDL_GetError());
    }
    SDL_Surface *image = IMG_Load(ICON_FILENAME);
    SDL_SetWindowIcon(window, image); // The icon is attached to the window pointer  
}

Window::~Window()
{
    if (this->renderer)
    {
        SDL_DestroyRenderer(this->renderer);
        this->renderer = nullptr;
    }

    if (this->window)
    {
        SDL_DestroyWindow(this->window);
        this->window = nullptr;
    }
}

void Window::fill(int r, int g, int b, int alpha)
{
    SDL_SetRenderDrawColor(this->renderer,
                           r, g, b, alpha);
    SDL_RenderClear(this->renderer);
}

void Window::fill()
{
    this->fill(0x33, 0x33, 0x33, 0xFF);
}

void Window::render()
{
    SDL_RenderPresent(this->renderer);
}

SDL_Renderer *Window::getRenderer() const
{
    return this->renderer;
}

void Window::getSize(int &width, int &height) const
{
    SDL_GetWindowSize(this->window, &width, &height);
}

void Window::fullscreen()
{   
    std::cout << fullscreened << std::endl;
    if (fullscreened == true)
    {
        SDL_SetWindowFullscreen(this->window, 0);
        SDL_SetWindowSize(this->window, 800, 600);
        fullscreened = false;
    }
    else
    {
        SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        fullscreened = true;
    }
}