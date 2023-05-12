
#include <SDL2/SDL.h>
#include "def_types_et_vars.h"
#include <stdio.h>
#include <stdlib.h>

void draw_matrix(SDL_Renderer** pRenderer,int** matrice, bloc* falling_meteor){
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrice[i][j]!=0){
                //il faut descendre une fois de plus
                falling_meteor->y=falling_meteor->y+going_down;
                
                SDL_Rect carreau = {j*taille_carreau, i*taille_carreau, taille_carreau, taille_carreau};
                if (matrice[i][j]==1){
                SDL_SetRenderDrawColor(*pRenderer, 64, 224, 208, 255);
                }
                if (matrice[i][j]==2){
                SDL_SetRenderDrawColor(*pRenderer, 255, 255, 0, 255);
                }
                if (matrice[i][j]==3){
                SDL_SetRenderDrawColor(*pRenderer, 64, 224, 208, 255);
                } //METTRE LES BONNES COULEURS
                if (matrice[i][j]==4){
                SDL_SetRenderDrawColor(*pRenderer, 64, 224, 208, 255);
                }
                if (matrice[i][j]==5){
                SDL_SetRenderDrawColor(*pRenderer, 64, 224, 208, 255);
                }
                if (matrice[i][j]==6){
                SDL_SetRenderDrawColor(*pRenderer, 64, 224, 208, 255);
                }

            
            SDL_RenderFillRect(*pRenderer, &carreau);
            }
        }
    }
    
}


void pre_render(SDL_Renderer** pRenderer, bloc * falling_meteor, int** matrice){
    printf("remise à zero du rendu\n");
    //On remet d'abort à zero le rendu
    SDL_SetRenderDrawColor(*pRenderer, 0, 0, 0, 255); //noir
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
                rectangle2.x = falling_meteor->x+taille_carreau;
                rectangle2.y = falling_meteor->y+taille_carreau;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y+taille_carreau;
                rectangle.w = 3*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x+taille_carreau;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==1){
                rectangle.x = falling_meteor->x+taille_carreau;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 3*taille_carreau;
                rectangle2.x = falling_meteor->x;
                rectangle2.y = falling_meteor->y+taille_carreau;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==3){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 3*taille_carreau;
                rectangle2.x = falling_meteor->x+taille_carreau;
                rectangle2.y = falling_meteor->y+taille_carreau;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }

            // Affichage des rectangles
            SDL_RenderFillRect(*pRenderer, &rectangle);
            SDL_RenderFillRect(*pRenderer, &rectangle2);

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
                rectangle2.y = falling_meteor->y+taille_carreau;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y+taille_carreau;
                rectangle.w = 3*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x+2*taille_carreau;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==1){
                rectangle.x = falling_meteor->x+taille_carreau;
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
                rectangle2.x = falling_meteor->x+taille_carreau;
                rectangle2.y = falling_meteor->y+2*taille_carreau;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }

            // Affichage des rectangles
            SDL_RenderFillRect(*pRenderer, &rectangle);
            SDL_RenderFillRect(*pRenderer, &rectangle2);

            break;

        case J:
            // Définition de la couleur du rectangle (bleu)
            SDL_SetRenderDrawColor(*pRenderer, 0, 0, 255, 255);
            
            if (falling_meteor->rotation==0){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = 3*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x+2*taille_carreau;
                rectangle2.y = falling_meteor->y+taille_carreau;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y+taille_carreau;
                rectangle.w = 3*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==1){
                rectangle.x = falling_meteor->x+taille_carreau;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 3*taille_carreau;
                rectangle2.x = falling_meteor->x;
                rectangle2.y = falling_meteor->y+2*taille_carreau;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==3){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 3*taille_carreau;
                rectangle2.x = falling_meteor->x+taille_carreau;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = taille_carreau;
            }
            // Affichage des rectangles
            SDL_RenderFillRect(*pRenderer, &rectangle);
            SDL_RenderFillRect(*pRenderer, &rectangle2);

            
            break;
        case Z:
            // Définition de la couleur du rectangle (rouge)
            SDL_SetRenderDrawColor(*pRenderer, 255, 0, 0, 255);
            
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = 2*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x+taille_carreau;
                rectangle2.y = falling_meteor->y+taille_carreau;
                rectangle2.w = 2*taille_carreau;
                rectangle2.h = taille_carreau;
            }

            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y+taille_carreau;
                rectangle.w = taille_carreau;
                rectangle.h = 2*taille_carreau;
                rectangle2.x = falling_meteor->x+taille_carreau;
                rectangle2.y = falling_meteor->y;
                rectangle2.w = taille_carreau;
                rectangle2.h = 2*taille_carreau;
            }
            // Affichage des rectangles
            SDL_RenderFillRect(*pRenderer, &rectangle);
            SDL_RenderFillRect(*pRenderer, &rectangle2);

            break; 

        default : //case S
            // Définition de la couleur du rectangle (vert)
            SDL_SetRenderDrawColor(*pRenderer, 0, 255, 0, 255);
            
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x+taille_carreau;
                rectangle.y = falling_meteor->y;
                rectangle.w = 2*taille_carreau;
                rectangle.h = taille_carreau;
                rectangle2.x = falling_meteor->x;
                rectangle2.y = falling_meteor->y+taille_carreau;
                rectangle2.w = 2*taille_carreau;
                rectangle2.h = taille_carreau;
            }
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h = 2*taille_carreau;
                rectangle2.x = falling_meteor->x+taille_carreau;
                rectangle2.y = falling_meteor->y+taille_carreau;
                rectangle2.w = taille_carreau;
                rectangle2.h = 2*taille_carreau;
            }

            // Affichage des rectangles
            SDL_RenderFillRect(*pRenderer, &rectangle);
            SDL_RenderFillRect(*pRenderer, &rectangle2);

            break;

    }
printf("numero6\n");

//dessin des blocs déjà tombés
draw_matrix(pRenderer,matrice, falling_meteor);

// Mise à jour du rendu
SDL_RenderPresent(*pRenderer);

}
