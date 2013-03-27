#include <Bomberman/Src/Graphics/Sprite.h>

namespace Bomberman
{
	Sprite::Sprite(SDL_Surface* spriteSheet, int x, int y, int width, int height)
		: SpriteSheet(spriteSheet)
	{
		SpriteBox.x = x;
		SpriteBox.y = y;
		SpriteBox.w = width;
		SpriteBox.h = height;
	}

	Sprite::~Sprite(void)
	{
	}
}