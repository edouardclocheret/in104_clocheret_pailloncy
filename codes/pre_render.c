#include "def_types_et_vars.h"
#include <SDL2/SDL.h>

void pre_renderer(SDL_Renderer* pRenderer){
    
    // Définition de la couleur du rectangle
    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);

    // Création du rectangle
    SDL_Rect rectangle = { 100, 100, 200, 200 };

    // Affichage du rectangle
    SDL_RenderFillRect(pRenderer, &rectangle);

    // Mise à jour du rendu
    SDL_RenderPresent(pRenderer);


}