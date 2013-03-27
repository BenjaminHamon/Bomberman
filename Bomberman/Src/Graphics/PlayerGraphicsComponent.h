#pragma once

#include <vector>

#include <Bomberman/Src/GameObjects/MoveDirection.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AnimatedSprite;
	class AssetManager;
	class GraphicsManager;

	#pragma endregion

	/// <summary>
	/// Graphics component for a player.
	/// Handles in particular the player direction and if he is moving or not.
	/// </summary>
	class PlayerGraphicsComponent
	{
	public:
		/// <summary>
		/// Creates a new PlayerGraphicsComponent object.
		/// <param name="playerNumber">An integer between 0 and 3 determining the color of the player.</param>
		/// </summary>
		PlayerGraphicsComponent(const AssetManager& assets, int playerNumber, int animationSpeed);
		virtual ~PlayerGraphicsComponent(void);

	public:
		void Render(GraphicsManager& graphics, int xPosition, int yPosition, bool newIsMoving, MoveDirection::MoveDirectionEnum direction);

	private:
		/// <summary>
		/// Collection of animations for when the player is not moving.
		/// </summary>
		const std::vector<AnimatedSprite*>* animations_;
		/// <summary>
		/// Collection of animations for when the player is moving.
		/// </summary>
		const std::vector<AnimatedSprite*>* animationsMoving_;
		
		// Information to choose the correct sprite.
		/// <summary>
		/// Current time in the animation, between 0 and the product of animationSpeed and the animation length.
		/// </sumary>
		int animationTime_;
		/// <summary>
		/// Stores the previous moving state of the player.
		/// If it changes, the animation time will reset.
		/// </summary>
		bool isMoving_;
		/// <summary>
		/// Factor on the animation time, making it slower or faster.
		/// </sumary>
		int animationSpeed_;

	private:
		AnimatedSprite* GetAnimation(bool isMoving, MoveDirection::MoveDirectionEnum direction);
	};
}
