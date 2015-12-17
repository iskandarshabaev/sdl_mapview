#include <SDL_image.h>
#include "LTexture.h"

class Dot
{
public:
	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Initializes the variables
	Dot();

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot and check collision against tiles
	void move();

	//Centers the camera over the dot
	void setCamera(SDL_Rect& camera);

	//Shows the dot on the screen
	void render(SDL_Renderer* gRenderer, SDL_Rect& camera);

	SDL_Rect Dot::getBox();

	LTexture* Dot::getDotTexture();

	void Dot::setDotTexture(LTexture* dotTexture);

private:
	LTexture* mDotTexture;

	//Collision box of the dot
	SDL_Rect mBox;

	//The velocity of the dot
	int mVelX, mVelY;

	int mScreenWidth = 640, mScreenHeight = 480;
};
