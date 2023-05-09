
#include <SDL2/SDL.h>
#include "def_types_et_vars.h"

void pre_render(SDL_Renderer** pRenderer, bloc * falling_meteor){
    SDL_Rect rectangle;
    switch(falling_meteor->son_nom){
        case I :
            // Définition de la couleur du rectangle (turquoise)
            SDL_SetRenderDrawColor(*pRenderer, 255, 0, 255, 255);


            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = 4*taille_carreau;
                rectangle.h = taille_carreau;

            }
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle.x = falling_meteor->x;
                rectangle.y = falling_meteor->y;
                rectangle.w = taille_carreau;
                rectangle.h =4*taille_carreau;
    
            }

            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            break;
            
        case O:
            // Définition de la couleur du rectangle (jaune)
            SDL_SetRenderDrawColor(*pRenderer, 255, 255, 0, 255);

            rectangle = { falling_meteor->x-2*taille_carreau, 
                                        falling_meteor->y-2*taille_carreau, 
                                        2*taille_carreau, 2*taille_carreau };
            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            
            break;
        case T:
            // Définition de la couleur du rectangle (violet)
            SDL_SetRenderDrawColor(*pRenderer, 255, 0, 255, 255);
            
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle = { falling_meteor->x-3*taille_carreau, 
                                        falling_meteor->y-2*taille_carreau, 
                                        3*taille_carreau, 2*taille_carreau };}
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle = { falling_meteor->x-2*taille_carreau, 
                                        falling_meteor->y-3*taille_carreau, 
                                        3*taille_carreau, 2*taille_carreau };}
            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            break;
        case L:
             // Définition de la couleur du rectangle (orange)
            SDL_SetRenderDrawColor(*pRenderer, 255, 128, 0, 255);
            
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle = { falling_meteor->x-3*taille_carreau, 
                                        falling_meteor->y-2*taille_carreau, 
                                        3*taille_carreau, 2*taille_carreau };}
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle = { falling_meteor->x-2*taille_carreau, 
                                        falling_meteor->y-3*taille_carreau, 
                                        3*taille_carreau, 2*taille_carreau };}

            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            
            break;
        case J:
            // Définition de la couleur du rectangle (bleu)
            SDL_SetRenderDrawColor(*pRenderer, 0, 0, 255, 255);
            
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle = { falling_meteor->x-3*taille_carreau, 
                                        falling_meteor->y-2*taille_carreau, 
                                        3*taille_carreau, 2*taille_carreau };}
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle = { falling_meteor->x-2*taille_carreau, 
                                        falling_meteor->y-3*taille_carreau, 
                                        3*taille_carreau, 2*taille_carreau };}

            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            
            break;
        case Z:
            // Définition de la couleur du rectangle (rouge)
            SDL_SetRenderDrawColor(*pRenderer, 255, 0, 0, 255);
            
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle = { falling_meteor->x-3*taille_carreau, 
                                        falling_meteor->y-2*taille_carreau, 
                                        3*taille_carreau, 2*taille_carreau };}
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle = { falling_meteor->x-2*taille_carreau, 
                                        falling_meteor->y-3*taille_carreau, 
                                        3*taille_carreau, 2*taille_carreau };}

            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            
            break;
        default : //case S
            // Définition de la couleur du rectangle (vert)
            SDL_SetRenderDrawColor(*pRenderer, 0, 255, 0, 255);
            
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                rectangle = { falling_meteor->x-3*taille_carreau, 
                                        falling_meteor->y-2*taille_carreau, 
                                        3*taille_carreau, 2*taille_carreau };}
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                rectangle = { falling_meteor->x-2*taille_carreau, 
                                        falling_meteor->y-3*taille_carreau, 
                                        3*taille_carreau, 2*taille_carreau };}

            // Affichage du rectangle
            SDL_RenderFillRect(*pRenderer, &rectangle);

            break;
        
    }
// Mise à jour du rendu
SDL_RenderPresent(*pRenderer);

}