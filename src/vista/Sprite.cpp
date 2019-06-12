#include "Sprite.h"
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
}

Sprite::~Sprite()
{
}

int Sprite::render(const Rect &src, const Rect &dest, SDL_RendererFlip flip, float angle) const
{
    SDL_Rect sdlSrc = {
        (int)src.getX(), (int)src.getY(),
        (int)src.getWidth(), (int)src.getHeight()};
    SDL_Rect sdlDest = {
        (int)dest.getX(), (int)dest.getY(),
        (int)dest.getWidth(), (int)dest.getHeight()};
    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest, angle, nullptr, flip);
}