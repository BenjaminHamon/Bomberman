#include <Bomberman/Src/GameObjects/GameObject.h>

#include <Bomberman/Src/Main/GameObjectVisitor.h>

namespace Bomberman
{
	GameObject::GameObject(const Rectangle& position, int life)
		: position_(position),
		  life_(life)
	{
	}

	GameObject::~GameObject(void)
	{
	}

	bool GameObject::IsCollidingWith(const GameObject& object) const
	{
		return position_.Intersect(object.position_);
	}

	bool GameObject::IsCollidingWith(const Rectangle& rect) const
	{
		return position_.Intersect(rect);
	}

	void GameObject::Accept(GameObjectVisitor& visitor)
	{
		visitor.Visit(this);
	}

	void GameObject::Kill(void)
	{
		life_ = 0;
	}

	bool GameObject::CanExplode(bool& block) const
	{
		block = true;
		return false;
	}
}
