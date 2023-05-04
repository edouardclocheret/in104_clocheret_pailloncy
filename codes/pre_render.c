
#include <SDL2/SDL.h>
#include "def_types_et_vars.h"

void pre_render(SDL_Renderer* pRenderer, bloc * falling_meteor){
    switch(falling_meteor->son_nom){
        case I :
            // Définition de la couleur du rectangle
            SDL_SetRenderDrawColor(pRenderer, 255, 0, 255, 255);
            // Création du rectangle
            SDL_Rect rectangle;
            
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle = { falling_meteor->x-4*taille_carreau, 
                                        falling_meteor->y-taille_carreau, 
                                        4*taille_carreau, taille_carreau };
            }
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle = { falling_meteor->x-taille_carreau, 
                                        falling_meteor->y-4*taille_carreau, 
                                        4*taille_carreau, taille_carreau };
            }

            // Affichage du rectangle
            SDL_RenderFillRect(pRenderer, &rectangle);

            // Mise à jour du rendu
            SDL_RenderPresent(pRenderer);
            break;
        case O:
            break;
        case T:
            break;
        case L:
            break;
        case J:
            break;
        case Z:
            break;
        case S:
            break;
    }


}