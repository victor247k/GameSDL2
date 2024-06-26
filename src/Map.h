#ifndef MAP_H
#define MAP_H

#include "Game.h"


class Map {
public:

    Map();
    ~Map();

    void LoadMap(int arr[30][40]);
    void DrawMap();

private:

    SDL_Rect src;
    SDL_Rect dst;
    SDL_Texture *dirt;
    SDL_Texture *grass;
    SDL_Texture *water;

    int map[30][40];

};



#endif //MAP_H
