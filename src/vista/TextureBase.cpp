#include "TextureBase.h"
#include "Constants.h"
#include "Sprite.h"
#include "SdlException.h"

TextureBase::TextureBase(SDL_Renderer* renderer) : renderer(renderer)
{
  createTexture(PLAYER_SPRITE_ID,PLAYER_FILENAME);
  createTexture(BLOCK_SPRITE_ID, BLOCK_FILENAME);
  createTexture(GATE_SPRITE_ID, GATE_FILENAME);
  createTexture(EMITTER_SPRITE_ID, EMITTER_FILENAME);
  createTexture(BUTTON_SPRITE_ID, BUTTON_FILENAME);
  createTexture(ACID_SPRITE_ID, ACID_FILENAME);
  createTexture(ENERGY_BARRIER_SPRITE_ID, ENERGY_BARRIER_FILENAME);
  createTexture(PORTAL_BLUE_SPRITE_ID, PORTAL_BLUE_FILENAME);
  createTexture(PORTAL_ORANGE_SPRITE_ID, PORTAL_ORANGE_FILENAME);
  createTexture(POWERBALL_SPRITE_ID, POWERBALL_FILENAME);
  createTexture(ROCK_SPRITE_ID, ROCK_FILENAME);
  createTexture(TARGET_SPRITE_ID,TARGET_FILENAME);
  createTexture(CAKE_SPRITE_ID,CAKE_FILENAME);
}

void TextureBase::createTexture(const int& id, const std::string filename) {
  if (imgs.find(id) != imgs.end()) return;
  imgs[id] = IMG_Load(filename.c_str());
  textures[id] = SDL_CreateTextureFromSurface(this->renderer, imgs[id]);
  /*if (textures[id] == NULL || imgs[id] == NULL) {
    throw SdlException("No se pudo cargar la imagen con ID " + std::to_string(id),SDL_GetError());
  }*/
}

TextureBase::~TextureBase()
{
  for (auto &texture : textures) {
    SDL_DestroyTexture(texture.second);
  }

  for (auto &img : imgs)
  {
    SDL_FreeSurface(img.second);
  }
}

SDL_Texture* TextureBase::getTexture(const int& id) {
  return textures[id];
}

TextureBase *TextureBase::instance = NULL;