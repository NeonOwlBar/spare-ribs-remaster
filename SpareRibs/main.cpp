#include <stdio.h>
#include <SDL.h>
#include <iostream>

int main(int argc, char* args[])
{
	// Visit this link for flags to use in SDL_Init(): https://wiki.libsdl.org/SDL2/SDL_Init#remarks 

	// returns a negative error code on failure
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL failed to initialise. Error: %s", SDL_GetError());
	}

	printf("ooga booga\n");
	return 0;
}
