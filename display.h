/* Author : YANN DROY */
/******** 2015 ********/

#ifndef __DISPLAY__
#define __DISPLAY__

void init_sdl ();

void init_window (SDL_Surface** window, SDL_Surface* background);

void sdl_kill ();

void display_letter (SDL_Surface* window, char c);

void turn_off (SDL_Surface* window, SDL_Surface* background, char c);

void display_plugboard (SDL_Surface* window, char* plugboard);

void display_parameters (SDL_Surface* window, int* chosen_rotors, int* positions);

void transform_to_roman (char* roman, int x);

void draw_line (SDL_Surface* window, int x1, int y1, int x2, int y2);

void set_pixel (SDL_Surface* window, int x, int y, Uint32 color);

#endif
