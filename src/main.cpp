#include "Game.h"
#include <filesystem>

Game *game = nullptr;

int main()
{

    const int FPS = 60;
    const float frameDelay = 1000.0 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("myGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();


    return 0;
}
