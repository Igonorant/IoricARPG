#pragma once

#include <iostream>

#include <SDL.h>

#include "texture_codex.h"


class Engine
{
public:
	int Init();
	int Quit();

	unsigned int LoadTexture(const char* path);


	// test functions
	void Display(const char* path);

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	TextureCodex textures;
};