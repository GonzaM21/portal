#ifndef __SPRITE_H__
#define __SPRITE_H__
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Rect.h"

class Sprite
{
public:
    /**
     * Crea un SDL_Texture, lanza una excepción si el filename es inválido
     **/
    Sprite(const std::string &filename, const Window &window);
    /**
     * Libera la memoria reservada por la textura
     **/
    ~Sprite();
    
    /**
     * Renderiza la textura cargada
     **/
    // int render(const Rect &src, const Rect &dest) const;
    int render(const Rect &src, const Rect &dest, SDL_RendererFlip flip = SDL_FLIP_NONE, float angle = 0) const;
    virtual int render(const Rect &dest) = 0;
    virtual bool isDone(){};
    virtual void setSrc(Rect &src){};
    virtual Rect getSrc(){};
    virtual void restart(){};

private:
    SDL_Texture *loadTexture(const std::string &filename);
    SDL_Renderer *renderer;
    SDL_Texture *texture;
};

#endif
