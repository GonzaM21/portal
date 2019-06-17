#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Window.h"
#include "SdlException.h"
#include "Rect.h"

Sprite::Sprite(SDL_Texture* texture, const Window &window)
    : renderer(window.getRenderer()), src(-1,-1,-1,-1)
{
    this->texture = texture;
    addColor(1, 250,25,26);
    addColor(2, 100, 100, 160);
    addColor(3, 220, 25, 26);
    addColor(4, 250, 38, 95);
    addColor(5, 200, 0, 46);
    addColor(6, 150, 49, 0);
    addColor(7, 165, 45, 127);
    addColor(8, 147, 0, 36);
}

void Sprite::addColor(const int& id, const int& r, const int& g, const int& b) {
    colors[id].push_back(r);
    colors[id].push_back(g);
    colors[id].push_back(b);
}

int Sprite::render(const Rect &src, const Rect &dest, SDL_RendererFlip flip, float angle,const int& color) const
{
    SDL_Rect sdlSrc = {
        (int)src.getX(), (int)src.getY(),
        (int)src.getWidth(), (int)src.getHeight()};
    SDL_Rect sdlDest = {
        (int)dest.getX(), (int)dest.getY(),
        (int)dest.getWidth(), (int)dest.getHeight()};
    if (color != 0)
    {
        SDL_SetTextureColorMod(this->texture, colors.at(color)[0], colors.at(color)[1], colors.at(color)[2]);
    }
    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest, angle, nullptr, flip);
}

Sprite::~Sprite()
{
}
