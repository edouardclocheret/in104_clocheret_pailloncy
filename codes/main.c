#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "all_def_functions.h"


int main(int argc, char *argv[]){
    
    
    printf("running\n");

    //Initialisation de SDL
    initialisation();
    
    //Création et ouverture de la fenêtre
    
    SDL_Window *window = NULL, *window2 = NULL;
    
    window = SDL_CreateWindow("SDL2", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
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
    
    //début du jeu

    bool quit = false;
    while(!quit) {

        //preRender();

        entree_clavier();

        //updateTetris();

        //updateRender();

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
