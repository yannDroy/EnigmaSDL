/* Author : YANN DROY */
/******** 2015 ********/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "display.h"
#include "machine.h"

int main (int argc, char* argv[]){
  SDL_Surface* window = NULL;
  SDL_Surface* background = NULL;

  init_sdl();
  background = IMG_Load("./Pictures/Keyboard/ENIGMA.png");
  init_window(&window, background);

  enigma(window, background);

  SDL_FreeSurface(background);
  sdl_kill();

  return EXIT_SUCCESS;
}
