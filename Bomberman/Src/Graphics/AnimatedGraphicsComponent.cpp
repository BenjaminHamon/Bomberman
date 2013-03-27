#include <Bomberman/Src/Graphics/AnimatedGraphicsComponent.h>

#include <Bomberman/Src/Graphics/AnimatedSprite.h>
#include <Bomberman/Src/Graphics/GraphicsManager.h>

namespace Bomberman
{
	AnimatedGraphicsComponent::AnimatedGraphicsComponent(AnimatedSprite* animatedSprite, int animationSpeed)
		: animatedSprite_(animatedSprite),
		  animationTime_(0),
		  animationSpeed_(animationSpeed)
	{
	}

	AnimatedGraphicsComponent::~AnimatedGraphicsComponent(void)
	{
	}

	void AnimatedGraphicsComponent::Render(GraphicsManager& graphics, int xPosition, int yPosition)
	{
		animationTime_ = (animationTime_ + 1) % (animatedSprite_->GetAnimationLength() * animationSpeed_);
		
		graphics.DrawGameObject(animatedSprite_->GetSprite(animationTime_ / animationSpeed_), xPosition, yPosition);
	}
}
