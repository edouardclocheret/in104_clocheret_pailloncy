#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "def_types_et_vars.h"
#include "down.h"
#include "entree_clavier.h"
#include "initialisation.h"
#include "rotation.h"
#include "pre_render.h"


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

bool collision(*bloc falling_meteor, int** matrice){
    //traduire le bloc en ses 4 coordonnées des cases occupées
    //arrondies à la case du dessus (si le bloc occupe que la moitié de la case, il n'y a pas encore collision)
    int x1; int y1;
    int x2; int y2;
    int x3; int y3;
    int x4; int y4;

    //test de collision : 
    if(y1==19||y2==19||y3==19||y4=19){
        //modifier en plus la matrice en ajoutant la couleur
        return true;
    }
    else if (matrice[x1][y1+1]!=0 ||matrice[x2][y2+1]!=0||matrice[x3][y3+1]!=0||matrice[x4][y4+1]!=0){
        //modifier en plus la matrice en ajoutant la couleur
        return true;
    }
    else return false;
}

//the falling bloc will be labeled "falling_meteor"

int main(int argc, char *argv[]){
    
    
    printf("runnning\n");

    //Initialisation de SDL
    initialisation();
    printf("initialisation passée\n");
    
    //Création et ouverture de la fenêtre
    printf("01\n");
    SDL_Window *window = NULL;
    printf("02\n");
    //taille de la grille de tetris : 10*20 cases de taille taille_carreau
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 10*taille_carreau, 20*taille_carreau, SDL_WINDOW_SHOWN);
    printf("03\n");
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    printf("04\n");
    //Création du rendu
    SDL_Renderer* pRenderer;
    printf("05\n");
    pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);       
    printf("06\n");
    if (pRenderer == NULL)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return EXIT_FAILURE;     
    }
    printf("07\n");
    
    bloc falling_meteor;
    printf("08\n");
    //tirage au sort du bloc qui va apparaître :
    //int etat_tire = rand() % 7;
    int etat_tire = 1;
    if (etat_tire ==1) {falling_meteor.son_nom = I;
    printf("08.5\n");}
    else if (etat_tire ==2) falling_meteor.son_nom = O;
    else if (etat_tire ==3) falling_meteor.son_nom = T;
    else if (etat_tire ==4) falling_meteor.son_nom = L;
    else if (etat_tire ==5) falling_meteor.son_nom = J;
    else if (etat_tire ==6) falling_meteor.son_nom = Z;
    else if (etat_tire ==7) falling_meteor.son_nom = S;
    printf("09\n");
    falling_meteor.x = taille_carreau*3;
    falling_meteor.y = 0;
    falling_meteor.rotation = 0;
    printf("10\n");
    pre_render(&pRenderer,&falling_meteor);
    printf("11\n");
    SDL_Delay(20000);
    
    //cette matrice représente les blocs déjà tombés
    int** matrice = create_matrix(20,10);
    printf("Bloc en psoition 1,3%d\n", matrice[1][3]);

    //if collision(*bloc falling_meteor, int** matrice);
    
    
    /*On mettra en place la boucle de jeu plus tard
    //début du jeu

    bool quit = false;

    while(!quit) {

        pre_render(arguments);

        //entree_clavier (falling_meteor);

        //updateTetris();

        //update_renderer();

        // Pour jouer à environ 60 fps
        // 1000 ms/ 60 fps = 1/16 s^2/frame
        SDL_Delay(16);
    }
    */


    //SDL_RenderPresent(pRenderer);
    SDL_DestroyWindow(window);

    if(NULL != pRenderer) SDL_DestroyRenderer(pRenderer);
    if(NULL != window) SDL_DestroyWindow(window);

    SDL_Quit();


    // Libération de la mémoire allouée pour la matrice
    for (int i = 0; i < 20; i++) {
        free(matrice[i]);
    }
    free(matrice);

    return EXIT_SUCCESS;
}
