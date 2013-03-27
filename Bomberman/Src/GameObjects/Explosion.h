#pragma once

#include <list>

#include <Bomberman/Src/GameObjects/ExplosionPart.h>
#include <Bomberman/Src/GameObjects/GameObject.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AssetManager;
	class Bomb;
	class Game;
	class GraphicsManager;
	class Item;
	class Map;

	#pragma endregion

	/// <summary>
	/// Explosion created by a bomb death.
	/// Explosions immediately expands in a cross patern from the center according to their power.
	/// During their short life, they kill any destructible object in its path.
	/// A bomb destroyed by an explosion will trigger its own explosion, making chain explosions.
	/// </summary>
	class Explosion : public GameObject
	{
	#pragma region Constructor and destructor

	public:
		Explosion(const AssetManager& assets, float xPosition, float yPosition, int power, std::list<GameObject*>& objects, const Map& map);
		virtual ~Explosion(void);

	#pragma endregion

	public:
		/// <sumary>
		/// Update the explosion, killing the destructible objects in the explosion area.
		/// </summary>
		void Update(std::list<GameObject*>& objects, std::list<Bomb>& bombs);
		virtual void Render(GraphicsManager& graphicsManager);

	public:
		// We need to override the collision methods as collision is determined with the explosion parts.
		virtual bool IsCollidingWith(const GameObject& object) const;
		virtual bool IsCollidingWith(const Rectangle& rect) const;

	private:
		/// <summary>
		/// Collection of explosion parts, a part corresponding to a map cell.
		/// They are created in the constructor, according to the explosion power and the obstacles.
		/// </summary>
		std::list<ExplosionPart> parts_;

	private:
		bool CanExplode(const Rectangle& zone, std::list<GameObject*>& objects, const Map& map, bool& block);
	};
}