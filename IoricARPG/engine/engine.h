#pragma once

#include <iostream>
#include <vector>

#include <SDL.h>

#include "texture_codex.h"
#include "../game/object.h"


class Engine
{
public:

	int Init();
	int Quit();

	// loggers
	/**
	* Log an SDL error with some error message to the output stream of our choice
	* @param os The output stream to write the message to
	* @param msg The error message to write, format will be msg error: SDL_GetError()
	*/
	void LogSDLError(std::ostream& os, const char* msg) {
		os << msg << " error: " << SDL_GetError() << std::endl;
	}

	// texture managing
	unsigned int LoadTexture(const char* path);
	void RenderTexture(const unsigned int ID, int x, int y, float scale);

	// rendering managing
	void ClearBackgroundQueue();
	void ClearForegroundQueue();

	void PushForegroundQueue(Object& obj);
	void PushBackgroundQueue(Object& obj);

	// test functions
	void Display();

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	TextureCodex textures;
	std::vector<Object*> background_queue;
	std::vector<Object*> foreground_queue;
};