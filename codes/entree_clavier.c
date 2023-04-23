#include "allinclude.h"

//entree clavier non bloquante 
//touche Q pour tourner le bloc vers la gauche 
//touche D pour tourner le bloc vers la droite 
//touche S pour faire descendre le bloc

while (run) {
    while (SDL_PollEvent(&events)) {
        switch(events.type) {
        case SDL_KEYDOWN:

            if (events.key.keysym.sym == SDLK_Q)
                rotation(-1);
            if (events.key.keysym.sym == SDLK_S)
                down(); //chute du bluc, à programmer 
            if (events.key.keysym.sym == SDLK_D)
                rotation(1);

            break;
        }
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}