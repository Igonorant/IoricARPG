#include "texture_codex.h"


TextureCodex::TextureCodex()
{
	// Initialize the first element of the texture vector
	SDL_Texture* tmpTex = NULL;
	textures.emplace_back(0, "", tmpTex);
}

TextureCodex::~TextureCodex()
{
	// Destroy all textures
	for (auto it = textures.begin();
		it != textures.end();
		it++)
	{
		SDL_DestroyTexture((*it).texture);
	}
}

unsigned int TextureCodex::LoadTexture(const char* path)
{
	unsigned int tmpID = GetID(path);

	// If texture was not loaded already, load texture and return ID
	if (tmpID)
	{
		return tmpID;
	}
	else
	{
		tmpSurface = IMG_Load(path);
		if (tmpSurface != NULL)
		{
			tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
			if (tmpTexture != NULL)
			{
				lastID++;
				textures.emplace_back(lastID, path, tmpTexture);

				SDL_Log("Texture %s loaded!", path);

				tmpTexture = NULL;
				SDL_FreeSurface(tmpSurface);
				tmpSurface = NULL;
				return lastID;

			}
			SDL_FreeSurface(tmpSurface);
			tmpSurface = NULL;
		}
	}

	// Return ID 0 (NULL texture) if everything goes wrong
	return 0;
}

unsigned int TextureCodex::GetID(const char* path)
{
	// Find ID corresponding to the given path
	for (auto it = textures.begin();
		it != textures.end();
		it++)
	{
		if (!strcmp(path, (*it).path))
		{
			// If texture is already loaded, return  current ID
			return (*it).ID;
		}
	}

	// Return ID 0 (NULL texture) if everything goes wrong
	return 0;
}

SDL_Texture* TextureCodex::GetTexture(const unsigned int ID)
{
	if (ID <= lastID)
	{
		return textures[ID].texture;
	}

	return NULL;

}

SDL_Texture* TextureCodex::GetTexture(const char* path)
{
	return textures[GetID(path)].texture;
}

void TextureCodex::SetRenderer(SDL_Renderer* rend)
{
	renderer = rend;
}