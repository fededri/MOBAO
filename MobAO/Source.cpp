#include <stdio.h>
#include <SDL.h>
#include "TextureWrapper.h"
#include "AnimatedBody.h"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


bool initSDL();
bool loadMedia();
void close();

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
bool quit = false;
SDL_Rect spriteClips[22];
TextureWrapper* textureWrapper;


bool initSDL(){
	bool success = true;

		if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL no se pudo incializar: SDL_ERROR %s\n", SDL_GetError());		
		success = false;
		}else {
			if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1")){
				printf("Linear texture filtering no establecido");
			}
		
			window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);
			if (window == NULL){
				printf("No se pudo crear la ventana %s\n",SDL_GetError);
				success = false;
			}else {				
				renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);			
				

			}
		}
		return success;
}

int main( int argc, char* args[] )
{
	
	if(!initSDL()){
	printf("inicializacion fallida de SDL");
	}else {
		textureWrapper = new TextureWrapper(renderer);
		loadMedia();
		textureWrapper->render(100,100,&spriteClips[3]);
		SDL_RenderPresent(renderer);
	}

	//creates AnimatedBody of user
	AnimatedBody animatedBody;
	animatedBody.setTotalFrames(20);
	animatedBody.setTexture(textureWrapper);
	animatedBody.setSpriteClips(spriteClips,20);

	SDL_Event e;
	while(!quit){
	while(SDL_PollEvent(&e)){
		if(e.key.keysym.scancode == SDL_SCANCODE_Q) {
			quit = true;
		}else if(e.key.keysym.scancode == SDL_SCANCODE_W){
			//move up
			animatedBody.moveUp();
		}
	}
	}


	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}

bool loadMedia(){
	bool success = true;
	if(!textureWrapper->loadFromFile("11.BMP")){
		printf("Texture Wrapper: Fallo la carga de la imagen");
		success = false;
	}else {
		//first row
		spriteClips[0].x = 0;
		spriteClips[0].y = 0;
		spriteClips[0].w = 25;
		spriteClips[0].h = 45;

		spriteClips[1].x = 25;
		spriteClips[1].y = 0;
		spriteClips[1].w = 25;
		spriteClips[1].h = 45;

		spriteClips[2].x = 50;
		spriteClips[2].y = 0;
		spriteClips[2].w = 25;
		spriteClips[2].h = 45;

		spriteClips[3].x = 75;
		spriteClips[3].y = 0;
		spriteClips[3].w = 25;
		spriteClips[3].h = 45;

		spriteClips[4].x = 100;
		spriteClips[4].y = 0;
		spriteClips[4].w = 25;
		spriteClips[4].h = 45;


		spriteClips[5].x = 125;
		spriteClips[5].y = 0;
		spriteClips[5].w = 25;
		spriteClips[5].h = 45;


		//second row
		spriteClips[6].x = 0;
		spriteClips[6].y = 25;
		spriteClips[6].w = 25;
		spriteClips[6].h = 45;

		spriteClips[7].x = 25;
		spriteClips[7].y = 25;
		spriteClips[7].w = 25;
		spriteClips[7].h = 45;

		spriteClips[8].x = 50;
		spriteClips[8].y = 25;
		spriteClips[8].w = 25;
		spriteClips[8].h = 45;

		spriteClips[9].x = 75;
		spriteClips[9].y = 25;
		spriteClips[9].w = 25;
		spriteClips[9].h = 45;

		spriteClips[9].x = 100;
		spriteClips[9].y = 25;
		spriteClips[9].w = 25;
		spriteClips[9].h = 45;

		spriteClips[10].x = 125;
		spriteClips[10].y = 25;
		spriteClips[10].w = 25;
		spriteClips[10].h = 45;

		//third row, has five items
		spriteClips[11].x = 0;
		spriteClips[11].y = 50;
		spriteClips[11].w = 25;
		spriteClips[11].h = 45;

		spriteClips[12].x = 25;
		spriteClips[12].y = 50;
		spriteClips[12].w = 25;
		spriteClips[12].h = 45;

		spriteClips[13].x = 50;
		spriteClips[13].y = 50;
		spriteClips[13].w = 25;
		spriteClips[13].h = 45;


		spriteClips[14].x = 75;
		spriteClips[14].y = 50;
		spriteClips[14].w = 25;
		spriteClips[14].h = 45;


		spriteClips[15].x = 100;
		spriteClips[15].y = 50;
		spriteClips[15].w = 25;
		spriteClips[15].h = 45;


		//fourth row
		spriteClips[16].x = 0;
		spriteClips[16].y = 75;
		spriteClips[16].w = 25;
		spriteClips[16].h = 45;

		spriteClips[17].x = 25;
		spriteClips[17].y = 75;
		spriteClips[17].w = 25;
		spriteClips[17].h = 45;


		spriteClips[18].x = 50;
		spriteClips[18].y = 75;
		spriteClips[18].w = 25;
		spriteClips[18].h = 45;


		spriteClips[19].x = 75;
		spriteClips[19].y = 75;
		spriteClips[19].w = 25;
		spriteClips[19].h = 45;


		spriteClips[20].x = 100;
		spriteClips[20].y = 75;
		spriteClips[20].w = 25;
		spriteClips[20].h = 45;




	}

	return success;

}