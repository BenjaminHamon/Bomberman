#pragma once

#include <Bomberman/Src/Graphics/AnimatedGraphicsComponent.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AnimatedSprite;
	class AssetManager;
	class GraphicsManager;

	#pragma endregion

	// DEAD CODE

	/// <summary>
	/// Graphics component for an explosion.
	/// </summary>
	class ExplosionGraphicsComponent : public AnimatedGraphicsComponent
	{
	public:
		ExplosionGraphicsComponent(const AssetManager& assets, int animationSpeed, int power);
		virtual ~ExplosionGraphicsComponent(void);

	public:
		virtual void Render(GraphicsManager& graphics, int xPosition, int yPosition);

	private:
		void Render(GraphicsManager& graphics, AnimatedSprite* animation, int xPosition, int yPosition);

	private:
		AnimatedSprite* horizontalAnimation_;
		AnimatedSprite* verticalAnimation_;
		AnimatedSprite* topEndAnimation_;
		AnimatedSprite* rightEndAnimation_;
		AnimatedSprite* bottomEndAnimation_;
		AnimatedSprite* leftEndAnimation_;

		int power_;
	};
}
