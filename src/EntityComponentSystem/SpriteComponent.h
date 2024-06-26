#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include <SDL2/SDL.h>
#include "TransformComponent.h"

class SpriteComponent : public Component {
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, dstRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        setTexture(path);
    }

    void setTexture(const char* path) {
        texture = TextureManger::loadTexture(path);
    }

    void init() override {
        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 16;
        dstRect.x = dstRect.y = 32;
        dstRect.w = dstRect.h = 64;
    }
    void update() override {
        dstRect.x = (int)transform->position.x;
        dstRect.y = (int)transform->position.y;
    }
    void draw() override {
        TextureManger::Draw(texture, srcRect, dstRect);
    }

};

#endif //SPRITECOMPONENT_H
