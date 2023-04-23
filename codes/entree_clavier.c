#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "rotation.h"
#include "down.h"

//entree clavier non bloquante 
//touche Q pour tourner le bloc vers la gauche 
//touche D pour tourner le bloc vers la droite 
//touche S pour faire descendre le bloc

void entree_clavier (){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN:

                if (event.key.keysym.sym == SDLK_q)
                    rotation(-1);
                if (event.key.keysym.sym == SDLK_s)
                    down(); //chute du bloc, à programmer 
                if (event.key.keysym.sym == SDLK_d)
                    rotation(1);

                break;
        }
    }
}



/*
void entree_clavier (){

    while (SDL_PollEvent(&events)) {
        switch(events.type) {
        case SDL_KEYDOWN:

            if (events.key.keysym.sym == SDLK_Q)
                rotation(-1);
            if (events.key.keysym.sym == SDLK_S)
                down(); //chute du bloc, à programmer 
            if (events.key.keysym.sym == SDLK_D)
                rotation(1);

            break;
        }
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
*/