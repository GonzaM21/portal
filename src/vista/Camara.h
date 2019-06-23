#ifndef __CAMARA_H__
#define __CAMARA_H__
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Rect.h"
#include "Sprite.h"

/**
 * Clase camara, es la clase encargada de mantener centrada la camara en el jugador 
*/
class Camara {
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
   * Renderiza el sprite recibido por parametro
   **/
  int render(Sprite &sprite, Rect destWorld);

  /**
   * Metodo que setea la posicion de la camara
  */
  void setCamara(float x, float y);

  /**
   * Metodo que combierte un area con medidas del mundo real en medidas de mundo virtual
  */
  void convertToVirtual(const Rect &worldPostion, Rect &virtualPostion);

  /**
   * Metodo que combierte un area con medidas del mundo virtual en medidas de mundo real
  */
  void convertToWorld(Rect &worldPostion, const Rect &virtualPostion);

 private:
   const Window &window;
   int window_width;
   int window_height;
   Rect vision;
};

#endif
