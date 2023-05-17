#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rotation.h"
#include "translate_bloc_to_positions.h"

//entree clavier non bloquante 
//touche Q pour tourner le bloc vers la gauche 
//touche D pour tourner le bloc vers la droite 


//flèche vers la droite pour translation vers la droite
//flèche vers la gauche pour translation vers la gauche

//touche escape pour quitter 

void entree_clavier (bloc* falling_meteor, SDL_Event* event, SDL_bool* quit, int ** matrice){
    
    while (SDL_PollEvent(event)!=0) {

        switch(event->type) {
            
            case SDL_WINDOWEVENT:
                if (event->window.event ==SDL_WINDOWEVENT_CLOSE) *quit = SDL_TRUE;
            break;

            case SDL_QUIT :
            if(event->type == SDL_QUIT) *quit = SDL_TRUE;
            break;

            case SDL_KEYDOWN:

                if (event->key.keysym.sym == SDLK_ESCAPE||event->key.keysym.sym == SDLK_p){
                    *quit = SDL_TRUE;
                }

                if (event->key.keysym.sym == SDLK_q){

                    rotation(-1, falling_meteor);
                    //on vérifie que le bloc ne sorte pas du cadre
                    int x1; int y1;
                    int x2; int y2;
                    int x3; int y3;
                    int x4; int y4;
                    translate_bloc_to_positions(falling_meteor, &x1,&y1, &x2,&y2, &x3,&y3, &x4,&y4);
                    
                    
                    //si l'action n'est pas autorisée on l'annule
                    if (x1<0||x2<0||x3<0||x4<0
                    ||x1>9 || x2>9 || x3>9 || x4>9 
                    ||y1>19 ||y2>19||y3>19||y4>19
                    ||y1<0||y2<0||y3<0||y4<0){
                        //on annule si on sort du cadre
                        rotation(1, falling_meteor);
                    }
                    else if (matrice[y1][x1]!=0 ||matrice[y2][x2]!=0
                    ||matrice[y3][x3]!=0||matrice[y4][x4]!=0){
                        //on annule si la case est déjà occupée
                        rotation(1, falling_meteor);
                    }
                    
                }

                if (event->key.keysym.sym == SDLK_d){
                    rotation(1, falling_meteor);
                    //on vérifie que le bloc ne sorte pas du cadre
                    int x1; int y1;
                    int x2; int y2;
                    int x3; int y3;
                    int x4; int y4;
                    translate_bloc_to_positions(falling_meteor, &x1,&y1, &x2,&y2, &x3,&y3, &x4,&y4);
                    
                    
                    //si l'action n'est pas autorisée on l'annule
                    if (x1<0||x2<0||x3<0||x4<0
                    ||x1>9 || x2>9 || x3>9 || x4>9 
                    ||y1>19 ||y2>19||y3>19||y4>19
                    ||y1<0||y2<0||y3<0||y4<0){
                        //on annule si on sort du cadre
                        rotation(-1, falling_meteor);
                    }
                    else if (matrice[y1][x1]!=0 ||matrice[y2][x2]!=0
                    ||matrice[y3][x3]!=0||matrice[y4][x4]!=0){
                        //on annule si la case est déjà occupée
                        rotation(-1, falling_meteor);
                    }
                }

                if (event->key.keysym.sym == SDLK_LEFT){
                    falling_meteor->x-=taille_carreau;
                    //on vérifie que le bloc ne sorte pas du cadre
                    int x1; int y1;
                    int x2; int y2;
                    int x3; int y3;
                    int x4; int y4;
                    translate_bloc_to_positions(falling_meteor, &x1,&y1, &x2,&y2, &x3,&y3, &x4,&y4);
                    
                    
                    //si l'action n'est pas autorisée on l'annule
                    if (x1<0||x2<0||x3<0||x4<0
                    ||x1>9 || x2>9 || x3>9 || x4>9 
                    ||y1>19 ||y2>19||y3>19||y4>19
                    ||y1<0||y2<0||y3<0||y4<0){
                        //on annule si on sort du cadre
                        falling_meteor->x+=taille_carreau;
                    }
                    else if (matrice[y1][x1]!=0 ||matrice[y2][x2]!=0
                    ||matrice[y3][x3]!=0||matrice[y4][x4]!=0){
                        //on annule si la case est déjà occupée
                        falling_meteor->x+=taille_carreau;
                    }
                    
                }

                if (event->key.keysym.sym == SDLK_RIGHT){
                    //on vérifie que le bloc ne sorte pas du cadre
                     falling_meteor->x+=taille_carreau;
                    //on vérifie que le bloc ne sorte pas du cadre
                    int x1; int y1;
                    int x2; int y2;
                    int x3; int y3;
                    int x4; int y4;
                    translate_bloc_to_positions(falling_meteor, &x1,&y1, &x2,&y2, &x3,&y3, &x4,&y4);
                    
                    
                    //si l'action n'est pas autorisée on l'annule
                    if (x1<0||x2<0||x3<0||x4<0
                    ||x1>9 || x2>9 || x3>9 || x4>9 
                    ||y1>19 ||y2>19||y3>19||y4>19
                    ||y1<0||y2<0||y3<0||y4<0){
                        //on annule si on sort du cadre
                        falling_meteor->x-=taille_carreau;
                    }
                    else if (matrice[y1][x1]!=0 ||matrice[y2][x2]!=0
                    ||matrice[y3][x3]!=0||matrice[y4][x4]!=0){
                        //on annule si la case est déjà occupée
                        falling_meteor->x-=taille_carreau;
                    }
                    
                }
                if (event->key.keysym.sym == SDLK_s){
                    //on vérifie que le bloc ne sorte pas du cadre
                    int x1; int y1;
                        int x2; int y2;
                        int x3; int y3;
                        int x4; int y4;
                        translate_bloc_to_positions(falling_meteor, &x1,&y1, &x2,&y2, &x3,&y3, &x4,&y4);
                    while(x1>0&&x2>0&&x3>0&&x4>0
                    &&x1<9 && x2<9 && x3<9 && x4<9 
                    &&y1<19 &&y2<19&&y3<19&&y4<19
                    &&y1>0&&y2>0&&y3>0&&y4>0&&
                    matrice[y1][x1]!=0 &&matrice[y2][x2]!=0
                    &&matrice[y3][x3]!=0&&matrice[y4][x4]!=0){
                        falling_meteor->y+=taille_carreau;
                        //on vérifie que le bloc ne sorte pas du cadre
                        int x1; int y1;
                        int x2; int y2;
                        int x3; int y3;
                        int x4; int y4;
                        translate_bloc_to_positions(falling_meteor, &x1,&y1, &x2,&y2, &x3,&y3, &x4,&y4);
                    }
                    //si on est sorti du while c'est qu'on a fait un déplacement de trop
                    falling_meteor->y-=taille_carreau; 
                    
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