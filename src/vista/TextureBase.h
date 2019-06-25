#ifndef __TEXTUREBASE_H__
#define __TEXTUREBASE_H__
#include <iostream>
#include <map>
#include "Sprite.h"
#include "SdlException.h"

/**
 * Clase que posee todas las texturas a utilizar en el juego,
 * es un singleton, para poder acceder a ellas desde muchos 
 * lugares, sin tener que ir pasandola por parametro
 */
class TextureBase {
public:

  /**
   * Getter de la instancia de la clase
   **/
  static TextureBase *getInstance(SDL_Renderer* renderer) {
    if (instance == NULL)
      try {
        instance = new TextureBase(renderer);
      } catch (SdlException& e) {
        std::cout << e.what();
      }
    return instance;
  }

  /**
   * Geter de la textura a utilizar a traves de un id
   **/
  SDL_Texture *getTexture(const int &id);

protected:

  /**
   * Constructor
   **/
  TextureBase(SDL_Renderer* renderer);
  
  /**
   * Destructor
   **/
  virtual ~TextureBase();

  /**
   * Metodo que genera una textura y la guarda en el mapa
   **/
  void createTexture(const int &id, const std::string filename);

private:
  static TextureBase *instance;
  SDL_Renderer *renderer;
  std::map<int, SDL_Texture *> textures;
  std::map<int, SDL_Surface *> imgs;
};

#endif
