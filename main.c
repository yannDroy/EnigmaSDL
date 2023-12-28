/* Author : YANN DROY */
/******** 2015 ********/

#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "display.h"
#include "machine.h"

int main (int argc, char* argv[]){
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* background = NULL;

    init_sdl();

    init_window(&window, &renderer, &background);

    display_help();

    enigma(renderer, background);

    SDL_DestroyTexture(background);
    sdl_kill();

    return EXIT_SUCCESS;
}
