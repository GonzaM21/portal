#ifndef __ROCK_H__
#define __ROCK_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Camara.h"
#include "../Sprite.h"

/**
 * Clase Roca, la cual es el objeto que posee el sprite correspondiente y su posicion en el mundo real
*/
class Rock {
public:
  /**
   * Constructor que recibe la window
  */
  Rock(const Window &window);

  /**
   * Destructor
  */
  ~Rock();
  
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

private:
  Rect dest_world;
  Sprite *sprite;
};

#endif
