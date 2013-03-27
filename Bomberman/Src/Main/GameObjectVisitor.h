#pragma once

#include <list>

namespace Bomberman
{
	#pragma region Forward declarations

	class Game;
	class GameObject;
	class Item;
	class Player;

	#pragma endregion

	/// <summary>
	/// Base abstract Visitor for the game objects.
	/// See http://en.wikipedia.org/wiki/Visitor_pattern for information on the Visitor design pattern.
	/// Here the visitor is used to simulate double dispatch (See http://en.wikipedia.org/wiki/Double_dispatch).
	/// </summary>
	class GameObjectVisitor
	{
	public:
		GameObjectVisitor(Game& game);
		virtual ~GameObjectVisitor(void);

	public:
		/// <summary>
		/// Visits every game object in the specified collection.
		/// </summary>
		void Visit(std::list<GameObject*>& objects);

	public:
		// These Visit methods are called by the Accept method of the object passed as parameter.
		virtual void Visit(GameObject* object) = 0;
		virtual void Visit(Player* player) = 0;
		virtual void Visit(Item* item) = 0;

	protected:
		Game& game_;
	};
}
