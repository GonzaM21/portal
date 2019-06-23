#ifndef __PORTAL_H__
#define __PORTAL_H__
#include <string>
#include "Rect.h"
#include "Window.h"
#include "Camara.h"

/**
 * Clase Portal, la cual es el objeto que posee el sprite correspondiente y su posicion en el mundo real
*/
class Portal {
public:
  /**
   * Constructor que recibe la window, y un codigo que 
   * define portal es y tambien recibe la direccion del portal, es decir a donde apunta
  */
  Portal(const Window &window, const int &code, const int &direction);
  
  /**
   * Destructor
  */
  ~Portal();
  
  /**
  * Metodo encargado de renderizar el sprite correspondiente
  */
  int render(Camara &camara);

  /**
  * Metodo encargado de setear el area y la posicion del objeto en el mundo real
  */
  void setDestWorld(float x, float y, float widht, float heigh);

  /**
  * Getter de la posicion del objeto en el mundo real
  */
  Rect getDestWorld() { return dest_world; };

  /**
   * Setea la direccion del portal, es decir a donde apunta
  */
  void setDirection(const int &direction);

private: 
  Rect dest_world;
  Sprite *sprite;
};

#endif
