#pragma once

#include <list>

#include <Bomberman/Src/GameObjects/GameObject.h>
#include <Bomberman/Src/GameObjects/MoveDirection.h>
#include <Bomberman/Src/Graphics/PlayerGraphicsComponent.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AssetManager;
	class Game;
	class GraphicsManager;
	class Input;
	class InputBindings;
	class Item;
	class Map;

	#pragma endregion

	/// <summary>
	/// A player avatar.
	/// </summary>
	class Player : public GameObject
	{
	#pragma region Constructor and destructor

	public:
		Player(const AssetManager& assets, int playerNumber, float xPosition, float yPosition, InputBindings* bindings);
		virtual ~Player(void);

	#pragma endregion

	public:
		void Update(const Input& input, Game& game, const Map& map, std::list<GameObject*>& objects);
		void Render(GraphicsManager& graphicsManager);
		virtual void Accept(GameObjectVisitor& visitor);

	#pragma region Movement
	
	private:
		/// <summary>
		/// Calculates the new player position according to the player input and the map objects.
		/// Called by Update.
		/// </sumary>
		void Move(const Input& input, const Map& map, const std::list<GameObject*>& objects);
		
		// Information used to correctly display the player.
		bool isMoving_;
		MoveDirection::MoveDirectionEnum direction_;

	#pragma endregion

	private:
		/// <sumary>
		/// Looks for items to be picked up by the player.
		/// If any is found, it is killed and its effects are applied to the player.
		/// </summary>
		void PickItems(std::list<GameObject*>& objects);

	#pragma region Stats
	
	private:
		/// <summary>
		/// Base player speed. It is the player speed at the start and without bonuses.
		/// </summary>
		static const float BaseSpeed;
		/// <summary>
		/// Modifier applied on the player base speed.
		/// Starts at 1, can be increased by picking up speed items.
		/// </sumary>
		float speedModifier_;
		/// <summary>
		/// Get the actual player speed.
		/// </summary>
		inline float RealSpeed(void) const { return BaseSpeed * speedModifier_; }

		/// <summary>
		/// Maximum number of bombs carried by the player. The bombs reload until reaching it.
		/// Increased by picking up Bomb items.
		/// </summary>
		int maxBombs_;
		/// <summary>
		/// Number of currently available bombs to be placed by the player.
		/// Decreases at each placed bomb and increases back to maxBombs over time.
		/// When it is 0, the player cannot place a bomb.
		/// </summary>
		int availableBombs_;
		/// <summary>
		/// Total number of ticks for the player to receive another bomb.
		/// </summary>
		static const int BombReloadTime;
		/// <summary>
		/// Timer running from 0 to BombReloadTime, when the player does not have the maximum possible of bombs.
		/// When BombReloadTime is reached, the player gets another bomb.
		/// </summary>
		int bombReload_;
		/// <summary>
		/// The power of the bombs carried by the player.
		/// This affects the range of the explosions created by the next bombs placed by the player.
		/// </sumary>
		int power_;

	#pragma endregion

	public:
		virtual void Kill(void);

	private:
		PlayerGraphicsComponent graphics_;

	public:
		virtual bool CanExplode(bool& block) const;

	private:
		/// <summary>
		/// Key bindings.
		/// Created before the player construction and passed to it in the constructor.
		/// The player destructor delete it.
		/// </summary>
		InputBindings* const bindings_;
	};
}