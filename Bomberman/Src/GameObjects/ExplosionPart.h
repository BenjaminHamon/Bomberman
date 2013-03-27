#pragma once

#include <list>

#include <Bomberman/Src/GameObjects/GameObject.h>
#include <Bomberman/Src/Graphics/AnimatedGraphicsComponent.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AnimatedSprite;
	class Bomb;
	class Item;

	#pragma endregion

	/// <summary>
	/// An explosion part is an explosion on a single map cell.
	/// </summary>
	class ExplosionPart : public GameObject
	{
	public:
		ExplosionPart(AnimatedSprite* sprite, float xPosition, float yPosition, int life);
		virtual ~ExplosionPart(void);

	public:
		void Update(std::list<GameObject*>& objects_, std::list<Bomb>& bombs, std::list<Item>& items);
		void Render(GraphicsManager& graphicsManager);

	private:
		AnimatedGraphicsComponent graphics_;
	};
}