#include "AnimatedBody.h"


AnimatedBody::AnimatedBody(void)
{
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

	void AnimatedBody::moveUp(){
		SDL_Rect nextClip = clips[getCurrentFrame()/5];
	
		getTexture()->render(100,100,&nextClip);
		SDL_RenderPresent(getTexture()->getRenderer());
		setCurrentFrame(getCurrentFrame()+1);
		if(getCurrentFrame() / 5 >= 5) setCurrentFrame(0);
	
	}


	void  AnimatedBody::moveDown(){
		
	}


	void  AnimatedBody::moveLeft(){

	}


	void  AnimatedBody::moveRight(){

	}