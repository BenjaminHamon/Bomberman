#pragma once

#include <Bomberman/Src/GameObjects/GameObject.h>
#include <Bomberman/Src/Graphics/AnimatedGraphicsComponent.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AssetManager;
	class Game;
	class GraphicsManager;

	#pragma endregion

	/// <summary>
	/// Bomb game object. A bomb is created by a player and will create an explosion after a short time.
	/// </summary>
	class Bomb : public GameObject
	{
	#pragma region Constructor and destructor

	public:
		Bomb(Game& game, const AssetManager& assets, float xPosition, float yPosition, int power);
		virtual ~Bomb(void);

	#pragma endregion

	public:
		void Update(void);
		void Render(GraphicsManager& graphicsManager);

	private:
		Game& game_;
		/// <summary>
		/// The bomb power. Each power point means the explosion will reach a cell further in each direction.
		/// </summary>
		int power_;

	public:
		static const float Width;
		static const float Height;

	private:
		AnimatedGraphicsComponent graphics_;

	public:
		virtual void Kill(void);

	public:
		virtual bool CanExplode(bool& block) const;
		
		virtual bool IsCollidable(void) const { return true; }
	};
}
