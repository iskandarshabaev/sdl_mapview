#include <SDL_image.h>
#include "LTexture.h"

class TTile
{
public:
	//Initializes position and type
	TTile(int x, int y);

	//Deallocates memory
	~TTile();

	//Shows the tile
	void render(SDL_Renderer* gRenderer, SDL_Rect& camera);

	//Get the collision box
	SDL_Rect getBox();

	//Get the collision box
	LTexture* getTileTexture();

	void TTile::setTileTexture(LTexture* tileTexture);

	bool checkCollision(SDL_Rect a, SDL_Rect b);

	void TTile::move(int offsetX, int offsetY);

	void TTile::setXY(int x, int y);

private:

	LTexture* mTileTexture;

	//The attributes of the tile
	SDL_Rect mBox;

	int mTileWidth = 256, mTileHeight = 256;
};

