/*
*Created by Federico Torres
*
*/
#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>


class TextureWrapper
{
public:

	TextureWrapper(SDL_Renderer* renderer);
	~TextureWrapper(void);

	//Loads image at specified path
	bool loadFromFile(std::string path);
	//Releases allocations
	void free();

	//Renders texture at  given point, if SDL_RECT is passed as non null parameter then only renders that rect from texture
	void render(int x, int y, SDL_Rect* clip = NULL);

	int getWidth();
	int getHeight();	
	void clearRender();
	SDL_Renderer* getRenderer();
	void setAsRendertarget();
	SDL_Texture* getTexture();

	bool createBlank(int width, int height, SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);

private:
	//hardware texture
	SDL_Texture* texture;
	SDL_Renderer* renderer;

	int width;
	int height;
	
};

