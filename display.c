/* Author : YANN DROY */
/******** 2015 ********/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "display.h"
#include "const.h"

void init_sdl (){
  if(SDL_Init(SDL_INIT_VIDEO) == -1){
    fprintf(stderr, "SDL loading failure : %s.\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  if(TTF_Init() == -1){
    fprintf(stderr, "TTF loading failure : %s.\n", TTF_GetError());
    exit(EXIT_FAILURE);
  }
}

void init_window (SDL_Surface** window, SDL_Surface* background){
  SDL_Rect position;

  *window = SDL_SetVideoMode(WIDTH, HEIGTH, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  if(window == NULL){
    fprintf(stderr, "Window opening failure : %s.\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }else{
    SDL_WM_SetCaption("Enigma Machine 2.6", NULL);
    SDL_WM_SetIcon(SDL_LoadBMP("./Pictures/icon.bmp"), NULL);

    position.x = 0;
    position.y = 0;

    SDL_BlitSurface(background, NULL, (*window), &position);
    SDL_Flip(*window);
  }
}

void sdl_kill (){
  TTF_Quit();
  SDL_Quit();
}

void display_letter (SDL_Surface* window, char c){
  SDL_Surface* letter = NULL;
  SDL_Rect position;

  switch(c){
  case 'A':
    position.x = 46;
    position.y = 252;
    letter = IMG_Load("./Pictures/Light/A.png");
    break;
  case 'B':
    position.x = 303;
    position.y = 313;
    letter = IMG_Load("./Pictures/Light/B.png");
    break;
  case 'C':
    position.x = 183;
    position.y = 313;
    letter = IMG_Load("./Pictures/Light/C.png");
    break;
  case 'D':
    position.x = 165;
    position.y = 253;
    letter = IMG_Load("./Pictures/Light/D.png");
    break;
  case 'E':
    position.x = 144;
    position.y = 193;
    letter = IMG_Load("./Pictures/Light/E.png");
    break;
  case 'F':
    position.x = 224;
    position.y = 254;
    letter = IMG_Load("./Pictures/Light/F.png");
    break;
  case 'G':
    position.x = 281;
    position.y = 253;
    letter = IMG_Load("./Pictures/Light/G.png");
    break;
  case 'H':
    position.x = 341;
    position.y = 253;
    letter = IMG_Load("./Pictures/Light/H.png");
    break;
  case 'I':
    position.x = 440;
    position.y = 193;
    letter = IMG_Load("./Pictures/Light/I.png");
    break;
  case 'J':
    position.x = 401;
    position.y = 253;
    letter = IMG_Load("./Pictures/Light/J.png");
    break;
  case 'K':
    position.x = 460;
    position.y = 253;
    letter = IMG_Load("./Pictures/Light/K.png");
    break;
  case 'L':
    position.x = 481;
    position.y = 313;
    letter = IMG_Load("./Pictures/Light/L.png");
    break;
  case 'M':
    position.x = 421;
    position.y = 313;
    letter = IMG_Load("./Pictures/Light/M.png");
    break;
  case 'N':
    position.x = 361;
    position.y = 313;
    letter = IMG_Load("./Pictures/Light/N.png");
    break;
  case 'O':
    position.x = 499;
    position.y = 193;
    letter = IMG_Load("./Pictures/Light/O.png");
    break;
  case 'P':
    position.x = 7;
    position.y = 314;
    letter = IMG_Load("./Pictures/Light/P.png");
    break;
  case 'Q':
    position.x = 26;
    position.y = 194;
    letter = IMG_Load("./Pictures/Light/Q.png");
    break;
  case 'R':
    position.x = 204;
    position.y = 193;
    letter = IMG_Load("./Pictures/Light/R.png");
    break;
  case 'S':
    position.x = 105;
    position.y = 253;
    letter = IMG_Load("./Pictures/Light/S.png");
    break;
  case 'T':
    position.x = 262;
    position.y = 194;
    letter = IMG_Load("./Pictures/Light/T.png");
    break;
  case 'U':
    position.x = 381;
    position.y = 194;
    letter = IMG_Load("./Pictures/Light/U.png");
    break;
  case 'V':
    position.x = 243;
    position.y = 314;
    letter = IMG_Load("./Pictures/Light/V.png");
    break;
  case 'W':
    position.x = 84;
    position.y = 195;
    letter = IMG_Load("./Pictures/Light/W.png");
    break;
  case 'X':
    position.x = 124;
    position.y = 313;
    letter = IMG_Load("./Pictures/Light/X.png");
    break;
  case 'Y':
    position.x = 66;
    position.y = 314;
    letter = IMG_Load("./Pictures/Light/Y.png");
    break;
  case 'Z':
    position.x = 321;
    position.y = 193;
    letter = IMG_Load("./Pictures/Light/Z.png");
    break;
  default:
    break;
  }

  SDL_BlitSurface(letter, NULL, window, &position);
  SDL_Flip(window);

  SDL_FreeSurface(letter);
}

void turn_off (SDL_Surface* window, SDL_Surface* background, char c){
  SDL_Rect position;

  switch(c){
  case 'A':
    position.x = 46;
    position.y = 252;
    break;
  case 'B':
    position.x = 303;
    position.y = 313;
    break;
  case 'C':
    position.x = 183;
    position.y = 313;
    break;
  case 'D':
    position.x = 165;
    position.y = 253;
    break;
  case 'E':
    position.x = 144;
    position.y = 193;
    break;
  case 'F':
    position.x = 224;
    position.y = 254;
    break;
  case 'G':
    position.x = 281;
    position.y = 253;
    break;
  case 'H':
    position.x = 341;
    position.y = 253;
    break;
  case 'I':
    position.x = 440;
    position.y = 193;
    break;
  case 'J':
    position.x = 401;
    position.y = 253;
    break;
  case 'K':
    position.x = 460;
    position.y = 253;
    break;
  case 'L':
    position.x = 481;
    position.y = 313;
    break;
  case 'M':
    position.x = 421;
    position.y = 313;
    break;
  case 'N':
    position.x = 361;
    position.y = 313;
    break;
  case 'O':
    position.x = 499;
    position.y = 193;
    break;
  case 'P':
    position.x = 7;
    position.y = 314;
    break;
  case 'Q':
    position.x = 26;
    position.y = 194;
    break;
  case 'R':
    position.x = 204;
    position.y = 193;
    break;
  case 'S':
    position.x = 105;
    position.y = 253;
    break;
  case 'T':
    position.x = 262;
    position.y = 194;
    break;
  case 'U':
    position.x = 381;
    position.y = 194;
    break;
  case 'V':
    position.x = 243;
    position.y = 314;
    break;
  case 'W':
    position.x = 84;
    position.y = 195;
    break;
  case 'X':
    position.x = 124;
    position.y = 313;
    break;
  case 'Y':
    position.x = 66;
    position.y = 314;
    break;
  case 'Z':
    position.x = 321;
    position.y = 193;
    break;
  default:
    break;
  }

  position.w = 90;
  position.h = 90;

  SDL_BlitSurface(background, &position, window, &position);
  SDL_Flip(window);
}

void display_plugboard (SDL_Surface* window, char* plugboard){
  SDL_Surface* back = NULL;
  SDL_Surface* letter = NULL;
  SDL_Rect position;
  SDL_Color color = {210, 210, 210};
  SDL_Color back_color = {5, 5, 5};
  TTF_Font* font = NULL;
  char s[2] = {0};
  int i;

  font = TTF_OpenFont("./Fonts/letter_font.ttf", 18);

  back = SDL_CreateRGBSurface(SDL_HWSURFACE, WIDTH - 20, 90, 32, 0, 0, 0, 0);
  SDL_FillRect(back, NULL, (SDL_MapRGB(window->format, 5, 5, 5)));
  position.x = 10;
  position.y = 600;
  SDL_BlitSurface(back, NULL, window, &position);

  position.x = 18;
  position.y = 605;

  for(i = 0; i < 26; i++){
    sprintf(s, "%c", i + 'A');
    letter = TTF_RenderText_Shaded(font, s, color, back_color);
    SDL_BlitSurface(letter, NULL, window, &position);
    position.y += 60;
    SDL_BlitSurface(letter, NULL, window, &position);

    SDL_FreeSurface(letter);
    position.y -= 60;

    if(plugboard[i] != 'A' + i)
      draw_line(window, position.x + 5, 630, (23 + (plugboard[i] - 'A') * 22), 658);

    position.x += 22;
  }

  SDL_Flip(window);
  SDL_FreeSurface(back);
  TTF_CloseFont(font);
}

void display_parameters (SDL_Surface* window, int* chosen_rotors, int* positions){
  SDL_Surface* rotor = NULL;
  SDL_Surface* pos = NULL;
  SDL_Surface* back = NULL;
  SDL_Rect position_rotor;
  SDL_Rect position_letter;
  SDL_Color color = {210, 210, 210};
  SDL_Color back_color = {24, 24, 24};
  TTF_Font* pos_font = NULL;
  TTF_Font* rotor_font = NULL;
  char s[2] = {0};
  char roman[4] = {0};

  pos_font = TTF_OpenFont("./Fonts/pos_font.ttf", 23);
  rotor_font = TTF_OpenFont("./Fonts/rotor_font.ttf", 17);

  back = IMG_Load("./Pictures/Keyboard/background_letters.png");
  position_letter.x = 176;
  position_letter.y = 86;
  SDL_BlitSurface(back, NULL, window, &position_letter);

  SDL_FreeSurface(back);
  back = IMG_Load("./Pictures/Keyboard/background_rotors.png");
  position_rotor.x = 200;
  position_rotor.y = 172;
  SDL_BlitSurface(back, NULL, window, &position_rotor);

  if(positions[2] != -1){
    sprintf(s, "%c", positions[2] + 'A');
    pos = TTF_RenderText_Shaded(pos_font, s, color, back_color);
    position_letter.x = 187 - pos->w / 2;
    position_letter.y = 102 - pos->h / 2;
    SDL_BlitSurface(pos, NULL, window, &position_letter);
    SDL_FreeSurface(pos);
  }

  if(positions[1] != -1){
    sprintf(s, "%c", positions[1] + 'A');
    pos = TTF_RenderText_Shaded(pos_font, s, color, back_color);
    position_letter.x = 249 - pos->w / 2;
    position_letter.y = 102 - pos->h / 2;
    SDL_BlitSurface(pos, NULL, window, &position_letter);
    SDL_FreeSurface(pos);
  }

  if(positions[0] != -1){
    sprintf(s, "%c", positions[0] + 'A');
    pos = TTF_RenderText_Shaded(pos_font, s, color, back_color);
    position_letter.x = 311 - pos->w / 2;
    position_letter.y = 102 - pos->h / 2;
    SDL_BlitSurface(pos, NULL, window, &position_letter);
    SDL_FreeSurface(pos);
  }

  if(chosen_rotors[2] != -1){
    transform_to_roman(roman, chosen_rotors[2]);
    rotor = TTF_RenderText_Shaded(rotor_font, roman, color, back_color);
    position_rotor.x = 215 - rotor->w / 2;
    position_rotor.y = 183 - rotor->h / 2;
    SDL_BlitSurface(rotor, NULL, window, &position_rotor);
    SDL_FreeSurface(rotor);
  }

  if(chosen_rotors[1] != -1){
    transform_to_roman(roman, chosen_rotors[1]);
    rotor = TTF_RenderText_Shaded(rotor_font, roman, color, back_color);
    position_rotor.x = 277 - rotor->w / 2;
    position_rotor.y = 183 - rotor->h / 2;
    SDL_BlitSurface(rotor, NULL, window, &position_rotor);
    SDL_FreeSurface(rotor);
  }

  if(chosen_rotors[0] != -1){
    transform_to_roman(roman, chosen_rotors[0]);
    rotor = TTF_RenderText_Shaded(rotor_font, roman, color, back_color);
    position_rotor.x = 339 - rotor->w / 2;
    position_rotor.y = 183 - rotor->h / 2;
    SDL_BlitSurface(rotor, NULL, window, &position_rotor);
    SDL_FreeSurface(rotor);
  }

  SDL_Flip(window);

  SDL_FreeSurface(back);
  TTF_CloseFont(pos_font);
  TTF_CloseFont(rotor_font);
}

void transform_to_roman (char* roman, int x){
  switch(x){
  case 0:
    roman[0] = 'I';
    roman[1] = '\0';
    break;
  case 1:
    roman[0] = 'I';
    roman[1] = 'I';
    roman[2] = '\0';
    break;
  case 2:
    roman[0] = 'I';
    roman[1] = 'I';
    roman[2] = 'I';
    roman[3] = '\0';
    break;
  case 3:
    roman[0] = 'I';
    roman[1] = 'V';
    roman[2] = '\0';
    break;
  case 4:
    roman[0] = 'V';
    roman[1] = '\0';
    break;
  default:
    roman[0] = '\0';
    break;
  }
}

void draw_line (SDL_Surface* window, int x1, int y1, int x2, int y2){
  SDL_Surface* plug = NULL;
  SDL_Rect position;
  double x = abs(x2 - x1);
  double y = abs(y2 - y1);
  double length = sqrt(x * x + y * y);
  double add_x;
  double add_y;
  int i;
  
  if(x1 > x2)
    add_x = -(x / length);
  else
    add_x = x / length;

  if(y1 > y2)
    add_y = -(y / length);
  else
    add_y = y / length;

  x = x1;
  y = y1;

  for(i = 0; i < length; i++){
    set_pixel(window, (int)x, (int)y, (SDL_MapRGB(window->format, 143, 89, 63)));
      x += add_x;
      y += add_y;
    }

  plug = SDL_CreateRGBSurface(SDL_HWSURFACE, 6, 6, 32, 0, 0, 0, 0);
  SDL_FillRect(plug, NULL, (SDL_MapRGB(window->format, 235, 213, 140)));

  position.x = x1 - 2;
  position.y = y1 - 2;
  SDL_BlitSurface(plug, NULL, window, &position);

  position.x = x2 - 2;
  position.y = y2 - 2;
  SDL_BlitSurface(plug, NULL, window, &position);

  SDL_FreeSurface(plug);
}

void set_pixel (SDL_Surface* window, int x, int y, Uint32 color){
  SDL_Surface* square = NULL;
  SDL_Rect position;

  position.x = x;
  position.y = y;

  square = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0);
  SDL_FillRect(square, NULL, color);
  SDL_BlitSurface(square, NULL, window, &position);

  SDL_FreeSurface(square);
}
