#include <SDL2/SDL.h>


int initialisation(){
    if(SDL_Init(SDL_INIT_VIDEO) <0 || SDL_Init(SDL_INIT_AUDIO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1;
    }
    return 0;
}
