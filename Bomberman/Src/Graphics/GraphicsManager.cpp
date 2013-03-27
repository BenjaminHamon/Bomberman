#include <Bomberman/Src/Graphics/GraphicsManager.h>

#include <SDL_image.h>

#include <Bomberman/Src/AppException.h>
#include <Bomberman/Src/GameObjects/Map.h>
#include <Bomberman/Src/Graphics/Sprite.h>

namespace Bomberman
{

	GraphicsManager::GraphicsManager(void)
		: assets_(),
		  display_(nullptr)
	{
	}

	GraphicsManager::~GraphicsManager(void)
	{
	}

	void GraphicsManager::Initialize(void)
	{
		// Display initialization.
		// SDL_HWSURFACE: Creates the video surface in video memory (SDL_SWSURFACE for system memory)
		// SDL_DOUBLEBUF: Uses double buffering. Operations are performed on a back buffer which will be flipped with the displayed buffer.
		display_ = SDL_SetVideoMode(1024, 768, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);

		if (display_ == nullptr)
		{
			throw AppException(SDL_GetError());
		}

		assets_.LoadImages();

		SDL_WM_SetCaption("Bomberman", nullptr);
	}

	void GraphicsManager::Finalize(void)
	{
		display_ = nullptr;
		assets_.UnloadImages();
	}

	void GraphicsManager::BeginRender(void)
	{
		SDL_BlitSurface(assets_.GetGameBackground(), nullptr, display_, nullptr);
	}

	void GraphicsManager::EndRender(void)
	{
		SDL_Flip(display_);
	}
	
	void GraphicsManager::Draw(SDL_Surface& sourceSurface, SDL_Rect& sourceRectangle, SDL_Rect& destinationRectangle)
	{
		SDL_BlitSurface(&sourceSurface, &sourceRectangle, display_, &destinationRectangle);
	}

	void GraphicsManager::Draw(Sprite* sprite, int x, int y)
	{
		SDL_Rect destination;
		destination.x = x;
		destination.y = y;
		SDL_BlitSurface(sprite->SpriteSheet, &(sprite->SpriteBox), display_, &destination);
	}

	void GraphicsManager::DrawGameObject(Sprite* sprite, int x, int y)
	{
		Draw(sprite, x + GameAreaX, y + GameAreaY);
	}
}