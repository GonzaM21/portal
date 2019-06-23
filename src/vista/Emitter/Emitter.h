#ifndef __EMITTER_H__
#define __EMITTER_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"
#include "Emitter_sprite.h"
#include "Emitter/Target_sprite.h"
#include "../Camara.h"

/**
 * Clase Emitter, la cual es el objeto que posee el sprite correspondiente y su posicion en el mundo real
*/
class Emitter {
public:
	/**
   * Constructor, crea el sprite y setea el destWorld, y tambien recibe, un code 
	 * que indica que bloque crear, seguen la orientacion, y un estado dependiendo de si esta cargado o no el emisor
  */
	Emitter(const Window &window, const int &code, const int &state);

	/**
	 * Destructor
	*/
	~Emitter();

	/**
	* Metodo encargado de renderizar el sprite correspondiente
	*/
	int render(Camara &camara);
	
	/**
  * Metodo encargado de setear el area y la posicion del objeto en el mundo real
  */
	void setDestWorld(float x, float y, float widht, float height);

	/**
  * Getter de la posicion del objeto en el mundo real
  */
	Rect getDestWorld() { return dest_world; };

  /**
  * Metodo encargado de setaer el estado del objeto recibido por parametro con un id
  */
  void setState(const int& state);

private:
	Rect dest_world;
	EmitterSprite sprite;
	TargetSprite* inactive;
};

#endif
