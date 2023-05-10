
#include <SDL2/SDL.h>
#include "def_types_et_vars.h"
#include <stdio.h>

void pre_render(SDL_Renderer** pRenderer, bloc * falling_meteor){
    
    //On remet d'abort à zero le rendu
    SDL_RenderClear(*pRenderer);
    printf("numero1\n");
    
    
    SDL_Rect rectangle;
    SDL_Rect rectangle2;
    printf("numero2\n");
    switch(falling_meteor->son_nom){
        case I :
            // Définition de la couleur du rectangle (turquoise)
            SDL_SetRenderDrawColor(*pRenderer, 64, 224, 208, 255);
            printf("numero3\n");
            rectangle.x = falling_meteor->x;
            rectangle.y = falling_meteor->y;
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle.w = 4*taille_carreau;
                rectangle.h = taille_carreau;

            }
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle.w = taille_carreau;
                rectangle.h =4*taille_carreau;
    
            }
            printf("numero4\n");
            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);
            printf("numero5\n");
            break;

        case O:
            // Définition de la couleur du rectangle (jaune)
            SDL_SetRenderDrawColor(*pRenderer, 255, 255, 0, 255);
            rectangle.x = falling_meteor->x;
            rectangle.y = falling_meteor->y;
            rectangle.w = 2*taille_carreau;
            rectangle.h =2*taille_carreau;
    
            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            break;

        case T:
            // Définition de la couleur du rectangle (violet)
            SDL_SetRenderDrawColor(*pRenderer, 127, 0, 255, 255);

            if (falling_meteor->rotation==0){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = 3*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x+1;
                rectangle2.y = falling_meteor->y+1;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y+1;
                rectangle.w = 3*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x+1;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==1){
                rectangle.x = falling_meteor->x+1;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 3*taille_carreau;
                rectangle2.x = falling_meteor->x;
                rectangle2.y = falling_meteor->y+1;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==3){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 3*taille_carreau;
                rectangle2.x = falling_meteor->x+1;
                rectangle2.y = falling_meteor->y+1;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }

            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            break;

        case L:
             // Définition de la couleur du rectangle (orange)
            SDL_SetRenderDrawColor(*pRenderer, 255, 128, 0, 255);
            
            if (falling_meteor->rotation==0){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = 3*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x;
                rectangle2.y = falling_meteor->y+1;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y+1;
                rectangle.w = 3*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x+2;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==1){
                rectangle.x = falling_meteor->x+1;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 3*taille_carreau;
                rectangle2.x = falling_meteor->x;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==3){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 3*taille_carreau;
                rectangle2.x = falling_meteor->x+1;
                rectangle2.y = falling_meteor->y+2;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }

            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            break;

        case J:
            // Définition de la couleur du rectangle (bleu)
            SDL_SetRenderDrawColor(*pRenderer, 0, 0, 255, 255);
            
            if (falling_meteor->rotation==0){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = 3*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x+2;
                rectangle2.y = falling_meteor->y+1;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y+1;
                rectangle.w = 3*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==1){
                rectangle.x = falling_meteor->x+1;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 3*taille_carreau;
                rectangle2.x = falling_meteor->x;
                rectangle2.y = falling_meteor->y+2;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==3){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 3*taille_carreau;
                rectangle2.x = falling_meteor->x+1;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            
            break;
        case Z:
            // Définition de la couleur du rectangle (rouge)
            SDL_SetRenderDrawColor(*pRenderer, 255, 0, 0, 255);
            
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = 2*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x+1;
                rectangle2.y = falling_meteor->y+1;
                rectangle2.w = 2*taille_carreau;
                rectangle2.h = taille_carreau;
            }

            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y+1;
                rectangle.w = taille_carreau;
                rectangle.h = 2*taille_carreau;
                rectangle2.x = falling_meteor->x+1;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = 2*taille_carreau;
            }
            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            break; 

        default : //case S
            // Définition de la couleur du rectangle (vert)
            SDL_SetRenderDrawColor(*pRenderer, 0, 255, 0, 255);
            
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x+1;
                rectangle.y = falling_meteor->y;
                rectangle.w = 2*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x;
                rectangle2.y = falling_meteor->y+1;
                rectangle2.w = 2*taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 2*taille_carreau;
                rectangle2.x = falling_meteor->x+1;
                rectangle2.y = falling_meteor->y+1;
                rectangle2.w = taille_carreau;
                rectangle2.h = 2*taille_carreau;
            }

            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            break;

    }
printf("numero6\n");
// Mise à jour du rendu
SDL_RenderPresent(*pRenderer);

}
