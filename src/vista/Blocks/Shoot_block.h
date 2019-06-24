#ifndef __SHOOTBLOCK_H__
#define __SHOOTBLOCK_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"
#include "../Camara.h"
#include "Block.h"
#include "Shoot_block_sprite.h"

/**
 * Clase ShootBlock, la cual es el objeto que herda de Block y que posee el sprite correspondiente y su posicion en el mundo real
*/
class ShootBlock : public Block
{
public:
  /**
   * Constructor, crea el sprite y setea el destWorld.
  */
  ShootBlock(const Window &window);
	
  /**
   * Destructor
  */
  ~ShootBlock();
	
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
	ShootBlockSprite sprite;
	Rect dest_world;
};

#endif
