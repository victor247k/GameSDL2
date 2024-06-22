#include "TextureManager.h"

SDL_Texture* TextureManger::loadTexture(const char* fileName, SDL_Renderer* ren)
{
    SDL_Surface* loadedSurface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    return texture;
}