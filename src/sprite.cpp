#include "sprite.h"

using namespace std;

Sprite::Sprite(const char *file, int x, int y, int height, int width, float angle){
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    this->rotation = angle;
}

SDL_Texture* Sprite::loadSprite(SDL_Renderer *renderer, const char *path){
    SDL_Surface *surface = SDL_LoadBMP(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture)
    {
        cout << "Failed to convert surface into a texture\n";
        cout << "SDL2 Error: " << SDL_GetError() << endl;
    }

    SDL_FreeSurface(surface);
    return texture;
}