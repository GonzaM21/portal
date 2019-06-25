#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Camara.h"
#include "../Sprite.h"

/**
 * Clase abstracta Block, de la cual heredan los distintos tipos de bloques
*/
class Block {
public:

  /**
   * Constructor
  */
  Block(){};

  /**
   * Destructor
  */
  virtual ~Block(){};

  /**
   * Metodo abstracto que heredan las clases hijas, que renderiza el sprite crespondiente
  */
  virtual int render(Camara &camara) = 0;

  /**
   * Metodo abstracto que heredan las clases hijas, que setea la posicion del objeto en mundo real
  */
  virtual void setDestWorld(float x, float y, float widht, float heigh) = 0;

  /**
   * Metodo abstracto que heredan las clases hijas, getter de la posicion del objeto en mundo real
  */
  virtual Rect getDestWorld() = 0;

};

#endif
