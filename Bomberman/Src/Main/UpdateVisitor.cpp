#include <Bomberman/Src/Main/UpdateVisitor.h>

#include <Bomberman/Src/GameObjects/GameObject.h>
#include <Bomberman/Src/GameObjects/Item.h>
#include <Bomberman/Src/GameObjects/Player.h>
#include <Bomberman/Src/Main/Game.h>

namespace Bomberman
{
	UpdateVisitor::UpdateVisitor(Game& game)
		: GameObjectVisitor(game)
	{
	}

	UpdateVisitor::~UpdateVisitor(void)
	{
	}

	void UpdateVisitor::Visit(GameObject* object)
	{
	}

	void UpdateVisitor::Visit(Player* player)
	{
		player->Update(game_.input_, game_, *(game_.map_), game_.objects_);
	}

	void UpdateVisitor::Visit(Item* item)
	{
		item->Update();
	}
}
