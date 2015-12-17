#include "Dot.h"
#include "LTexture.h"

Dot::Dot()
{
	//Initialize the collision box
	mBox.x = 0;
	mBox.y = 0;
	mBox.w = DOT_WIDTH;
	mBox.h = DOT_HEIGHT;

	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;
}

void Dot::handleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY -= DOT_VEL; break;
		case SDLK_DOWN: mVelY += DOT_VEL; break;
		case SDLK_LEFT: mVelX -= DOT_VEL; break;
		case SDLK_RIGHT: mVelX += DOT_VEL; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += DOT_VEL; break;
		case SDLK_DOWN: mVelY -= DOT_VEL; break;
		case SDLK_LEFT: mVelX += DOT_VEL; break;
		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		}
	}
}

void Dot::move()
{
	//Move the dot left or right
	mBox.x += mVelX;

	//Move the dot up or down
	mBox.y += mVelY;
}

void Dot::setCamera(SDL_Rect& camera)
{
	//Center the camera over the dot
	//camera.x = (mBox.x + DOT_WIDTH / 2) - mScreenWidth / 2;
	//camera.y = (mBox.y + DOT_HEIGHT / 2) - mScreenHeight / 2;
}

void Dot::render(SDL_Renderer* gRenderer, SDL_Rect& camera)
{
	//Show the dot
	mDotTexture -> render(gRenderer, mBox.x - camera.x, mBox.y - camera.y);
}

SDL_Rect Dot::getBox()
{
	return mBox;
}

LTexture* Dot::getDotTexture()
{
	return mDotTexture;
}

void Dot::setDotTexture(LTexture* dotTexture) {
	mDotTexture = dotTexture;
}