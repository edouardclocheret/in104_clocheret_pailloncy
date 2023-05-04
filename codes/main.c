#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "all_def_functions.h"


//the falling bloc will be labeled "falling_meteor"

int main(int argc, char *argv[]){
    
    
    printf("running\n");

    //Initialisation de SDL
    initialisation();
    
    //Création et ouverture de la fenêtre
    
    SDL_Window *window = NULL, *window2 = NULL;
    
    //taille de la grille de tetris : 10*20 cases de taille taille_carreau
    window = SDL_CreateWindow("SDL2", 100, 100, 10*taille_carreau, 20*taille_carreau, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    //Création du rendu
    SDL_Renderer* pRenderer;
    pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);       
    if (pRenderer == NULL)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return EXIT_FAILURE;     
    }
    
    bloc* falling_meteor;
    //tirage au sort du bloc qui va apparaître :
    //int etat_tire = rand() % 7;
    int etat_tire = 1;
    if (etat_tire ==1) falling_meteor->son_nom = I;
    else if (etat_tire ==2) falling_meteor->son_nom = O;
    else if (etat_tire ==3) falling_meteor->son_nom = T;
    else if (etat_tire ==4) falling_meteor->son_nom = L;
    else if (etat_tire ==5) falling_meteor->son_nom = J;
    else if (etat_tire ==6) falling_meteor->son_nom = Z;
    else if (etat_tire ==7) falling_meteor->son_nom = S;
    
    falling_meteor->x = taille_carreau*2;
    falling_meteor->x = taille_carreau*5;
    falling_meteor->rotation = 0;
    //début du jeu

    bool quit = false;
    while(!quit) {

        pre_render(pRenderer);

        entree_clavier (falling_meteor);

        //updateTetris();

        //update_renderer();

        // Pour jouer à environ 60 fps
        // 1000 ms/ 60 fps = 1/16 s^2/frame
        SDL_Delay(16);
    }


    SDL_RenderPresent(pRenderer);
    SDL_DestroyWindow(window);

    if(NULL != pRenderer) SDL_DestroyRenderer(pRenderer);
    if(NULL != window) SDL_DestroyWindow(window);

    SDL_Quit();

    return EXIT_SUCCESS;
}
