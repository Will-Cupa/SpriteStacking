#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>

#include "sprite.h"

using namespace std;

const int HEIGHT = 600, WIDTH = 800;

int main(int argc, char *argv[]){

    int init = SDL_Init(SDL_INIT_EVERYTHING);
    if (init < 0){
        cerr << "SDL not initialized properly error code :" << init << endl;
        return init;
    };

    SDL_Window *window = SDL_CreateWindow("Sprite Stacking", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

    if (window == nullptr){
        cerr << "Failed to create window" << endl;
        return -1;
    }

     SDL_GLContext Context = SDL_GL_CreateContext(window);

    if (Context == nullptr){
        cerr << "Failed to create Context" << endl;
        return -2;
    }

    Sprite sprite = Sprite("sprites/redCross.bmp", 100, 100, 50, 50, 45.0f);

    SDL_Event events;
    bool running = true;

    while(running){
        while (SDL_PollEvent(&events)){
            if(events.type == SDL_QUIT){
                running = false;
                break;
            }
        }

        glViewport(0, 0, WIDTH, HEIGHT);
        glClearColor(1.f, 0.f, 1.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

//g++ src/*.cpp -IZ:\personal\SDL2Library\include -LZ:\personal\SDL2Library\lib -lmingw32 -lSDL2main -lSDL2 -lopengl32 -o main
//g++ src/*.cpp -ID:\C++Libraries\SDL2\include -LD:\C++Libraries\SDL2\lib -lmingw32 -lSDL2main -lSDL2 -lopengl32 -o main