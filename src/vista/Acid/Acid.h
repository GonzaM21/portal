#ifndef __ACID_H__
#define __ACID_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Sprite.h"
#include <string>
#include "../Camara.h"

/**
 * Clase Acid, la cual es el objeto que posee el sprite correspondiente y su posicion en el mundo real
*/
class Acid {
public:

  /**
   * Constructor
  */
  Acid(const Window &window);

  /**
   * Destructor
  */
  ~Acid();

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
