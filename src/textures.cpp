#include "textures.h"

using namespace std;

SDL_Texture* loadSprite(SDL_Renderer *renderer, const char *path){
    SDL_Surface *surface = SDL_LoadBMP(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture)
    {
        std::cout << "Failed to convert surface into a texture\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    }

    SDL_FreeSurface(surface);
    return texture;
}