#include "GameLoop.h"
#include <chrono>   // for hi res clock

int main(int argc, char* argv[])
{
    // Calls for physics updates x times per second
    const double MS_PER_UPDATE = 1000.0/60.0;

    GameLoop gameLoop = GameLoop();

    if (gameLoop.Init() != 0)
    {
        printf("Game loop failed to initialise");
        return -1;
    }

    std::chrono::high_resolution_clock::time_point previousFrameTime = 
        std::chrono::high_resolution_clock::now();
    // Time difference between game logic and rendering
    // (how much the logic is lagging behind)
    double lag = 0.0;

    std::chrono::high_resolution_clock::time_point initialFrameTime = 
        std::chrono::high_resolution_clock::now();

    while (gameLoop.IsRunning())
    {
        // Used for testing logic's framerate independence
        SDL_Delay(64);

        std::chrono::high_resolution_clock::time_point currentFrameTime =
            std::chrono::high_resolution_clock::now();
        // Time taken to complete previous frame
        std::chrono::duration<double> elapsed =
            std::chrono::duration_cast<std::chrono::duration<double>>(currentFrameTime - previousFrameTime);

        // Update for use in next frame
        previousFrameTime = currentFrameTime;
        // update lag with time since last frame
        lag += elapsed.count() * 1000;
        printf(" %fms\n", elapsed.count() * 1000);

        gameLoop.ProcessInput();

        // if game logic is (over)due an update
        while (lag >= MS_PER_UPDATE)
        {
            gameLoop.Update();
            // Check 
            lag -= MS_PER_UPDATE;
        }

        gameLoop.Render(lag/MS_PER_UPDATE);
    }

    // Calculate total time from start to finish of game loop. Used to test logic's framerate independence
    std::chrono::high_resolution_clock::time_point finalFrameTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalFramesDuration = std::chrono::duration_cast<std::chrono::duration<double>>(finalFrameTime - initialFrameTime);
    printf("Time elapsed: %f seconds", totalFramesDuration.count());

    gameLoop.Quit();

    return 0;
}
