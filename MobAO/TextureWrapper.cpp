#include "TextureWrapper.h"
/*
Created by Federico Torres
This class is a texture representing an entire file image, if the file has multiple sprites, it contains all of them
*/
TextureWrapper::TextureWrapper(SDL_Renderer* r){
	renderer = r;	
	texture = NULL;
	width = 0;
	height = 0;
}

bool TextureWrapper::createBlank(int w, int h, SDL_TextureAccess  access) {
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, access, w, h);
	if (texture == NULL) {
		printf("No se pudo crear textura en blanco");
	}
	else {
		width = w;
		height = h;
	}
	
	return texture != NULL;

}

void TextureWrapper::setAsRendertarget() {
	SDL_SetRenderTarget(renderer, texture);
}


SDL_Texture* TextureWrapper::getTexture() {
	return texture;
}

void TextureWrapper::render(int x, int y, SDL_Rect* clip){

	//sets the rect space to draw texture
	SDL_Rect rect = {x,y,width,height};
	
	if(clip != NULL){
		rect.w = clip->w;
		rect.h = clip->h;
	}

	//if clip is null, all texture is rendered
	SDL_RenderCopy(renderer, texture, clip, &rect);

}

SDL_Renderer* TextureWrapper::getRenderer(){
	return renderer;
}

bool TextureWrapper::loadFromFile(std::string path){
	free(); //releases previous textures loaded
	
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL){
		printf("No se pudo cargar la imagen %s!",path.c_str(),IMG_GetError());
		return false;
	}else {
		SDL_SetColorKey(loadedSurface,SDL_TRUE, SDL_MapRGB(loadedSurface->format,0x00,0x00,0x00));
		newTexture= SDL_CreateTextureFromSurface(renderer,loadedSurface);
		if(newTexture == NULL) printf("No se pudo crear la textura %s",path.c_str());
		else {
			width = loadedSurface->w;
			height = loadedSurface->h;
			texture = newTexture;
		}
	
		SDL_FreeSurface(loadedSurface);
	}
	return texture != NULL;
}


void TextureWrapper::clearRender(){
	SDL_RenderClear(renderer);
}

void TextureWrapper::free()
{
	if(texture != NULL){
		SDL_DestroyTexture(texture);
		texture  = NULL;
		width = 0;
		height = 0;
	}

}

TextureWrapper::~TextureWrapper(void)
{
	free();
}


int TextureWrapper::getHeight(){
	return height;
}


int TextureWrapper::getWidth(){
	return width;
}