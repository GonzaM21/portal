#ifndef __METALBLOCK_H__
#define __METALBLOCK_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"
#include "../Camara.h"
#include "Block.h"
#include "Metal_block_sprite.h"

/**
 * Clase MetalBlock, la cual es el objeto que herda de Block y que posee el sprite correspondiente y su posicion en el mundo real
*/
class MetalBlock : public Block
{
public:
  /**
   * Constructor, crea el sprite y setea el destWorld.
  */
	MetalBlock(const Window &window);

  /**
   * Destructor
  */
	~MetalBlock();
	
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
	MetalBlockSprite sprite;
	Rect dest_world;
};

#endif
