#pragma once
#include <SDL.h>
#include "TextureWrapper.h"
class AnimatedObject
{
public:
	AnimatedObject(void);
	~AnimatedObject(void);


	//returns number of the current frame
	int getCurrentFrame();

	//return the amount of frames composing the animation
	int getTotalFrames();

	void setCurrentFrame(int frameNumber);
	void setTotalFrames(int amount);

	TextureWrapper* getTexture();
	void setTexture(TextureWrapper*);

private:
	TextureWrapper* texture;
	int frame;
	int totalFrames;


};

