//C libraries
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//all types and global constants
#ifndef TYPES_ET_VARS 
#define TYPES_ET_VARS
#include "def_types_et_vars.h"
#endif

//all functions
#include "entree_clavier.h"
#include "initialisation.h"
#include "rotation.h"
#include "pre_render.h"
#include "collision.h"




//the falling bloc will be labeled "falling_meteor"
bool game_over(int ** matrice){
        if ((matrice[3][0]!=0)||(matrice[3][1]!=0)||(matrice[3][2]!=0)||(matrice[3][3]!=0)||(matrice[3][4]!=0)
        ||(matrice[3][5]!=0)||(matrice[3][6]!=0)||(matrice[3][7]!=0)||(matrice[3][8]!=0)||(matrice[3][9]!=0)){
            return true;
        }
        return false;
}

void test_ligne_complete(int ** matrice){
    for(int i=19;i>3;i-=1){
        if(matrice[i][0]!=0 && matrice[i][1]!=0 && matrice[i][2]!=0 && matrice[i][3]!=0
        && matrice[i][4]!=0 && matrice[i][5]!=0 && matrice[i][6]!=0 && matrice[i][7]!=0 && matrice[i][8]!=0 && matrice[i][9]!=0){
            for(int j=i;j>=3;j-=1){
                for (int k =0; k<10; k+=1){
                    matrice[j][k]=matrice[j-1][k];}
                
            }
        }
    }
}


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
    

    //cette matrice représente les blocs déjà tombés
    int** matrice = create_matrix(20,10);
    bloc falling_meteor;
    SDL_bool quit = SDL_FALSE;
    SDL_Event event;
    srand(time(NULL)); //pour que le tirage soit vraiment aléatoire


    while((!quit) && (!game_over(matrice))){
        
        //tirage d'un bloc
        //tirage au sort du bloc qui va apparaître :
        int etat_tire = rand() % 7 + 1;
        //int etat_tire = 1;
        if (etat_tire ==1) falling_meteor.son_nom = I;
        else if (etat_tire ==2) falling_meteor.son_nom = O;
        else if (etat_tire ==3) falling_meteor.son_nom = T;
        else if (etat_tire ==4) falling_meteor.son_nom = L;
        else if (etat_tire ==5) falling_meteor.son_nom = J;
        else if (etat_tire ==6) falling_meteor.son_nom = Z;
        else if (etat_tire ==7) falling_meteor.son_nom = S;
        
        falling_meteor.x = taille_carreau*3;
        falling_meteor.y = 0;
        falling_meteor.rotation = 0;
        pre_render(&pRenderer,&falling_meteor, matrice);
        SDL_Delay(500);

        //on utilise ce bloc jusqu'à ce qu'il touche le sol
        while((!quit) &&(collision(&falling_meteor, matrice)==0 )&& (!game_over(matrice))){
            printf("boucle\n");

            //faire descendre le bloc
            falling_meteor.y=falling_meteor.y+going_down;

            //Mettre à jour l'affichage
            pre_render(&pRenderer,&falling_meteor, matrice);
            
            //Mettre à jour le jeu selon le joueur
            entree_clavier (&falling_meteor, &event, &quit, matrice);
            test_ligne_complete(matrice);
            SDL_Delay(16);          

            printf("position du bloc : %d , %d\n",falling_meteor.x, falling_meteor.y);
        }
    }
    
    

    SDL_Delay(1000);
    printf("11\n");
    

    if(NULL != pRenderer) SDL_DestroyRenderer(pRenderer);
    if(NULL != window) SDL_DestroyWindow(window);


    SDL_Quit();


    return EXIT_SUCCESS;
}
