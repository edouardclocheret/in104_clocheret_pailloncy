//C libraries
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//all types and global constants
#ifndef TYPES_ET_VARS 
#define TYPES_ET_VARS
#include "def_types_et_vars.h"
#endif

//all functions
#include "down.h"
#include "entree_clavier.h"
#include "initialisation.h"
#include "rotation.h"
#include "pre_render.h"
#include "collision.h"




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
    bool quit = false;
    SDL_Event event;
    printf("08\n");
    
    
    printf("10\n");
    printf("position du bloc : %d , %d\n",falling_meteor.x, falling_meteor.y);
    //cette matrice représente les blocs déjà tombés
    int** matrice = create_matrix(20,10);
    
    //pour le test de collision !
    matrice [17][3] = 5;
    matrice [17][5] = 6;
    matrice [17][6] = 3;

    bool game_over(int ** matice){
        if ((matrice[3][0]!=0)||(matrice[3][1]!=0)||(matrice[3][2]!=0)||(matrice[3][3]!=0)||(matrice[3][4]!=0)
        ||(matrice[3][5]!=0)||(matrice[3][6]!=0)||(matrice[3][7]!=0)||(matrice[3][8]!=0)||(matrice[3][9]!=0)){
            return true;
        }
        return false;
    }

    while((!quit) && (!game_over(matrice))){
        
        //tirage d'un bloc
        //tirage au sort du bloc qui va apparaître :
        int etat_tire = rand() % 7;
        //int etat_tire = 1;
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
        pre_render(&pRenderer,&falling_meteor, matrice);
        SDL_Delay(500);

        //on utilise ce bloc jusqu'à ce qu'il touche le sol
        while((collision(&falling_meteor, matrice)==0 )&& (!game_over(matrice))){
            printf("boucle\n");

            //faire descendre le bloc
            falling_meteor.y=falling_meteor.y+going_down;

            //Mettre à jour l'affichage
            pre_render(&pRenderer,&falling_meteor, matrice);
            
            //Mettre à jour le jeu selon le joueur
            entree_clavier (&falling_meteor, &event);          
            SDL_Delay(16);

            printf("position du bloc : %d , %d\n",falling_meteor.x, falling_meteor.y);
        }
    }
    
    

    SDL_Delay(1000);
    printf("11\n");
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

    if(NULL != pRenderer) SDL_DestroyRenderer(pRenderer);
    if(NULL != window) SDL_DestroyWindow(window);

    SDL_Quit();


    // Libération de la mémoire allouée pour la matrice
    /*for (int i = 0; i < ?; i++) {
        free(matrice[i]);
    }
    free(matrice);*/

    return EXIT_SUCCESS;
}
