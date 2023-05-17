#ifndef TYPES_ET_VARS 
#define TYPES_ET_VARS
#include "def_types_et_vars.h"
#endif
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void translate_bloc_to_positions(bloc* falling_meteor, int*x1,int*y1, int*x2,int*y2, int*x3,int*y3, int*x4,int*y4){

    switch (falling_meteor->son_nom){
        case I :
            if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1+1;
                *x3 = *x2+1;
                *x4 = *x3+1;
                //on prend la partie entière parce qu'il n'y a pas de collision
                // si on occupe une demie- case
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1;
                *y3 = *y1;
                *y4 = *y1;
            }
            else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1;
                *x3 = *x2;
                *x4 = *x3;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1+1;
                *y3 = *y2+1;
                *y4 = *y3+1;
            }
        break;


        case O :
            *x1 = falling_meteor->x/taille_carreau;
            *x2 = *x1+1;
            *x3 = *x1;
            *x4 = *x2;
            *y1 = falling_meteor->y/taille_carreau;
            *y2 = *y1;
            *y3 = *y1+1;
            *y4 = *y3;
            break;

        case T :
            if (falling_meteor->rotation ==0){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1+1;
                *x3 = *x2+1;
                *x4 = *x2;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1;
                *y3 = *y1;
                *y4 = *y1+1;
            }
            else if (falling_meteor->rotation ==1){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1+1;
                *x3 = *x2;
                *x4 = *x3;
                *y1 = falling_meteor->y/taille_carreau+1;
                *y2 = *y1-1;
                *y3 = *y1;
                *y4 = *y1+1;
            }
            else if (falling_meteor->rotation ==2){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1+1;
                *x3 = *x2;
                *x4 = *x3+1;
                *y1 = falling_meteor->y/taille_carreau+1;
                *y2 = *y1-1;
                *y3 = *y1;
                *y4 = *y1;
            }
            else if (falling_meteor->rotation ==3){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1;
                *x3 = *x1+1;
                *x4 = *x1;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1+1;
                *y3 = *y2;
                *y4 = *y2+1;
            }
        break;   

        case L :
            if (falling_meteor->rotation ==0){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1;
                *x3 = *x2+1;
                *x4 = *x3+1;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1+1;
                *y3 = *y1;
                *y4 = *y1;
            }
            else if (falling_meteor->rotation ==1){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1+1;
                *x3 = *x2;
                *x4 = *x3;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1;
                *y3 = *y1+1;
                *y4 = *y3+1;
            }
            else if (falling_meteor->rotation ==2){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1+1;
                *x3 = *x2+1;
                *x4 = *x3;
                *y1 = falling_meteor->y/taille_carreau+1;
                *y2 = *y1;
                *y3 = *y1;
                *y4 =*y1-1;
            }
            else if (falling_meteor->rotation ==3){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1;
                *x3 = *x1;
                *x4 = *x1+1;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1+1;
                *y3 = *y2+1;
                *y4 = *y3;
            }
        break; 

        case J :
            if (falling_meteor->rotation ==0){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1+1;
                *x3 = *x2+1;
                *x4 = *x3;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1;
                *y3 = *y1;
                *y4 = *y1+1;
            }
            else if (falling_meteor->rotation ==1){
                *x1 = falling_meteor->x/taille_carreau+1;
                *x2 = *x1;
                *x3 = *x1;
                *x4 = *x3-1;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1+1;
                *y3 = *y2+1;
                *y4 = *y3;
            }
            else if (falling_meteor->rotation ==2){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1;
                *x3 = *x1+1;
                *x4 = *x3+1;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1+1;
                *y3 = *y1+1;
                *y4 = *y1+1;
            }
            else if (falling_meteor->rotation ==3){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1;
                *x3 = *x1;
                *x4 = *x1+1;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1+1;
                *y3 = *y2+1;
                *y4 = *y3;
            }
        break; 

        case Z :
            if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1+1;
                *x3 = *x2;
                *x4 = *x3+1;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1;
                *y3 = *y1+1;
                *y4 = *y3;
            }
            else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1;
                *x3 = *x1+1;
                *x4 = *x3;
                *y1 = falling_meteor->y/taille_carreau+1;
                *y2 = *y1+1;
                *y3 = *y1-1;
                *y4 = *y1;
            }
        break; 

        case S :
            if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1+1;
                *x3 = *x2;
                *x4 = *x3+1;
                *y1 = falling_meteor->y/taille_carreau+1;
                *y2 = *y1;
                *y3 = *y2-1;
                *y4 = *y3;
            }
            else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                *x1 = falling_meteor->x/taille_carreau;
                *x2 = *x1;
                *x3 = *x2+1;
                *x4 = *x3;
                *y1 = falling_meteor->y/taille_carreau;
                *y2 = *y1+1;
                *y3 = *y2;
                *y4 = *y3+1;
            }
        
        break; 
            }
}