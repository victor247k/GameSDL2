#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.h"

class TextureManger {
public:
    static SDL_Texture* loadTexture(const char* fileName);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
};

#endif //TEXTUREMANAGER_H
