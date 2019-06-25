#ifndef __POWERBALL_H__
#define __POWERBALL_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "Flying_powerball.h"
#include "Hitting_powerball.h"
#include "../Camara.h"

/**
 * Clase Powerball, la cual es el objeto que posee el sprite correspondiente y su posicion en el mundo real
*/
class PowerBall {
public:
  /**
   * Constructor que recibe la window, y un state que 
   * define si la powerball esta volando o golpeando y tambien recibe la direccion de la misma
  */
  PowerBall(const Window &window, const int& direction);

  /**
   * Destructor
  */
  ~PowerBall();
  
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

  void setFlying();
  void setHitting();
  bool hitted();
  bool isDone();
  void setState(const int &state, const int &direction);

private:
  Rect dest_world;
  FlyingPowerBall *sprite;
};

#endif
