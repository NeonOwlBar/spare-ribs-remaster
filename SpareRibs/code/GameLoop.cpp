#include "GameLoop.h"

GameLoop::GameLoop()
{
    Init();

    // SDL Window flags: https://wiki.libsdl.org/SDL2/SDL_WindowFlags
    appWindow = SDL_CreateWindow(windowTitleDefault,
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                windowWidth, windowHeight,
                                SDL_WINDOW_SHOWN);
    if (appWindow == NULL)
    {
        SDL_LogError(5, "Window failed to initialise. Error: %s", SDL_GetError());
    }
}

void GameLoop::Init()
{
    // Visit this link for flags to use in SDL_Init(): https://wiki.libsdl.org/SDL2/SDL_Init#remarks 

    // Returns a negative error code on failure
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL failed to initialise. Error: %s", SDL_GetError());
    }

    // Calculate window height using width and aspect ratio
    windowHeight = (int)(windowWidth * kAspectRatio);

}

void GameLoop::Quit()
{
    SDL_DestroyWindow(appWindow);
    SDL_Quit();
}