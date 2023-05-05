#include <SDL.h>
#include "Game.h"
#include "SDL_image.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(IMG_INIT_PNG);




    Game game;
    game.init();

    return 0;
}
