#ifndef __BUTTON_H__
#define __BUTTON_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Sprite.h"
#include "../Camara.h"
#include <unordered_map>

/**
 * Clase Button, la cual es el objeto que posee el sprite correspondiente y su posicion en el mundo real
*/
class Button {
public:
  /**
   * Constructor setea la posicion del button en el mundo y 
   * el mapa de estados del mismo.
  */
  Button(const Window &window, const int &state);

  /**
   * Destructor
  */
  ~Button();
  
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

  /*
  * Metodo encargado de setaer el estado del objeto recibido por parametro con un id
  */
  void setState(const int& state);

private:
  Rect dest_world;
  Sprite *sprite;
  std::unordered_map<int, Sprite *> states;
};

#endif
