#ifndef __CAMARA_H__
#define __CAMARA_H__
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "vista/Window.h"
#include "vista/Rect.h"
#include "vista/Sprite.h"

class Camara
{
public:
   /**
     * Crea una camara
     **/
   Camara(const Window &window);
   /**
     * Libera la memoria reservada por la camara
     **/
   ~Camara();
   /**
     * Renderiza la textura recibida por parametro
     **/
   int render(Sprite &sprite, Rect destWorld);
   void setWindow(float x, float y, float width, float height);
   void convertToVirtual(const Rect &worldPostion, Rect &virtualPostion);
   void convertToWorld(Rect &worldPostion, const Rect &virtualPostion);

 private:
   const Window &window;
   int window_width;
   int window_height;
   Rect vision;
};

#endif
