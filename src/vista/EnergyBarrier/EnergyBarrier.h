#ifndef __ENERGYBARRIER_H__
#define __ENERGYBARRIER_H__
#include <string>
#include "vista/Rect.h"
#include "vista/Window.h"
#include "vista/Sprite.h"
#include "vista/Camara.h"
#include <unordered_map>

/**
 * Clase EnergyBarrier, la cual es el objeto que posee el sprite correspondiente y su posicion en el mundo real
*/
class EnergyBarrier {
public:
  /**
   * Constructor, crea el sprite y setea el destWorld, y 
   * recibe un codigo dependiendo de si la barrera es vertical o horizontal
  */
  EnergyBarrier(const Window &window, const int &code);
  ~EnergyBarrier();
  
  /**
   * Metodo encargado de renderizar el sprite correspondiente
  **/
  int render(Camara &camara);
  
  /**
   * Metodo encargado de setear el area y la posicion del objeto en el mundo real
  **/
  void setDestWorld(float x, float y, float widht, float heigh);

  /**
   * Getter de la posicion del objeto en el mundo real
  **/
  Rect getDestWorld() { return dest_world; };

private:
  Rect dest_world;
  Sprite *sprite;
};

#endif
