#include <Bomberman/Src/Graphics/PlayerGraphicsComponent.h>

#include <Bomberman/Src/Graphics/AnimatedSprite.h>
#include <Bomberman/Src/Graphics/AssetManager.h>
#include <Bomberman/Src/Graphics/GraphicsManager.h>

namespace Bomberman
{
	PlayerGraphicsComponent::PlayerGraphicsComponent(const AssetManager& assets, int playerNumber, int animationSpeed)
		: animations_(assets.GetPlayer(playerNumber)),
		  animationsMoving_(assets.GetPlayerMoving(playerNumber)),
		  animationTime_(0),
		  isMoving_(false),
		  animationSpeed_(animationSpeed)
	{
	}

	PlayerGraphicsComponent::~PlayerGraphicsComponent(void)
	{
	}

	void PlayerGraphicsComponent::Render(GraphicsManager& graphics, int xPosition, int yPosition, bool newIsMoving, MoveDirection::MoveDirectionEnum direction)
	{
		// Reset the animation time if the moving state has changed.
		if (newIsMoving != isMoving_)
		{
			animationTime_ = 0;
			isMoving_ = newIsMoving;
		}
		else
		{
			// Advance one step in the animation.
			// animationTime is between 0 and the produce of the animation length and the animation speed.
			animationTime_ = (animationTime_ + 1) % (GetAnimation(isMoving_, direction)->GetAnimationLength() * animationSpeed_);
		}
		graphics.DrawGameObject(GetAnimation(isMoving_, direction)->GetSprite(animationTime_ / animationSpeed_), xPosition, yPosition - 39);
	}

	AnimatedSprite* PlayerGraphicsComponent::GetAnimation(bool isMoving, MoveDirection::MoveDirectionEnum direction)
	{
		if (isMoving == true)
			return (*animationsMoving_)[direction];
		else
			return (*animations_)[direction];
	}
}
