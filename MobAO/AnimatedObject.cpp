#include "AnimatedObject.h"
#include "TextureWrapper.h"
#include <SDL.h>

AnimatedObject::AnimatedObject(void)
{
	frame = 0;
	totalFrames = 0;
	texture = NULL;
}


TextureWrapper*  AnimatedObject::getTexture(){
	return texture;
}

void AnimatedObject::setTexture(TextureWrapper* newTexture){
	texture = newTexture;
}

int AnimatedObject::getTotalFrames(){
	return totalFrames;
}

int AnimatedObject::getCurrentFrame(){
	return frame;
}


void AnimatedObject::setCurrentFrame(int n){
	frame = n;
}

void AnimatedObject::setTotalFrames(int n){
	totalFrames = n;
}

AnimatedObject::~AnimatedObject(void)
{
}
