#pragma once

#include <SDL_video.h>

namespace Bomberman
{
	/// <summary>
	/// Graphic element for the graphics components.
	/// Holds a pointer to a sprite sheet and a rectangle surrounding the actual sprite in the sheet.
	/// </summary>
	class Sprite
	{
	public:
		Sprite(SDL_Surface* spriteSheet, int x, int y, int width, int height);
		~Sprite(void);

	public:
		/// <summary>
		/// Pointer to the sprite sheet containing the sprite.
		/// The pointer is owned by the AssetManager and should not be freed by the Sprite.
		/// </summary>
		SDL_Surface* const SpriteSheet;
		/// <sumary>
		/// Source rectangle to get the actual sprite from the sprite sheet.
		/// </summary>
		SDL_Rect SpriteBox;
	};
}
