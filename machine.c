/* Author : YANN DROY */
/******** 2015 ********/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include "machine.h"
#include "display.h"

void test_rotation (int* chosen_rotors, int* positions){
    int forward = 0;

    switch(chosen_rotors[0]){
    case 0:
        if(positions[0] == 'R' - 'A'){
            positions[1] = (positions[1] + 1) % 26;
            forward = 1;
        }
        break;
    case 1:
        if(positions[0] == 'F' - 'A'){
            positions[1] = (positions[1] + 1) % 26;
            forward = 1;
        }
        break;
    case 2:
        if(positions[0] == 'W' - 'A'){
            positions[1] = (positions[1] + 1) % 26;
            forward = 1;
        }
        break;
    case 3:
        if(positions[0] == 'K' - 'A'){
            positions[1] = (positions[1] + 1) % 26;
            forward = 1;
        }
        break;
    case 4:
        if(positions[0] == 'A' - 'A'){
            positions[1] = (positions[1] + 1) % 26;
            forward = 1;
        }
        break;
    default:
        break;
    }

    if(forward){
        switch(chosen_rotors[1]){
        case 0:
            if(positions[1] == 'R' - 'A')
                positions[2] = (positions[2] + 1) % 26;
            break;
        case 1:
            if(positions[1] == 'F' - 'A')
                positions[2] = (positions[2] + 1) % 26;
            break;
        case 2:
            if(positions[1] == 'W' - 'A')
                positions[2] = (positions[2] + 1) % 26;
            break;
        case 3:
            if(positions[1] == 'K' - 'A')
                positions[2] = (positions[2] + 1) % 26;
            break;
        case 4:
            if(positions[1] == 'A' - 'A')
                positions[2] = (positions[2] + 1) % 26;
            break;
        default:
            break;
        }
    }
}

char reflector (char c){
    switch(c){
    case 'A':
        return 'Y';
        break;
    case 'B':
        return 'R';
        break;
    case 'C':
        return 'U';
        break;
    case 'D':
        return 'H';
        break;
    case 'E':
        return 'Q';
        break;
    case 'F':
        return 'S';
        break;
    case 'G':
        return 'L';
        break;
    case 'H':
        return 'D';
        break;
    case 'I':
        return 'P';
        break;
    case 'J':
        return 'X';
        break;
    case 'K':
        return 'N';
        break;
    case 'L':
        return 'G';
        break;
    case 'M':
        return 'O';
        break;
    case 'N':
        return 'K';
        break;
    case 'O':
        return 'M';
        break;
    case 'P':
        return 'I';
        break;
    case 'Q':
        return 'E';
        break;
    case 'R':
        return 'B';
        break;
    case 'S':
        return 'F';
        break;
    case 'T':
        return 'Z';
        break;
    case 'U':
        return 'C';
        break;
    case 'V':
        return 'W';
        break;
    case 'W':
        return 'V';
        break;
    case 'X':
        return 'J';
        break;
    case 'Y':
        return 'A';
        break;
    case 'Z':
        return 'T';
        break;
    default:
        return c;
        break;
    }
}

char encode_char (char c, char rotors[][26], int* chosen_rotors, int* positions, char* plugboard){
    int j;

    if(chosen_rotors[0] == -1 || chosen_rotors[1] == -1 || chosen_rotors[2] == -1){
        return c;
    }else{
        c = plugboard[c -'A'];
    
        c = rotors[chosen_rotors[0]][(positions[0] + (c - 'A')) % 26];
        c = rotors[chosen_rotors[1]][(positions[1] + (c - 'A')) % 26];
        c = rotors[chosen_rotors[2]][(positions[2] + (c - 'A')) % 26];
    
        c = reflector(c);
    
        for(j = 0; j < 26; j++){
            if(rotors[chosen_rotors[2]][j] == c){
                c = (j - positions[2]) % 26;
                if(c < 0)
                    c = 26 + c;
                c = c + 'A';
                break;
            }
        }
    
        for(j = 0; j < 26; j++){
            if(rotors[chosen_rotors[1]][j] == c){
                c = (j - positions[1]) % 26;
                if(c < 0)
                    c = 26 + c;
                c = c + 'A';
                break;
            }
        }
    
        for(j = 0; j < 26; j++){
            if(rotors[chosen_rotors[0]][j] == c){
                c = (j - positions[0]) % 26;
                if(c < 0)
                    c = 26 + c;
                c = c + 'A';
                break;
            }
        }

        c = plugboard[c -'A'];
    
        positions[0] = (positions[0] + 1) % 26;
        test_rotation(chosen_rotors, positions);
    
        return c;
    }
}

void init_parameters (int* chosen_rotors, int* positions){
    int i;

    for(i = 0; i < 3; i++){
        positions[i] = -1;
        chosen_rotors[i] = -1;
    }
}

void random_parameters (int* chosen_rotors, int* positions){
    int i;

    srand(time(NULL));

    chosen_rotors[0] = rand() % 5;
  
    do{
        i = rand() % 5;
        chosen_rotors[1] = i;
    }while(chosen_rotors[1] == chosen_rotors[0]);

    do{
        i = rand() % 5;
        chosen_rotors[2] = i;
    }while(chosen_rotors[2] == chosen_rotors[1] || chosen_rotors[2] == chosen_rotors[0]);

    for(i = 0; i < 3; i++)
        positions[i] = rand() % 26;
}

void init_plugboard (char* plugboard, int* nb_pairs){
    int i;

    for(i = 0; i < 26; i++)
        plugboard[i] = i + 'A';

    *nb_pairs = 0;
    for(i = 0; i < 26; i++){
        if(plugboard[i] != i + 'A')
            (*nb_pairs)++;
    }
    *nb_pairs /= 2;
}

void enigma (SDL_Surface* window, SDL_Surface* background){
    SDL_Event event;
    char rotors[5][26] = {
        {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'},
        {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'},
        {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'},
        {'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'},
        {'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'}};
    char plugboard[26];
    char c;
    int positions[3];
    int chosen_rotors[3];
    int wait = 1;
    int press = 0;
    int nb_pairs = 0;

    init_parameters(chosen_rotors, positions);
    init_plugboard(plugboard, &nb_pairs);

    while(wait){
        display_parameters(window, chosen_rotors, positions);
        display_plugboard(window, plugboard);
        
        SDL_WaitEvent(&event);

        switch(event.type){
        case SDL_MOUSEMOTION:
            break;
        case SDL_QUIT:
            wait = 0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
            case SDLK_ESCAPE:
                wait = 0;
                break;
            case SDLK_a:
                if(!press){
                    c = encode_char('A', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'A')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_b:
                if(!press){
                    c = encode_char('B', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'B')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_c:
                if(!press){
                    c = encode_char('C', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'C')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_d:
                if(!press){
                    c = encode_char('D', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'D')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_e:
                if(!press){
                    c = encode_char('E', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'E')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_f:
                if(!press){
                    c = encode_char('F', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'F')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_g:
                if(!press){
                    c = encode_char('G', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'G')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_h:
                if(!press){
                    c = encode_char('H', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'H')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_i:
                if(!press){
                    c = encode_char('I', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'I')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_j:
                if(!press){
                    c = encode_char('J', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'J')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_k:
                if(!press){
                    c = encode_char('K', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'K')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_l:
                if(!press){
                    c = encode_char('L', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'L')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_m:
                if(!press){
                    c = encode_char('M', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'M')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_n:
                if(!press){
                    c = encode_char('N', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'N')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_o:
                if(!press){
                    c = encode_char('O', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'O')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_p:
                if(!press){
                    c = encode_char('P', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'P')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_q:
                if(!press){
                    c = encode_char('Q', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'Q')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_r:
                if(!press){
                    c = encode_char('R', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'R')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_s:
                if(!press){
                    c = encode_char('S', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'S')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_t:
                if(!press){
                    c = encode_char('T', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'T')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_u:
                if(!press){
                    c = encode_char('U', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'U')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_v:
                if(!press){
                    c = encode_char('V', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'V')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_w:
                if(!press){
                    c = encode_char('W', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'W')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_x:
                if(!press){
                    c = encode_char('X', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'X')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_y:
                if(!press){
                    c = encode_char('Y', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'Y')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_z:
                if(!press){
                    c = encode_char('Z', rotors, chosen_rotors, positions, plugboard);
                    if(c != 'Z')
                        display_letter(window, c);
                    press = 1;
                }
                break;
            case SDLK_SPACE:
                init_parameters(chosen_rotors, positions);
                break;
            case SDLK_BACKSPACE:
                init_plugboard(plugboard, &nb_pairs);
                break;
            case SDLK_RETURN:
                if(chosen_rotors[0] != -1)
                    positions[0] = 0;
                if(chosen_rotors[1] != -1)
                    positions[1] = 0;
                if(chosen_rotors[2] != -1)
                    positions[2] = 0;
                break;
            case SDLK_KP_ENTER:
                random_parameters(chosen_rotors, positions);
                break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            if(press){
                turn_off(window, background, c);
                press = 0;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            test_click(chosen_rotors, positions, plugboard, &nb_pairs, event.button.x, event.button.y);
            break;
        case SDL_MOUSEBUTTONUP:
            break;
        default:
            break;
        }
    }
}

void test_click (int* chosen_rotors, int* positions, char* plugboard, int* nb_pairs, int x, int y){
    srand(time(NULL));

    if(x >= 182 && x <= 192 && y >= 56 && y <= 66){
        if(positions[2] != -1)
            positions[2] = (positions[2] + 1) % 26;
    }

    if(x >= 244 && x <= 254 && y >= 56 && y <= 66){
        if(positions[1] != -1)
            positions[1] = (positions[1] + 1) % 26;
    }

    if(x >= 306 && x <= 316 && y >= 56 && y <= 66){
        if(positions[0] != -1)
            positions[0] = (positions[0] + 1) % 26;
    }

    if(x >= 182 && x <= 192 && y >= 132 && y <= 142){
        if(positions[2] != -1){
            positions[2] -= 1;
            if(positions[2] < 0)
                positions[2] += 26;
        }
    }

    if(x >= 244 && x <= 254 && y >= 132 && y <= 142){
        if(positions[1] != -1){
            positions[1] -= 1;
            if(positions[1] < 0)
                positions[1] += 26;
        }
    }

    if(x >= 306 && x <= 316 && y >= 132 && y <= 142){
        if(positions[0] != -1){
            positions[0] -= 1;
            if(positions[0] < 0)
                positions[0] += 26;
        }
    }

    if(x >= 200 && x <= 229 && y >= 171 && y <= 195){
        positions[2] = rand() % 26;
        do{
            chosen_rotors[2] = (chosen_rotors[2] + 1) % 5;
        }while(chosen_rotors[2] == chosen_rotors[1] || chosen_rotors[0] == chosen_rotors[2]);
    }

    if(x >= 262 && x <= 291 && y >= 171 && y <= 195){
        positions[1] = rand() % 26;
        do{
            chosen_rotors[1] = (chosen_rotors[1] + 1) % 5;
        }while(chosen_rotors[1] == chosen_rotors[0] || chosen_rotors[1] == chosen_rotors[2]);
    }

    if(x >= 324 && x <= 353 && y >= 171 && y <= 195){
        positions[0] = rand() % 26;
        do{
            chosen_rotors[0] = (chosen_rotors[0] + 1) % 5;
        }while(chosen_rotors[0] == chosen_rotors[1] || chosen_rotors[2] == chosen_rotors[0]);
    }


    if(x >= 18 && x <= 31 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'A', nb_pairs);
    if(x >= 40 && x <= 53 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'B', nb_pairs);
    if(x >= 62 && x <= 75 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'C', nb_pairs);
    if(x >= 84 && x <= 97 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'D', nb_pairs);
    if(x >= 106 && x <= 119 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'E', nb_pairs);
    if(x >= 128 && x <= 141 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'F', nb_pairs);
    if(x >= 150 && x <= 163 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'G', nb_pairs);
    if(x >= 172 && x <= 185 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'H', nb_pairs);
    if(x >= 194 && x <= 207 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'I', nb_pairs);
    if(x >= 216 && x <= 229 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'J', nb_pairs);
    if(x >= 238 && x <= 251 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'K', nb_pairs);
    if(x >= 260 && x <= 273 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'L', nb_pairs);
    if(x >= 282 && x <= 295 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'M', nb_pairs);
    if(x >= 304 && x <= 317 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'N', nb_pairs);
    if(x >= 326 && x <= 339 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'O', nb_pairs);
    if(x >= 348 && x <= 361 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'P', nb_pairs);
    if(x >= 370 && x <= 383 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'Q', nb_pairs);
    if(x >= 392 && x <= 405 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'R', nb_pairs);
    if(x >= 414 && x <= 427 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'S', nb_pairs);
    if(x >= 436 && x <= 449 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'T', nb_pairs);
    if(x >= 458 && x <= 471 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'U', nb_pairs);
    if(x >= 480 && x <= 493 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'V', nb_pairs);
    if(x >= 502 && x <= 515 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'W', nb_pairs);
    if(x >= 524 && x <= 537 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'X', nb_pairs);
    if(x >= 546 && x <= 559 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'Y', nb_pairs);
    if(x >= 568 && x <= 581 && y >= 607 && y <= 625)
        change_plugboard(plugboard, 'Z', nb_pairs);
}

void change_plugboard (char* plugboard, char c, int* nb_pairs){
    SDL_Event event;
    char click;
    int wait = 1;
    int i, x, y;
  
    while(wait && (*nb_pairs < 10 || plugboard[c - 'A'] != c)){
        SDL_WaitEvent(&event);

        if(event.type == SDL_KEYDOWN)
            wait = 0;
        else if(event.type == SDL_QUIT)
            exit(EXIT_SUCCESS);
        else if(event.type == SDL_MOUSEBUTTONDOWN){
            wait = 0;

            x = event.button.x;
            y = event.button.y;
      
            if(x >= 18 && x <= 31 && y >= 664 && y <= 679)
                click = 'A';
            else if(x >= 40 && x <= 53 && y >= 664 && y <= 679)
                click = 'B';
            else if(x >= 62 && x <= 75 && y >= 664 && y <= 679)
                click = 'C';
            else if(x >= 84 && x <= 97 && y >= 664 && y <= 679)
                click = 'D';
            else if(x >= 106 && x <= 119 && y >= 664 && y <= 679)
                click = 'E';
            else if(x >= 128 && x <= 141 && y >= 664 && y <= 679)
                click = 'F';
            else if(x >= 150 && x <= 163 && y >= 664 && y <= 679)
                click = 'G';
            else if(x >= 172 && x <= 185 && y >= 664 && y <= 679)
                click = 'H';
            else if(x >= 194 && x <= 207 && y >= 664 && y <= 679)
                click = 'I';
            else if(x >= 216 && x <= 229 && y >= 664 && y <= 679)
                click = 'J';
            else if(x >= 238 && x <= 251 && y >= 664 && y <= 679)
                click = 'K';
            else if(x >= 260 && x <= 273 && y >= 664 && y <= 679)
                click = 'L';
            else if(x >= 282 && x <= 295 && y >= 664 && y <= 679)
                click = 'M';
            else if(x >= 304 && x <= 317 && y >= 664 && y <= 679)
                click = 'N';
            else if(x >= 326 && x <= 339 && y >= 664 && y <= 679)
                click = 'O';
            else if(x >= 348 && x <= 361 && y >= 664 && y <= 679)
                click = 'P';
            else if(x >= 370 && x <= 383 && y >= 664 && y <= 679)
                click = 'Q';
            else if(x >= 392 && x <= 405 && y >= 664 && y <= 679)
                click = 'R';
            else if(x >= 414 && x <= 427 && y >= 664 && y <= 679)
                click = 'S';
            else if(x >= 436 && x <= 449 && y >= 664 && y <= 679)
                click = 'T';
            else if(x >= 458 && x <= 471 && y >= 664 && y <= 679)
                click = 'U';
            else if(x >= 480 && x <= 493 && y >= 664 && y <= 679)
                click = 'V';
            else if(x >= 502 && x <= 515 && y >= 664 && y <= 679)
                click = 'W';
            else if(x >= 524 && x <= 537 && y >= 664 && y <= 679)
                click = 'X';
            else if(x >= 546 && x <= 559 && y >= 664 && y <= 679)
                click = 'Y';
            else if(x >= 568 && x <= 581 && y >= 664 && y <= 679)
                click = 'Z';

            if(plugboard[click - 'A'] == click && plugboard[c - 'A'] == c){
                plugboard[c - 'A'] = click;
                plugboard[click - 'A'] = c;
            }else if(plugboard[click - 'A'] == c && plugboard[c - 'A'] == click){
                plugboard[c - 'A'] = c;
                plugboard[click - 'A'] = click;
            }
        }

        *nb_pairs = 0;
        for(i = 0; i < 26; i++){
            if(plugboard[i] != i + 'A')
                (*nb_pairs)++;
        }
        *nb_pairs /= 2;
    }
}
