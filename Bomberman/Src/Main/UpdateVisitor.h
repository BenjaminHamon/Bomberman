#pragma once

#include <Bomberman/Src/Main/GameObjectVisitor.h>

namespace Bomberman
{
	class Game;

	/// <summary>
	/// Visitor to update the game objects.
	/// </sumary>
	class UpdateVisitor : public GameObjectVisitor
	{
	public:
		UpdateVisitor(Game& game);
		virtual ~UpdateVisitor(void);
	
	public:
		using GameObjectVisitor::Visit; // Unhides base class Visit(std::list<GameObject*>& objects) method.

	public:
		virtual void Visit(GameObject* object);
		virtual void Visit(Player* player);
		virtual void Visit(Item* item);
	};
}
