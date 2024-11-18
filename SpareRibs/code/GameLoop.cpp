#include "GameLoop.h"

int GameLoop::Init()
{
    // Visit this link for flags to use in SDL_Init(): https://wiki.libsdl.org/SDL2/SDL_Init#remarks 

    // Returns a negative error code on failure
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL failed to initialise. Error: %s", SDL_GetError());
        return -1;
    }

    // Calculate window height using width and aspect ratio
    windowHeight = (int)(windowWidth * kAspectRatio);

    // SDL Window flags: https://wiki.libsdl.org/SDL2/SDL_WindowFlags
    appWindow = SDL_CreateWindow(windowTitleDefault,
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                windowWidth, windowHeight,
                                SDL_WINDOW_SHOWN);
    // SDL Renderer flags: https://wiki.libsdl.org/SDL2/SDL_RendererFlags
    // Uses hardware acceleration if available
    appRenderer = SDL_CreateRenderer(appWindow, -1, SDL_RENDERER_ACCELERATED);

    if (appWindow == nullptr)
    {
        SDL_LogError(5, "Window failed to initialise. Error: %s", SDL_GetError());
        return -1;
    }
    SDL_RenderSetVSync(appRenderer, 0);

    // window needs a surface

    return 0;
}

bool GameLoop::IsRunning()
{
    return isGameRunning;
}

void GameLoop::ProcessInput()
{

}

void GameLoop::Update()
{
    if (playerCube.x + (playerCube.w / 2) > windowWidth)
    {
        Quit();
        return;
    }
    //printf("Update() called.\n");
    playerCube.x += 2;
    playerCube.y += 1;
}

void GameLoop::Render(double lerpMultiplier)
{
    //printf("Render() called.\n");
    
    SDL_SetRenderDrawColor(appRenderer, 0, 0, 0, 255);
    // Clear rendering target with draw colour
    SDL_RenderClear(appRenderer);

    SDL_SetRenderDrawColor(appRenderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(appRenderer, &playerCube);

    // Send current render information to renderer
    SDL_RenderPresent(appRenderer);
}

void GameLoop::Quit()
{
    isGameRunning = false;
    SDL_DestroyWindow(appWindow);
    SDL_Quit();
}