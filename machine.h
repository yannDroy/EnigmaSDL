/* Author : YANN DROY */
/******** 2015 ********/

#ifndef __MACHINE__
#define __MACHINE__

void test_rotation (int* rotors, int* positions);

char reflector (char c);

char encode_char (char c, char rotors[][26], int* chosen_rotors, int* positions, char* plugboard);

void init_parameters (int* chosen_rotors, int* positions);

void random_parameters (int* chosen_rotors, int* positions);

void init_plugboard (char* plugboard, int* nb_pairs);

void enigma (SDL_Surface* window, SDL_Surface* background);

void test_click (int* chosen_rotors, int* positions, char* plugboard, int* nb_pairs, int x, int y);

void change_plugboard (char* plugboard, char c, int* nb_pairs);
#endif
