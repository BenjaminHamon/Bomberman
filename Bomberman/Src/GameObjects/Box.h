#pragma once

#include <Bomberman/Src/GameObjects/GameObject.h>
#include <Bomberman/Src/Graphics/GraphicsComponent.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AssetManager;
	class Game;
	class GraphicsManager;

	#pragma endregion

	/// <summary>
	/// Box is a destructible game object that may spawn an item.
	/// </summary>
	class Box : public GameObject
	{
	#pragma region Constructor and destructor

	public:
		Box(Game& game, const AssetManager& assets, float xPosition, float yPosition);
		virtual ~Box(void);

	#pragma endregion

	private:
		Game& game_;

	public:
		void Render(GraphicsManager& graphicsManager);

	private:
		GraphicsComponent graphics_;
	
	public:
		virtual void Kill(void);

	public:
		virtual bool CanExplode(bool& block) const;

		virtual bool IsCollidable(void) const { return true; }

	private:
		/// <summary>
		/// The probability, between 0 and 1, of the box spawning an item.
		/// </summary>
		static const double ItemProbability;
	};
}