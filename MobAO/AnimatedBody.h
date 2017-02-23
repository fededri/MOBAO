#pragma once
#include "AnimatedObject.h"
#include <vector>
using namespace std;

class AnimatedBody : public AnimatedObject
{
public:
	AnimatedBody();
	~AnimatedBody(void);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	vector<SDL_Rect> clips;

	void setSpriteClips(SDL_Rect a[],int arrayLenght);
};

