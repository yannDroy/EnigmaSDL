/* Author : YANN DROY */
/******** 2015 ********/

#ifndef __DISPLAY__
#define __DISPLAY__

void init_sdl ();

void init_window (SDL_Window** window, SDL_Renderer **renderer, SDL_Texture** background);

void sdl_kill ();

SDL_Texture* loadTextureFromFile (SDL_Renderer* renderer, char* filename);

void blit (SDL_Renderer* renderer, SDL_Texture* texture, int x, int y);

void blitWithSize (SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int w, int h);

void display_letter (SDL_Renderer* renderer, char c, int* nb_letters);

void turn_off (SDL_Renderer* renderer, SDL_Texture* background, char c);

void display_plugboard (SDL_Renderer* renderer, char* plugboard);

void display_parameters (SDL_Renderer* renderer, int* chosen_rotors, int* positions);

void transform_to_roman (char* roman, int x);

void draw_line (SDL_Renderer* renderer, int pair_index, int x1, int y1, int x2, int y2);

void set_pixel (SDL_Renderer* renderer, int pair_index, int x, int y);

void writeOnConsole (char c, int* nb_letters);

void writeCurrentParameters (int* chosen_rotors, int* positions, char* plugboard, int nb_pairs);

#endif
