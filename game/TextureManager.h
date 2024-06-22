#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.h"

class TextureManger {
public:
    static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* ren);
};

#endif //TEXTUREMANAGER_H
