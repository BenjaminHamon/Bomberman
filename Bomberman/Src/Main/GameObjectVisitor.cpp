#include <Bomberman/Src/Main/GameObjectVisitor.h>

#include <Bomberman/Src/GameObjects/GameObject.h>

namespace Bomberman
{
	GameObjectVisitor::GameObjectVisitor(Game& game)
		: game_(game)
	{
	}

	GameObjectVisitor::~GameObjectVisitor(void)
	{
	}

	void GameObjectVisitor::Visit(std::list<GameObject*>& objects)
	{
		for (std::list<GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it)
		{
			(*it)->Accept(*this);
		}
	}
}