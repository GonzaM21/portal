#ifndef __WINDOW_H__
#define __WINDOW_H__
#include "MusicBase.h"
class SDL_Window;
class SDL_Renderer;
class SDL_Texture;

class Window
{
public:
    /**
     * Ctor standalone
     */
    Window(int width, int height);
    ~Window();
    void fill();
    void fill(int r, int g, int b, int alpha);
    void render();
    SDL_Renderer *getRenderer() const;
    void fullscreen();
    void getSize(int &width, int &height) const;
    void setBackground(const char *background);

private:
    int width;
    SDL_Texture *background; 
    int height;
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool fullscreened;
};

#endif
