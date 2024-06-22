#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"


GameObject* player;

Game::Game()
{
}
Game::~Game()
{
}
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
        isRunning = false;
        return;
    }
    std::cout << "Subsystems Initialized!...\n";

    window = SDL_CreateWindow(title, xpos, ypos, width, height, (fullscreen ? SDL_WINDOW_FULLSCREEN : 0));
    if (window)
    {
        std::cout << "Window created!...\n";
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        std::cout << "Renderer created!...\n";
    }
    isRunning = true;

    player = new GameObject("../assets/batman.png", renderer, 0, 0);

}
void Game::update()
{
    player->Update();
}
void Game::render()
{
    SDL_RenderClear(renderer);
    player->Render();
    SDL_RenderPresent(renderer);
}
void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}
void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Game cleaned!...\n";
}
