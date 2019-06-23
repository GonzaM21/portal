#ifndef __SPRITE_H__
#define __SPRITE_H__
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Rect.h"

/**
 * Clase encargada de renderizar el sprite correspondiente 
 **/
class Sprite {
public:
    /**
     * Constructor, recibe una textura y un window, y setea los atributos, 
     * tambien genera un mapa de colores posibles para teñir los sprites
     **/
    Sprite(SDL_Texture *texture, const Window &window);
    
    /**
     * Destructor
     **/
    virtual ~Sprite();
    
    /**
     * Renderiza la textura cargada, y esta puede ser modificada, 
     * es decir girada, o teñida de ottro color
     **/
    int render(const Rect &src, const Rect &dest, SDL_RendererFlip flip = SDL_FLIP_NONE, float angle = 0, const int &color = 0) const;
    
    /**
     * Metodo abstracta la cual recibe el dest en pantalla 
     * donde debe ser renderizado la textura
     **/
    virtual int render(const Rect &dest) = 0;
    
    /**
     * Metodo que devuelve se la animacion del sprite esta finalizada
     **/
    virtual bool isDone(){return true;};
    
    /**
     * Setter del src, es decir el tamaño del sprite en el archivo
     **/
    virtual void setSrc(Rect &src){this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());};
    
    /**
     * Getter del src
     **/ 
    virtual Rect getSrc() { return src; };
    
    /**
     * Metodo que reinicia la animacion del sprite
     **/
    virtual void restart(){};
    
    /**
     * Metodo que settea la direccion del sprite, es decir, izquierda o derecha.
     **/
    virtual void setDirection(const int& direction){this->direction = direction;};

    /**
     * Metodo que agrega un color al mapa de posibles colores para teñir los sprites.
     **/
    void addColor(const int &id, const int &r, const int &g, const int &b);

private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Rect src;
    int direction;
    std::map<Uint8, std::vector<int>> colors;
};

#endif
