#include "GameLoop.h"

int main(int argc, char* args[])
{
    GameLoop gameLoop = GameLoop();

    SDL_Delay(1500);

    // window needs a surface
    SDL_SetWindowTitle(gameLoop.GetWindow(), "Updated Title!");

    SDL_Delay(1500);

    gameLoop.Quit();

    return 0;
}
