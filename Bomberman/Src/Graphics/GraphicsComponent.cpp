#include <Bomberman/Src/Graphics/GraphicsComponent.h>

#include <SDL_video.h>

#include <Bomberman/Src/Graphics/GraphicsManager.h>

namespace Bomberman
{
	GraphicsComponent::GraphicsComponent(Sprite* sprite)
		: sprite_(sprite)
	{
	}

	GraphicsComponent::~GraphicsComponent(void)
	{
	}

	void GraphicsComponent::Render(GraphicsManager& graphics, int xPosition, int yPosition)
	{
		graphics.DrawGameObject(sprite_, xPosition, yPosition);
	}
}