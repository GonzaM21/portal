#ifndef __TRIANGLEBLOCK_H__
#define __TRIANGLEBLOCK_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"
#include "../Camara.h"
#include "Block.h"
#include "Triangle_block_sprite.h"

/**
 * Clase TriangleBlock, la cual es el objeto que herda de Block y que posee el sprite correspondiente y su posicion en el mundo real
*/
class TriangleBlock : public Block
{
public:
  /**
   * Constructor, crea el sprite y setea el destWorld, 
   * recibe tambien el codigo del bloque a crear, 
   * este indica la orientacion del bloque.
  */
  TriangleBlock(const Window &window, const int& code);

  /**
   * Desructor
  */
  ~TriangleBlock();
  
  /*
  * Metodo encargado de renderizar el sprite correspondiente
  */
  virtual int render(Camara &camara) override;
  
  /*
  * Metodo encargado de setear la posicion y el area del objeto en el mundo real
  */
  virtual void setDestWorld(float x, float y, float widht, float height) override;
  
  /*
  * Metodo getter de la posicion y el area del objeto en el mundo real, devuelve un objeto del tipo Rect
  */
  virtual Rect getDestWorld() override { return dest_world; };

private:
  TriangleBlockSprite sprite;
  Rect dest_world;
};

#endif
