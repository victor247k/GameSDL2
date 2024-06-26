#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include "EntityComponentSystem.h"
#include "../Game.h"
#include "Components.h"

class KeyboardController : public Component{
public:
    TransformComponent *transform;

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
    }
    void update() override {
        if (SDL_PollEvent(&Game::event)) {
            switch (Game::event.type) {
                case SDL_KEYDOWN:
                    switch (Game::event.key.keysym.sym) {
                        case SDLK_w:
                            transform->velocity.y = -1;
                        break;
                        case SDLK_a:
                            transform->velocity.x = -1;
                        break;
                        case SDLK_s:
                            transform->velocity.y = 1;
                        break;
                        case SDLK_d:
                            transform->velocity.x = 1;
                        break;
                        default:
                            break;
                    }
                break;
                case SDL_KEYUP:
                    switch (Game::event.key.keysym.sym) {
                        case SDLK_w:
                        case SDLK_s:
                            transform->velocity.y = 0;
                        break;
                        case SDLK_a:
                        case SDLK_d:
                            transform->velocity.x = 0;
                        break;
                        default:
                            break;
                    }
                break;
            }
        }
    }
};

#endif //KEYBOARDCONTROLLER_H
