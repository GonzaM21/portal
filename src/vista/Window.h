#ifndef __WINDOW_H__
#define __WINDOW_H__
#include "MusicBase.h"
class SDL_Window;
class SDL_Renderer;
class SDL_Texture;

/**
 * Clase encargada de renderizar todo, al momento de 
 * que ya se cargo todo en el renderer.
 */
class Window {
public:
    /**
     * Constructor de la ventana
     */
    Window(int width, int height);

    /**
     * Destructor de la ventana
     */
    ~Window();

    /**
     * Rellena la pantala con el fondo de pantalla cargado 
     */
    void fill();

    /**
     * rendera el renderer presente
     */
    void render();
    
    /**
     * getter del renderer
     */
    SDL_Renderer *getRenderer() const;
    
    /**
     * Setea la pantalla fullscreen o no dependiendo de si estaba en fullscreen o no
     */ 
    void fullscreen();
    
    /**
     * Getter del size de la ventana 
     */
    void getSize(int &width, int &height) const;

    /**
     * Setter del background
     */
    void setBackground(const char *background);

private:
    int width;
    SDL_Texture *background; 
    int height;
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool fullscreened;
    MusicBase * musicPlayer;
};

#endif
