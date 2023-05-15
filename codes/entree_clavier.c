#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rotation.h"
#include "down.h"

//entree clavier non bloquante 
//touche Q pour tourner le bloc vers la gauche 
//touche D pour tourner le bloc vers la droite 


//flèche vers la droite pour translation vers la droite
//flèche vers la gauche pour translation vers la gauche

//touche escape pour quitter 

void entree_clavier (bloc* falling_meteor, SDL_Event* event, bool* quit){
    
    while (SDL_PollEvent(event)) {
        switch(event->type) {
            case SDL_KEYDOWN:

                if (event->key.keysym.sym == SDLK_ESCAPE){
                    *quit = true;
                }

                if (event->key.keysym.sym == SDLK_q){
                    rotation(-1, falling_meteor);
                }

                if (event->key.keysym.sym == SDLK_d){
                    rotation(1, falling_meteor);
                }

                if (event->key.keysym.sym == SDLK_LEFT){
                    if (falling_meteor->x>0){
                        falling_meteor->x-=1;
                    }
                }

                if (event->key.keysym.sym == SDLK_RIGHT){
                    if (falling_meteor->x<19*taille_carreau){
                        falling_meteor->x+=1;
                    }
                }
                

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