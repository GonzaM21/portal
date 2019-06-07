#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "Window.h"
#include "SdlException.h"
#include "Rect.h"

Sprite::Sprite(const std::string &filename, const Window &window)
    : renderer(window.getRenderer())
{
    this->texture = loadTexture(filename);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(this->texture);
}

SDL_Texture *Sprite::loadTexture(const std::string &filename)
{
    SDL_Surface *image = IMG_Load(filename.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, image);
    if (!texture)
    {
        throw SdlException("Error al cargar la textura", SDL_GetError());
    }
    return texture;
}

int Sprite::render(const Rect &src, const Rect &dest, SDL_RendererFlip flip, float angle) const
{
    SDL_Rect sdlSrc = {
        src.getX(), src.getY(),
        src.getWidth(), src.getHeight()};
    SDL_Rect sdlDest = {
        dest.getX(), dest.getY(),
        dest.getWidth(), dest.getHeight()};
    return SDL_RenderCopyEx(this->renderer, this->texture, &sdlSrc, &sdlDest, angle, nullptr, flip);
}