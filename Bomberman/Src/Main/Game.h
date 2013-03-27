#pragma once

#include <list>
#include <random>

#include <Bomberman/Src/Graphics/GraphicsManager.h>
#include <Bomberman/Src/Input/Input.h>
#include <Bomberman/Src/Main/UpdateVisitor.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class Bomb;
	class Explosion;
	class GameObject;
	class Map;

	#pragma endregion

	/// <summary>
	/// Main class for the game.
	/// </summary>
	class Game
	{
		friend class UpdateVisitor;

	#pragma region Constructor and destructor

	public:
		Game(void);
		virtual ~Game(void);

	#pragma endregion

	#pragma region Game loop

	public:
		/// <summary>
		/// Runs the game. Returns when the game is exited.
		/// Initializes the game, then runs the game loop. Finalizes the game after leaving the loop.
		/// </sumary>
		void Run(void);

	private:
		/// <summary>
		/// Initializes the game.
		/// Initializes the game components and creates the game objects.
		/// </summary>
		void Initialize(void);
		void CreatePlayers(void);

		/// <summary>
		/// Updates all the game objects.
		/// </sumary>
		void Update(void);
		/// <summary>
		/// Remove killed objects from the game.
		/// </summary>
		void RemoveDeadObjects(void);
		/// <summary>
		/// Draw all the game objects by calling their Render method.
		/// </summary>
		void Render(void);

		/// <sumary>
		/// Finalizes the game.
		/// Finalizes the game components and deletes the game objects.
		/// </summary>
		void Finalize(void);

	private:
		/// <summary>
		/// True when the user closes the game. This will exit the game loop.
		/// </summary>
		bool exitRequested_;

	#pragma endregion

	#pragma region Game components

	private:
		/// <summary>
		/// Game component handling draw calls and everything related to the game display.
		/// </summary>
		GraphicsManager graphics_;
		/// <summary>
		/// Game component to record the user input.
		/// </summary>
		Input input_;

		/// <summary>
		/// Visitor used to update the game objects.
		/// </summary>
		UpdateVisitor updateVisitor_;

	#pragma endregion

	#pragma region Game objects
	
	private:
		Map* map_;
		std::list<Bomb> bombs_;
		std::list<Explosion> explosions_;

		std::list<GameObject*> objects_;

	public:
		/// <summary>
		/// Creates a bomb at the specified position.
		/// Called by a Player object.
		/// </summary>
		bool CreateBomb(float xPosition, float yPosition, int power);
		/// <summary>
		/// Creates an explosion at the specified position.
		/// Called by a Bomb object.
		/// </summary>
		void CreateExplosion(float xPosition, float yPosition, int power);
		/// <summary>
		/// Creates an item at the specified position.
		/// Called by a Box object.
		/// </summary>
		void CreateItem(float xPosition, float yPosition, ItemType::ItemTypeEnum type);

	#pragma endregion

	#pragma region Random numbers generation

		// The random number generation use the <random> library, which is a feature of C++11.
	public:
		std::default_random_engine randomGenerator_;
		std::uniform_real_distribution<double> randomDistribution_;
		/// <summary>
		/// Gets a random double between 0 and 1.
		/// </sumary>
		double RandomDouble();
		/// <summary>
		/// Gets a random integer between min and max.
		/// </sumary>
		int RandomInteger(int min, int max);

	#pragma endregion
	};
}