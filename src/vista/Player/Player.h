#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Camara.h"
#include "../Sprite.h"
#include <map>
#include <unordered_map>

/**
 * Clase Player, la cual es el objeto que posee el sprite 
 * correspondiente y su posicion en el mundo real y el estado del mismo
*/
class Player {
public:
  /**
   * Constructor, crea el sprite y setea el destWorld, 
   * y recibe la direccion hacia donde se mueve el player
  */
  Player(const Window &window, const int &direction);

  /**
   * Destructor
  */
  ~Player();
  
  /**
  * Metodo encargado de renderizar el sprite correspondiente
  */
  int render(Camara &camara);

  /**
   * Metodo que setea el estado del jugador
  */
  void setState(const int &state, const int &direction);
  
  /**
   * Setters del estado del jugador
  */
  void setIdle();
  void setFlying();
  void setGrabbed();
  void setDying();
  void setRestIdle();
  void setRunning();
  void setDancing();
  void setRunningShooting();
  void setStop();
  void setRising();
  void setFalling();

  /**
   * Metodo que setea la posicion y el area de 
   * sprite en la textura correspondiente
  */
  void setSrc(int x, int y, int widht, int heigh);
  
  /**
  * Metodo encargado de setear el area y la posicion del objeto en el mundo real
  */
  void setDestWorld(float x, float y, float widht, float heigh);

  /**
  * Getter de la posicion del objeto en el mundo real
  */
  Rect getDestWorld() { return dest_world; };
  
  /**
  * Getter de la posicion de la posicion y el area del 
  * sprite en la textura correspiendente. 
  */
  Rect getSrc();

private:
  Rect dest_world;
  Sprite *sprite;
  int direction;
  typedef void (Player::*player_method_t)();
  std::unordered_map<int, player_method_t> changeState;
  std::unordered_map<int, Sprite *> states;
};

#endif
