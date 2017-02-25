#include "AnimatedBody.h"
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

AnimatedBody::AnimatedBody(void)
{
	posX = 100;
	posY = 100;
	velX = 0;
	velY = 0;
}


AnimatedBody::~AnimatedBody(void)
{
}

void AnimatedBody::setSpriteClips(SDL_Rect a[], int arrayLenght){
	clips.clear();
	for(int i =0; i<arrayLenght;i++){
		clips.push_back(a[i]);
	}
}


void AnimatedBody::renderOnCurrentPosition() {
	getTexture()->render(posX, posY, &clips[getCurrentFrame()]);
}


void AnimatedBody::handleEvent(SDL_Event& event)  {
	if (event.type == SDL_KEYDOWN) {
		//key pressed
		switch (event.key.keysym.sym)
		{
		case SDLK_w: {
			if (velY > 0) velY = 0;
			velY = -VELOCITY;
			moveUp();
			break;
		}
		case SDLK_s: {
			if (velY < 0) velY = 0;
			velY = VELOCITY;
			moveDown();
			break;
		}
		case SDLK_a: {
			if (velX > 0) velX = 0;
			velX = -VELOCITY;
			moveLeft();
			break;
		}
		case SDLK_d: {
			if (velX < 0) velX = 0;
			velX = VELOCITY;
			moveRight();
			break;
		}
		default:
			break;
		}
	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym)
		{
		case SDLK_w: velY += VELOCITY;
		case SDLK_s: velY -= VELOCITY;
		case SDLK_a: velX += VELOCITY;
		case SDLK_d: velX -= VELOCITY;
		default:
			break;
		}
		renderOnCurrentPosition();
	}
}

	void AnimatedBody::moveUp(){
		//frame 6 to 10
		int frame = getCurrentFrame();
		if (frame < 6 || frame > 10) {
			frame = 6;
			setCurrentFrame(frame);
		}
		SDL_Rect nextClip = clips[frame];
		frame++;
		setCurrentFrame(frame);
		if(frame / 6 >= 6) setCurrentFrame(6);

		posY += velY;
		if ((posY < 0) || (posY + HEIGHT) > SCREEN_HEIGHT) {
			posY -= velY;
		}

		getTexture()->render(posX, posY, &nextClip);
	
	}


	void  AnimatedBody::moveDown(){
		//0-5
		int frame = getCurrentFrame();
		if (frame < 0 || frame > 5) {
			frame = 0;
			setCurrentFrame(frame);
		}
		else  {
			frame++;
		}
		SDL_Rect nextClip = clips[frame];
		setCurrentFrame(frame);
		if (frame / 6 >= 6) setCurrentFrame(0);

		posY += velY;
		if ((posY < 0) || (posY + HEIGHT) > SCREEN_HEIGHT) {
			posY -= velY;
		}

		getTexture()->render(posX, posY, &nextClip);
	}


	void  AnimatedBody::moveLeft(){
		//11-15
		int frame = getCurrentFrame();
		if (frame < 12 || frame > 15) {
			frame = 12;
		}
		else {
			frame++;
		}
		setCurrentFrame(frame);
		SDL_Rect nextClip = clips[frame];
		
		if (frame / 5 >= 5) setCurrentFrame(5);

		posX += velX;
		if ((posX < 0) || (posX + WIDTH) > SCREEN_WIDTH) {
			posX -= velX;
		}

		getTexture()->render(posX, posY, &nextClip);
	}


	void  AnimatedBody::moveRight(){
		//16-20
		int frame = getCurrentFrame();
		if (frame < 16 || frame > 20) {
			frame = 16;			
		}
		else {
			frame++;
			if (frame >= 20) frame = 16; //avoid runtime exception for invalid index accessing clips
		}
		setCurrentFrame(frame);
		SDL_Rect nextClip = clips[frame];

		if (frame / 5 >= 5) setCurrentFrame(5);

		posX += velX;
		if ((posX < 0) || (posX + WIDTH) > SCREEN_WIDTH) {
			posX -= velX;
		}

		getTexture()->render(posX, posY, &nextClip);
	}