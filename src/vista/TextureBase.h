#include <iostream>
#include <map>
#include "Sprite.h"

class TextureBase
{
public:
  static TextureBase *getInstance(SDL_Renderer* renderer)
  {
    if (instance == NULL)
      instance = new TextureBase(renderer);
    else
      std::cout << "Getting existing instance"<<std::endl;

    return instance;
  }

  SDL_Texture *getTexture(const int &id);

protected:
  TextureBase(SDL_Renderer* renderer);
  void createTexture(const int &id, const std::string filename);

  virtual ~TextureBase();

  TextureBase(TextureBase const &);
  TextureBase &operator=(TextureBase const &);

private:
  static TextureBase *instance;
  SDL_Renderer *renderer;
  std::map<int, SDL_Texture *> textures;
  std::map<int, SDL_Surface *> imgs;
};