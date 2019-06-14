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
    addColor(1,250,25,26);
}

void Sprite::addColor(const int& id, const int& r, const int& g, const int& b) {
    colors[id].push_back(r);
    colors[id].push_back(g);
    colors[id].push_back(b);
}
Sprite::~Sprite()
{
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