#include "TextureManager.h"

SDL_Texture* TextureManger::loadTexture(const char* fileName)
{
    SDL_Surface* loadedSurface = IMG_Load(fileName);
    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    return texture;
}

void TextureManger::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst) {
    SDL_RenderCopy(Game::renderer, texture, &src, &dst);
}
