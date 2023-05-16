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

void entree_clavier (bloc* falling_meteor, SDL_Event* event, SDL_bool* quit){
    
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
                    int x1; 
                    int x2; 
                    int x3; 
                    int x4; 
                    switch (falling_meteor->son_nom){
                                    case I :
                                        
                                        if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                                            
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x2;
                                            x4 = x3;
                                            
                                        }
                                    break;


                                    case O :
                                        x1 = falling_meteor->x/taille_carreau;
                                        x2 = x1+1;
                                        x3 = x1;
                                        x4 = x2;
                                        break;

                                    case T :
                                        
                                        if (falling_meteor->rotation ==0){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x2;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1+1;
                                            x4 = x1;
                                            
                                        }
                                    break;   

                                    case L :
                                        
                                        if (falling_meteor->rotation ==0){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x2+1;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1;
                                            x4 = x1+1;
                                            
                                        }
                                    break; 

                                    case J :
                                        printf("on est dans case J\n");
                                        if (falling_meteor->rotation ==0){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1){
                                            x1 = falling_meteor->x/taille_carreau+1;
                                            x2 = x1;
                                            x3 = x1;
                                            x4 = x3-1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1+1;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1;
                                            x4 = x1+1;
                                            
                                        }
                                    break; 

                                    case Z :
                                        if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1+1;
                                            x4 = x3;
                                        
                                        }
                                    break; 

                                    case S :
                                        if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x2+1;
                                            x4 = x3;
                                        
                                        }
                                    break; 
                                        }
                    
                    //si l'action n'est pas autorisée on l'annule
                    if (x1>9 || x2>9 || x3>9 || x4>9 ){
                        rotation(1, falling_meteor);
                    }
                }

                if (event->key.keysym.sym == SDLK_d){
                    rotation(1, falling_meteor);
                    //on vérifie que le bloc ne sorte pas du cadre
                    int x1; 
                    int x2; 
                    int x3; 
                    int x4; 
                    switch (falling_meteor->son_nom){
                                    case I :
                                        
                                        if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                                            
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x2;
                                            x4 = x3;
                                            
                                        }
                                    break;


                                    case O :
                                        x1 = falling_meteor->x/taille_carreau;
                                        x2 = x1+1;
                                        x3 = x1;
                                        x4 = x2;
                                        break;

                                    case T :
                                        
                                        if (falling_meteor->rotation ==0){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x2;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1+1;
                                            x4 = x1;
                                            
                                        }
                                    break;   

                                    case L :
                                        
                                        if (falling_meteor->rotation ==0){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x2+1;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1;
                                            x4 = x1+1;
                                            
                                        }
                                    break; 

                                    case J :
                                        printf("on est dans case J\n");
                                        if (falling_meteor->rotation ==0){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1){
                                            x1 = falling_meteor->x/taille_carreau+1;
                                            x2 = x1;
                                            x3 = x1;
                                            x4 = x3-1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1+1;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1;
                                            x4 = x1+1;
                                            
                                        }
                                    break; 

                                    case Z :
                                        if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1+1;
                                            x4 = x3;
                                        
                                        }
                                    break; 

                                    case S :
                                        if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x2+1;
                                            x4 = x3;
                                        
                                        }
                                    break; 
                                        }
                    
                    //si l'action n'est pas autorisée on l'annule
                    if (x1>9 || x2>9 || x3>9 || x4>9 ){
                        rotation(-1, falling_meteor);
                    }
                }

                if (event->key.keysym.sym == SDLK_LEFT){
                    if (falling_meteor->x>0){
                        falling_meteor->x-=taille_carreau;
                    }
                }

                if (event->key.keysym.sym == SDLK_RIGHT){
                    //on vérifie que le bloc ne sorte pas du cadre
                    int x1; 
                    int x2; 
                    int x3; 
                    int x4; 
                    switch (falling_meteor->son_nom){
                                    case I :
                                        
                                        if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                                            
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x2;
                                            x4 = x3;
                                            
                                        }
                                    break;


                                    case O :
                                        x1 = falling_meteor->x/taille_carreau;
                                        x2 = x1+1;
                                        x3 = x1;
                                        x4 = x2;
                                        break;

                                    case T :
                                        
                                        if (falling_meteor->rotation ==0){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x2;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1+1;
                                            x4 = x1;
                                            
                                        }
                                    break;   

                                    case L :
                                        
                                        if (falling_meteor->rotation ==0){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x2+1;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1;
                                            x4 = x1+1;
                                            
                                        }
                                    break; 

                                    case J :
                                        printf("on est dans case J\n");
                                        if (falling_meteor->rotation ==0){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2+1;
                                            x4 = x3;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1){
                                            x1 = falling_meteor->x/taille_carreau+1;
                                            x2 = x1;
                                            x3 = x1;
                                            x4 = x3-1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1+1;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1;
                                            x4 = x1+1;
                                            
                                        }
                                    break; 

                                    case Z :
                                        if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x1+1;
                                            x4 = x3;
                                        
                                        }
                                    break; 

                                    case S :
                                        if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1+1;
                                            x3 = x2;
                                            x4 = x3+1;
                                            
                                        }
                                        else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                                            x1 = falling_meteor->x/taille_carreau;
                                            x2 = x1;
                                            x3 = x2+1;
                                            x4 = x3;
                                        
                                        }
                                    break; 
                                        }
                    
                    //si l'action est autorisée on la fait
                    if (x1<9 && x2<9 && x3<9 && x4<9 ){
                        falling_meteor->x+=taille_carreau;
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