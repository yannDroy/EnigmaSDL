/* Author : YANN DROY */
/******** 2015 ********/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "display.h"
#include "const.h"

void init_sdl (){
    SDL_SetMainReady();

    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
        fprintf(stderr, "SDL loading failure : %s.\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if(TTF_Init() == -1){
        fprintf(stderr, "TTF loading failure : %s.\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
}

void init_window (SDL_Window** window, SDL_Renderer **renderer, SDL_Texture** background){
    *window = SDL_CreateWindow("Enigma Machine 3.0",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                WIDTH, HEIGTH,
                                0);
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

    if(window == NULL){
        fprintf(stderr, "Window opening failure : %s.\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }else if(renderer == NULL){
        fprintf(stderr, "Rendering opening failure : %s.\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }else{
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_SetWindowIcon(*window, SDL_LoadBMP("./Pictures/icon.bmp"));

        *background = loadTextureFromFile(*renderer, "./Pictures/Keyboard/ENIGMA.png");
        blit(*renderer, *background, 0, 0);
    }
}

void sdl_kill (){
    TTF_Quit();
    SDL_Quit();
}

SDL_Texture* loadTextureFromFile (SDL_Renderer* renderer, char* filename){
    SDL_Texture *texture;
    texture = IMG_LoadTexture(renderer, filename);

    return texture;
}

void blit (SDL_Renderer* renderer, SDL_Texture *texture, int x, int y){
    SDL_Rect position;
    position.x = x;
    position.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(renderer, texture, NULL, &position);
}

void blitWithSize (SDL_Renderer* renderer, SDL_Texture *texture, int x, int y, int w, int h){
    SDL_Rect position;
    SDL_Rect from;

    position.x = x;
    position.y = y;
    position.w = w;
    position.h = h;
    from.x = x;
    from.y = y;
    from.w = w;
    from.h = h;

    SDL_RenderCopy(renderer, texture, &from, &position);
}

void display_letter (SDL_Renderer* renderer, char c, int* nb_letter){
    SDL_Texture* letter = NULL;
    int x;
    int y;

    writeOnConsole(c, nb_letter);

    switch(c){
    case 'A':
        x = 46;
        y = 252;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/A.png");
        break;
    case 'B':
        x = 303;
        y = 313;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/B.png");
        break;
    case 'C':
        x = 183;
        y = 313;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/C.png");
        break;
    case 'D':
        x = 165;
        y = 253;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/D.png");
        break;
    case 'E':
        x = 144;
        y = 193;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/E.png");
        break;
    case 'F':
        x = 224;
        y = 254;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/F.png");
        break;
    case 'G':
        x = 281;
        y = 253;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/G.png");
        break;
    case 'H':
        x = 341;
        y = 253;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/H.png");
        break;
    case 'I':
        x = 440;
        y = 193;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/I.png");
        break;
    case 'J':
        x = 401;
        y = 253;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/J.png");
        break;
    case 'K':
        x = 460;
        y = 253;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/K.png");
        break;
    case 'L':
        x = 481;
        y = 313;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/L.png");
        break;
    case 'M':
        x = 421;
        y = 313;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/M.png");
        break;
    case 'N':
        x = 361;
        y = 313;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/N.png");
        break;
    case 'O':
        x = 499;
        y = 193;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/O.png");
        break;
    case 'P':
        x = 7;
        y = 314;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/P.png");
        break;
    case 'Q':
        x = 26;
        y = 194;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/Q.png");
        break;
    case 'R':
        x = 204;
        y = 193;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/R.png");
        break;
    case 'S':
        x = 105;
        y = 253;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/S.png");
        break;
    case 'T':
        x = 262;
        y = 194;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/T.png");
        break;
    case 'U':
        x = 381;
        y = 194;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/U.png");
        break;
    case 'V':
        x = 243;
        y = 314;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/V.png");
        break;
    case 'W':
        x = 84;
        y = 195;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/W.png");
        break;
    case 'X':
        x = 124;
        y = 313;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/X.png");
        break;
    case 'Y':
        x = 66;
        y = 314;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/Y.png");
        break;
    case 'Z':
        x = 321;
        y = 193;
        letter = loadTextureFromFile(renderer, "./Pictures/Light/Z.png");
        break;
    default:
        break;
    }

    blit(renderer, letter, x, y);
    SDL_DestroyTexture(letter);
}

void turn_off (SDL_Renderer* renderer, SDL_Texture* background, char c){
    int x;
    int y;

    switch(c){
    case 'A':
        x = 46;
        y = 252;
        break;
    case 'B':
        x = 303;
        y = 313;
        break;
    case 'C':
        x = 183;
        y = 313;
        break;
    case 'D':
        x = 165;
        y = 253;
        break;
    case 'E':
        x = 144;
        y = 193;
        break;
    case 'F':
        x = 224;
        y = 254;
        break;
    case 'G':
        x = 281;
        y = 253;
        break;
    case 'H':
        x = 341;
        y = 253;
        break;
    case 'I':
        x = 440;
        y = 193;
        break;
    case 'J':
        x = 401;
        y = 253;
        break;
    case 'K':
        x = 460;
        y = 253;
        break;
    case 'L':
        x = 481;
        y = 313;
        break;
    case 'M':
        x = 421;
        y = 313;
        break;
    case 'N':
        x = 361;
        y = 313;
        break;
    case 'O':
        x = 499;
        y = 193;
        break;
    case 'P':
        x = 7;
        y = 314;
        break;
    case 'Q':
        x = 26;
        y = 194;
        break;
    case 'R':
        x = 204;
        y = 193;
        break;
    case 'S':
        x = 105;
        y = 253;
        break;
    case 'T':
        x = 262;
        y = 194;
        break;
    case 'U':
        x = 381;
        y = 194;
        break;
    case 'V':
        x = 243;
        y = 314;
        break;
    case 'W':
        x = 84;
        y = 195;
        break;
    case 'X':
        x = 124;
        y = 313;
        break;
    case 'Y':
        x = 66;
        y = 314;
        break;
    case 'Z':
        x = 321;
        y = 193;
        break;
    default:
        break;
    }

    blitWithSize(renderer, background, x, y, 90, 90);
}

void display_plugboard (SDL_Renderer* renderer, char* plugboard){
    SDL_Surface* letter = NULL;
    SDL_Rect position;
    SDL_Color color = {220, 220, 220};
    SDL_Color back_color = {48, 26, 0};
    TTF_Font* font = NULL;
    char s[2] = {0};
    char already_displayed[10] = {0};
    int pair_index = 0;
    int display;
    int i, j;

    font = TTF_OpenFont("./Fonts/letter_font.ttf", 18);

    position.x = 10;
    position.y = 600;
    position.w = WIDTH - 20;
    position.h = 90;
    SDL_SetRenderDrawColor(renderer, 48, 26, 0, 255);
    SDL_RenderFillRect(renderer, &position);

    position.x = 18;
    position.y = 605;

    for(i = 0; i < 26; i++){
        sprintf(s, "%c", i + 'A');

        letter = TTF_RenderText_Shaded(font, s, color, back_color);
        SDL_Texture* textureLetter = SDL_CreateTextureFromSurface(renderer, letter);
        blit(renderer, textureLetter, position.x, position.y);
        blit(renderer, textureLetter, position.x, position.y + 60);
        SDL_FreeSurface(letter);
        SDL_DestroyTexture(textureLetter);

        if(plugboard[i] != 'A' + i){
            display = 1;
            for (j = 0; j < pair_index; j++){
                if (already_displayed[j] == i + 'A'){
                    display = 0;
                    break;
                }
            }
            if (display){
                draw_line(renderer, pair_index, position.x + 5, 630, (23 + (plugboard[i] - 'A') * 22), 658);
                already_displayed[pair_index] = plugboard[i];
                pair_index++;
            }
        }

        position.x += 22;
    }

    TTF_CloseFont(font);
}

void display_parameters (SDL_Renderer* renderer, int* chosen_rotors, int* positions){
    SDL_Surface* rotor = NULL;
    SDL_Surface* pos = NULL;
    SDL_Texture* back = NULL;
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

    back = loadTextureFromFile(renderer, "./Pictures/Keyboard/background_letters.png");
    position_letter.x = 176;
    position_letter.y = 86;
    blit(renderer, back, position_letter.x, position_letter.y);
    SDL_DestroyTexture(back);

    back = loadTextureFromFile(renderer, "./Pictures/Keyboard/background_rotors.png");
    position_rotor.x = 200;
    position_rotor.y = 172;
    blit(renderer, back, position_rotor.x, position_rotor.y);
    SDL_DestroyTexture(back);

    if(positions[2] != -1){
        sprintf(s, "%c", positions[2] + 'A');
        pos = TTF_RenderText_Shaded(pos_font, s, color, back_color);
        position_letter.x = 187 - pos->w / 2;
        position_letter.y = 102 - pos->h / 2;
        SDL_Texture* texturePos = SDL_CreateTextureFromSurface(renderer, pos);
        blit(renderer, texturePos, position_letter.x, position_letter.y);
        SDL_FreeSurface(pos);
        SDL_DestroyTexture(texturePos);
    }

    if(positions[1] != -1){
        sprintf(s, "%c", positions[1] + 'A');
        pos = TTF_RenderText_Shaded(pos_font, s, color, back_color);
        position_letter.x = 249 - pos->w / 2;
        position_letter.y = 102 - pos->h / 2;
        SDL_Texture* texturePos = SDL_CreateTextureFromSurface(renderer, pos);
        blit(renderer, texturePos, position_letter.x, position_letter.y);
        SDL_FreeSurface(pos);
        SDL_DestroyTexture(texturePos);
    }

    if(positions[0] != -1){
        sprintf(s, "%c", positions[0] + 'A');
        pos = TTF_RenderText_Shaded(pos_font, s, color, back_color);
        position_letter.x = 311 - pos->w / 2;
        position_letter.y = 102 - pos->h / 2;
        SDL_Texture* texturePos = SDL_CreateTextureFromSurface(renderer, pos);
        blit(renderer, texturePos, position_letter.x, position_letter.y);
        SDL_FreeSurface(pos);
        SDL_DestroyTexture(texturePos);
    }

    if(chosen_rotors[2] != -1){
        transform_to_roman(roman, chosen_rotors[2]);
        rotor = TTF_RenderText_Shaded(rotor_font, roman, color, back_color);
        position_rotor.x = 215 - rotor->w / 2;
        position_rotor.y = 183 - rotor->h / 2;
        SDL_Texture* textureRotor = SDL_CreateTextureFromSurface(renderer, rotor);
        blit(renderer, textureRotor, position_rotor.x, position_rotor.y);
        SDL_FreeSurface(rotor);
        SDL_DestroyTexture(textureRotor);
    }

    if(chosen_rotors[1] != -1){
        transform_to_roman(roman, chosen_rotors[1]);
        rotor = TTF_RenderText_Shaded(rotor_font, roman, color, back_color);
        position_rotor.x = 277 - rotor->w / 2;
        position_rotor.y = 183 - rotor->h / 2;
        SDL_Texture* textureRotor = SDL_CreateTextureFromSurface(renderer, rotor);
        blit(renderer, textureRotor, position_rotor.x, position_rotor.y);
        SDL_FreeSurface(rotor);
        SDL_DestroyTexture(textureRotor);
    }

    if(chosen_rotors[0] != -1){
        transform_to_roman(roman, chosen_rotors[0]);
        rotor = TTF_RenderText_Shaded(rotor_font, roman, color, back_color);
        position_rotor.x = 339 - rotor->w / 2;
        position_rotor.y = 183 - rotor->h / 2;
        SDL_Texture* textureRotor = SDL_CreateTextureFromSurface(renderer, rotor);
        blit(renderer, textureRotor, position_rotor.x, position_rotor.y);
        SDL_FreeSurface(rotor);
        SDL_DestroyTexture(textureRotor);
    }

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

void draw_line (SDL_Renderer* renderer, int pair_index, int x1, int y1, int x2, int y2){
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
        set_pixel(renderer, pair_index, (int)x, (int)y);
        x += add_x;
        y += add_y;
    }

    SDL_SetRenderDrawColor(renderer, 235, 213, 140, 255);

    position.x = x1 - 2;
    position.y = y1 - 2;
    position.w = 6;
    position.h = 6;
    SDL_RenderFillRect(renderer, &position);

    position.x = x2 - 2;
    position.y = y2 - 2;
    SDL_RenderFillRect(renderer, &position);
}

void set_pixel (SDL_Renderer* renderer, int pair_index, int x, int y){
    SDL_Rect position;
    int colors[10][3] = {
        {0  , 100, 0  },
        {176, 48 , 96 },
        {255, 215, 0  },
        {0  , 0  , 188},
        {200, 39 , 0  },
        {0  , 255, 255},
        {255, 0  , 255},
        {127, 255, 0  },
        {245, 230, 240},
        {255, 130, 0  }};

    position.x = x;
    position.y = y;
    position.w = 2;
    position.h = 2;

    SDL_SetRenderDrawColor(renderer, colors[pair_index][0], colors[pair_index][1], colors[pair_index][2], 255);
    SDL_RenderFillRect(renderer, &position);
}

void writeOnConsole (char c, int* nb_letters){
    if (*nb_letters == 0){
        fprintf(stdout, "\n\nNew settings detected. Message:\n");
    }

    fprintf(stdout, "%c", c);
    (*nb_letters)++;

    if (*nb_letters % 25 == 0){
        fprintf(stdout, "\n");
    }else if (*nb_letters % 5 == 0){
        fprintf(stdout, " ");
    }
}

void writeCurrentParameters (int* chosen_rotors, int* positions, char* plugboard, int nb_pairs){
    char roman[4] = {0};
    char already_displayed[10] = {0};
    int last_pair_index = 0;
    int display;
    int i, j;

    if (chosen_rotors[0] == -1 || chosen_rotors[1] == -1 || chosen_rotors[2] == -1)
        return;

    fprintf(stdout, "\n\n\nCurrent ENIGMA settings:\n");

    transform_to_roman(roman, chosen_rotors[2]);
    fprintf(stdout, "  Rotor %3s: %c\n", roman, (positions[2] + 'A'));

    transform_to_roman(roman, chosen_rotors[1]);
    fprintf(stdout, "  Rotor %3s: %c\n", roman, (positions[1] + 'A'));

    transform_to_roman(roman, chosen_rotors[0]);
    fprintf(stdout, "  Rotor %3s: %c\n", roman, (positions[0] + 'A'));

    if (nb_pairs == 0){
        fprintf(stdout, "No Pairs on the plugboard.\n");
        return;
    }

    if (nb_pairs == 1)
        fprintf(stdout, "1 pair on the plugboard:\n  ");
    else
        fprintf(stdout, "%d pairs on the plugboard:\n  ", nb_pairs);

    for (i = 0; i < 26; i++){
        if (plugboard[i] != i + 'A'){
            display = 1;
            for (j = 0; j < last_pair_index; j++){
                if (already_displayed[j] == i + 'A'){
                    display = 0;
                    break;
                }
            }
            if (display){
                fprintf(stdout, "%c-%c  ", (i + 'A'), plugboard[i]);
                already_displayed[last_pair_index] = plugboard[i];
                last_pair_index++;
            }
        }
    }

    fprintf(stdout, "\n");
}
