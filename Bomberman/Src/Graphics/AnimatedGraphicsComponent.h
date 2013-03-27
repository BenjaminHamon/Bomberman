#pragma once

#include <Bomberman/Src/GameObjects/MoveDirection.h>

namespace Bomberman
{
	class AnimatedSprite;
	class GraphicsManager;

	/// <summary>
	/// Graphics component for an animated object.
	/// </summary>
	class AnimatedGraphicsComponent
	{
	public:
		AnimatedGraphicsComponent(AnimatedSprite* animatedSprite, int animationSpeed);
		virtual ~AnimatedGraphicsComponent(void);

	public:
		virtual void Render(GraphicsManager& graphics, int xPosition, int yPosition);

	protected:
		AnimatedSprite* animatedSprite_;
		/// <summary>
		/// Current time in the animation, between 0 and the product of animationSpeed and the animation length.
		/// </sumary>
		int animationTime_;
		/// <summary>
		/// Factor on the animation time, making it slower or faster.
		/// </sumary>
		int animationSpeed_;
	};
}