#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>

#include "textures.h"

using namespace std;

const int HEIGHT = 600, WIDTH = 800;

int main(int argc, char *argv[]){

    int init = SDL_Init(SDL_INIT_EVERYTHING);
    if (init < 0){
        cerr << "SDL not initialized properly error code :" << init << endl;
        return init;
    };

    SDL_Window *window = SDL_CreateWindow("Sprite Stacking", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr){
        cerr << "Failed to create window" << endl;
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); 

    if (renderer == nullptr){
        cerr << "Failed to create renderer" << endl;
        return -2;
    }

    SDL_Texture *texture = loadSprite(renderer, "sprites/redCross.bmp");

    SDL_Event events;
    bool running = true;

    while(running){
        while (SDL_PollEvent(&events)){
            if(events.type == SDL_QUIT){
                running = false;
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer); //Not really clearing, more like filling

        SDL_Rect rect =  {0, 0, 500, 100};

        SDL_RenderCopy(renderer, texture, nullptr, &rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}