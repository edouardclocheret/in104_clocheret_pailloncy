#ifndef TYPES_ET_VARS 
#define TYPES_ET_VARS
#include "def_types_et_vars.h"
#endif
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** create_matrix (int lignes, int colonnes){

    // Allocation dynamique de la mémoire pour la matrice
    int** matrice = (int**)malloc(lignes * sizeof(int*));
    for (int i = 0; i < lignes; i++) {
        matrice[i] = (int*)malloc(colonnes * sizeof(int));
    }

    // Initialisation de la matrice avec des zéros partout
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            matrice[i][j] = 0;
        }
    }
    return matrice;
}

bool collision(bloc* falling_meteor, int** matrice){
    ///////////////////////////////
    //    traduction             //
    ///////////////////////////////

    //ie traduire le bloc en ses 4 coordonnées des cases occupées
    //arrondies à la case du dessus (si le bloc occupe que la moitié de la case, il n'y a pas encore collision)
    int x1; int y1;
    int x2; int y2;
    int x3; int y3;
    int x4; int y4;

    switch (falling_meteor->son_nom){
        case I :
            printf("on est dans case I\n");
            if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                printf("et rotation paire\n");
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1+1;
                x3 = x2+1;
                x4 = x3+1;
                //on prend la partie entière parce qu'il n'y a pas de collision
                // si on occupe une demie- case
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1;
                y3 = y1;
                y4 = y1;
            }
            else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1;
                x3 = x2;
                x4 = x3;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1+1;
                y3 = y2+1;
                y4 = y3+1;
            }
        printf("%d,%d %d,%d %d,%d %d,%d\n", x1,y1,x2,y2,x3,y3,x4,y4);
        break;


        case O :
            printf("on est dans case O\n");
            x1 = falling_meteor->x/taille_carreau;
            x2 = x1+1;
            x3 = x1;
            x4 = x2;
            y1 = falling_meteor->y/taille_carreau;
            y2 = y1;
            y3 = y1+1;
            y4 = y3;
            printf("%d,%d %d,%d %d,%d %d,%d\n", x1,y1,x2,y2,x3,y3,x4,y4);
            break;

        case T :
            printf("on est dans case T\n");
            if (falling_meteor->rotation ==0){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1+1;
                x3 = x2+1;
                x4 = x2;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1;
                y3 = y1;
                y4 = y1+1;
            }
            else if (falling_meteor->rotation ==1){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1+1;
                x3 = x2;
                x4 = x3;
                y1 = falling_meteor->y/taille_carreau+1;
                y2 = y1-1;
                y3 = y1;
                y4 = y1+1;
            }
            else if (falling_meteor->rotation ==2){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1+1;
                x3 = x2;
                x4 = x3+1;
                y1 = falling_meteor->y/taille_carreau+1;
                y2 = y1-1;
                y3 = y1;
                y4 = y1;
            }
            else if (falling_meteor->rotation ==3){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1;
                x3 = x1+1;
                x4 = x1;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1+1;
                y3 = y2;
                y4 = y2+1;
            }
        printf("%d,%d %d,%d %d,%d %d,%d\n", x1,y1,x2,y2,x3,y3,x4,y4);
        break;   

        case L :
            printf("on est dans case L\n");
            if (falling_meteor->rotation ==0){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1;
                x3 = x2+1;
                x4 = x3+1;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1+1;
                y3 = y1;
                y4 = y1;
            }
            else if (falling_meteor->rotation ==1){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1+1;
                x3 = x2;
                x4 = x3;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1;
                y3 = y1+1;
                y4 = y3+1;
            }
            else if (falling_meteor->rotation ==2){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1+1;
                x3 = x2+1;
                x4 = x3;
                y1 = falling_meteor->y/taille_carreau+1;
                y2 = y1;
                y3 = y1;
                y4 = y1-1;
            }
            else if (falling_meteor->rotation ==3){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1;
                x3 = x1;
                x4 = x1+1;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1+1;
                y3 = y2+1;
                y4 = y3;
            }
        printf("%d,%d %d,%d %d,%d %d,%d\n", x1,y1,x2,y2,x3,y3,x4,y4);
        break; 

        case J :
            printf("on est dans case J\n");
            if (falling_meteor->rotation ==0){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1+1;
                x3 = x2+1;
                x4 = x3;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1;
                y3 = y1;
                y4 = y1+1;
            }
            else if (falling_meteor->rotation ==1){
                x1 = falling_meteor->x/taille_carreau+1;
                x2 = x1;
                x3 = x1;
                x4 = x3-1;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1+1;
                y3 = y2+1;
                y4 = y3;
            }
            else if (falling_meteor->rotation ==2){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1;
                x3 = x1+1;
                x4 = x3+1;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1;
                y3 = y1;
                y4 = y1;
            }
            else if (falling_meteor->rotation ==3){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1;
                x3 = x1;
                x4 = x1+1;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1+1;
                y3 = y2+1;
                y4 = y3;
            }
        printf("%d,%d %d,%d %d,%d %d,%d\n", x1,y1,x2,y2,x3,y3,x4,y4);
        break; 

        case Z :
            printf("on est dans case Z\n");
            if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1+1;
                x3 = x2;
                x4 = x3+1;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1;
                y3 = y1+1;
                y4 = y3;
            }
            else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1;
                x3 = x1+1;
                x4 = x3;
                y1 = falling_meteor->y/taille_carreau+1;
                y2 = y1+1;
                y3 = y1-1;
                y4 = y1;
            }
        printf("%d,%d %d,%d %d,%d %d,%d\n", x1,y1,x2,y2,x3,y3,x4,y4);
        break; 

        case S :
            printf("on est dans case S\n");
            if (falling_meteor->rotation ==0||falling_meteor->rotation ==2){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1+1;
                x3 = x2;
                x4 = x3+1;
                y1 = falling_meteor->y/taille_carreau+1;
                y2 = y1;
                y3 = y2-1;
                y4 = y3;
            }
            else if (falling_meteor->rotation ==1||falling_meteor->rotation ==3){
                x1 = falling_meteor->x/taille_carreau;
                x2 = x1;
                x3 = x2+1;
                x4 = x3;
                y1 = falling_meteor->y/taille_carreau;
                y2 = y1;
                y3 = y2;
                y4 = y3+1;
            }
        printf("%d,%d %d,%d %d,%d %d,%d\n", x1,y1,x2,y2,x3,y3,x4,y4);
        break; 
            }




    ////////////////////////////////////////
    //          test de collision         //
    ////////////////////////////////////////
    if(y1==19||y2==19||y3==19||y4==19||matrice[y1+1][x1]!=0 
    ||matrice[y2+1][x2]!=0||matrice[y3+1][x3]!=0||matrice[y4+1][x4]!=0){
        
        
        //Dans le cas de collision, on arrêt le bloc où il est 
        //et on clorie le fond avec la bonne couleur
        
        switch (falling_meteor->son_nom){
            case I:
            matrice[y1][x1]=1;
            matrice[y2][x2]=1;
            matrice[y3][x3]=1;
            matrice[y4][x4]=1;
            break;

            case O:
            matrice[y1][x1]=2;
            matrice[y2][x2]=2;
            matrice[y3][x3]=2;
            matrice[y4][x4]=2;
            break;
            case T:
            matrice[y1][x1]=3;
            matrice[y2][x2]=3;
            matrice[y3][x3]=3;
            matrice[y4][x4]=3;
            break;
            case L:
            matrice[y1][x1]=4;
            matrice[y2][x2]=4;
            matrice[y3][x3]=4;
            matrice[y4][x4]=4;
            break;
            case J:
            matrice[y1][x1]=5;
            matrice[y2][x2]=5;
            matrice[y3][x3]=5;
            matrice[y4][x4]=5;
            break;
            case Z:
            matrice[y1][x1]=6;
            matrice[y2][x2]=6;
            matrice[y3][x3]=6;
            matrice[y4][x4]=6;
            break;
            case S:
            matrice[y1][x1]=7;
            matrice[y2][x2]=7;
            matrice[y3][x3]=7;
            matrice[y4][x4]=7;
            break;

            }

        //dire qu'il y a eu collision
        return true;
    }
    return false;
}