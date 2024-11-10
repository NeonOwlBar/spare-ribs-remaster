#pragma once
#include "CommonIncludes.h"

class GameLoop
{
public:

	GameLoop();
	void Init();

	void Quit();

	SDL_Window* GetWindow()
	{
		return appWindow;
	}

private:
	// WINDOW DETAILS

	const char* windowTitleDefault = "Spare Ribs";
	SDL_Window* appWindow;
	// 16:9 aspect ratio
	float kAspectRatio = 9.0/16.0;
	int windowWidth = 600;
	int windowHeight = {0};
};
