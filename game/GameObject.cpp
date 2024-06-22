#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    objTexture = TextureManger::loadTexture(textureSheet, ren);
    xpos = x;
    ypos = y;
}
GameObject::~GameObject()
{

}

void GameObject::Update()
{
    xpos++;
    ypos++;
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.x = xpos;
    dstRect.y = ypos;
    dstRect.w = srcRect.w * 2;
    dstRect.h = srcRect.h * 2;
}
void GameObject::Render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &dstRect);
}
