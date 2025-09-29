#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>

#include "sprite.h"

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

    Sprite sprite = Sprite(renderer, "sprites/redCross.bmp", 100, 100, 50, 50, 45.0);

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

        sprite.display(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

//g++ src/*.cpp -IZ:\personal\SDL2Library\include -LZ:\personal\SDL2Library\lib -lmingw32 -lSDL2main -lSDL2 -lopengl32 -o main