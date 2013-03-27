#include <Bomberman/Src/Graphics/ExplosionGraphicsComponent.h>

#include <Bomberman/Src/Graphics/AnimatedSprite.h>
#include <Bomberman/Src/Graphics/AssetManager.h>
#include <Bomberman/Src/Graphics/GraphicsManager.h>

namespace Bomberman
{
	// DEAD CODE

	ExplosionGraphicsComponent::ExplosionGraphicsComponent(const AssetManager& assets, int animationSpeed, int power)
		: AnimatedGraphicsComponent(assets.GetExplosionCenter(), animationSpeed),
		  horizontalAnimation_(assets.GetExplosionHorizontal()),
		  verticalAnimation_(assets.GetExplosionVertical()),
		  topEndAnimation_(assets.GetExplosionTopEnd()),
		  rightEndAnimation_(assets.GetExplosionRightEnd()),
		  bottomEndAnimation_(assets.GetExplosionBottomEnd()),
		  leftEndAnimation_(assets.GetExplosionLeftEnd()),
		  power_(power)
	{
	}

	ExplosionGraphicsComponent::~ExplosionGraphicsComponent(void)
	{
	}

	void ExplosionGraphicsComponent::Render(GraphicsManager& graphics, int xPosition, int yPosition)
	{
		animationTime_ = (animationTime_ + 1) % (animatedSprite_->GetAnimationLength() * animationSpeed_);

		Render(graphics, animatedSprite_, xPosition, yPosition);

		for (int i = 1; i < power_; ++i)
		{
			Render(graphics, verticalAnimation_, xPosition, yPosition - 48 * i); // Top
			Render(graphics, horizontalAnimation_, xPosition + 48 * i, yPosition); // Right
			Render(graphics, verticalAnimation_, xPosition, yPosition + 48 * i); // Bottom
			Render(graphics, horizontalAnimation_, xPosition - 48 * i, yPosition); // Left
		}

		Render(graphics, topEndAnimation_, xPosition, yPosition - 48 * power_);
		Render(graphics, rightEndAnimation_, xPosition + 48 * power_, yPosition);
		Render(graphics, bottomEndAnimation_, xPosition, yPosition + 48 * power_);
		Render(graphics, leftEndAnimation_, xPosition - 48 * power_, yPosition);

	}

	void ExplosionGraphicsComponent::Render(GraphicsManager& graphics, AnimatedSprite* animation, int xPosition, int yPosition)
	{
		graphics.DrawGameObject(animation->GetSprite(animationTime_ / animationSpeed_), xPosition, yPosition);
	}
}
