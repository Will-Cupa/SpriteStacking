#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <GL/gl.h>

using namespace std;

class Sprite{
    private:
    int x, y, width, height;
    double rotation;
    SDL_Texture* texture;

    public:
    Sprite(SDL_Renderer *renderer, const char *file, int x, int y, int height, int width, double angle);
    
    SDL_Texture* loadSprite(SDL_Renderer *renderer, const char *path);

    void display(SDL_Renderer *renderer);
};