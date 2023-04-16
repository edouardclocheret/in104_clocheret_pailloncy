#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    
    printf("running\n");

    //Initialisation de SDL
    
    if(SDL_Init(SDL_INIT_VIDEO) <0)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
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
    pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);       
    if (pRenderer == NULL)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return EXIT_FAILURE;     
    }

    SDL_Delay(3000);
    SDL_DestroyWindow(window);

    if(NULL != pRenderer) SDL_DestroyRenderer(pRenderer);
    if(NULL != window) SDL_DestroyWindow(window);
    SDL_Quit();
    
    SDL_Quit();

    return EXIT_SUCCESS;
}
