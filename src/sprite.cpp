#include "sprite.h"

using namespace std;

Sprite::Sprite(SDL_Renderer *renderer, const char *file, int x, int y, int height, int width, double angle){
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    this->rotation = angle;

    this->texture = loadSprite(renderer, file);
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

void Sprite::display(SDL_Renderer *renderer){
    SDL_Rect rect =  {x, y, height, width};

    for(int i=0; i<10; i++){
        SDL_RenderCopyEx(renderer, texture, nullptr, &rect, rotation, NULL, SDL_FLIP_NONE);
        rect =  {x, y - i*5, height, width};
    }
}

void Sprite::display(){
    
}