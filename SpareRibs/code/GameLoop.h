#pragma once
#include "CommonIncludes.h"
#include <utility>

class GameLoop
{
public:

    GameLoop() {}
    ~GameLoop() { Quit(); }
    int Init();

    bool IsRunning();

    // Get user input
    void ProcessInput();
    // Game logic (AI, physics, etc.)
    void Update();
    // Render game to screen
    void Render(double lerpMultiplier);

    void Quit();

    SDL_Window* GetWindow()
    {
        return appWindow;
    }

private:
    /* ____WINDOW____ */
    // Window title set at initialisation
    const char* windowTitleDefault = "Spare Ribs";
    SDL_Window* appWindow{};
    SDL_Renderer* appRenderer{};
    // 16:9 aspect ratio
    float kAspectRatio = 9.0/16.0;
    int windowWidth = 800;
    int windowHeight = {0};

    /* ____GAME____ */
    // Game state
    bool isGameRunning = true;



    /* ____TESTING____ */
    
    SDL_Rect playerCube{ 0, 0, 50, 50 };
};
