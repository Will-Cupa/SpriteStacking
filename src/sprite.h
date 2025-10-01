#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>

using namespace std;

class Sprite{
    private:
    int x, y, width, height;
    float rotation;
    SDL_Texture* texture;

    public:
    Sprite(const char *file, int x, int y, int height, int width, float angle);
    
    SDL_Texture* loadSprite(SDL_Renderer *renderer, const char *path);
};