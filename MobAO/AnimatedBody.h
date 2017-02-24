#pragma once
#include "AnimatedObject.h"
#include <vector>
using namespace std;

class AnimatedBody : public AnimatedObject
{
public:
	AnimatedBody();
	~AnimatedBody(void);

	static const int VELOCITY = 3;
	static const int WIDTH = 25;
	static const int HEIGHT = 45;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void handleEvent(SDL_Event& event);

	vector<SDL_Rect> clips;

	void setSpriteClips(SDL_Rect a[],int arrayLenght);

private:
	int posX, posY;
	int velX, velY;
};

