#include <Bomberman/Src/GameObjects/Explosion.h>

#include <Bomberman/Src/GameObjects/Bomb.h>
#include <Bomberman/Src/GameObjects/ExplosionPart.h>
#include <Bomberman/Src/GameObjects/Item.h>
#include <Bomberman/Src/GameObjects/Map.h>
#include <Bomberman/Src/GameObjects/Player.h>
#include <Bomberman/Src/Graphics/AssetManager.h>
#include <Bomberman/Src/Utils.h>

namespace Bomberman
{
	Explosion::Explosion(const AssetManager& assets, float xPosition, float yPosition, int power, std::list<GameObject*>& objects, const Map& map)
		: GameObject(Rectangle(xPosition, yPosition, 0, 0), 14),
		  parts_()
	{
		// Create the explosion parts.

		parts_.push_back(ExplosionPart(assets.GetExplosionCenter(), xPosition, yPosition, 14));
		
		// Each loop expands in one direction as long as not blocked and as long as the power is not exhausted.
		// Top
		bool block = false;
		for (int i = 1; (i <= power) && (block == false); ++i)
		{
			if (CanExplode(Rectangle(xPosition, yPosition - 48 * i, 48, 48), objects, map, block) == true)
			{
				AnimatedSprite* sprite = (i == power) ? assets.GetExplosionTopEnd() : assets.GetExplosionVertical(); // The final part has its own sprites.
				parts_.push_back(ExplosionPart(sprite, xPosition, yPosition - 48 * i, 14));
			}
		}
		// Right
		block = false;
		for (int i = 1; (i <= power) && (block == false); ++i)
		{
			if (CanExplode(Rectangle(xPosition + 48 * i, yPosition, 48, 48), objects, map, block) == true)
			{
				AnimatedSprite* sprite = (i == power) ? assets.GetExplosionRightEnd() : assets.GetExplosionHorizontal();
				parts_.push_back(ExplosionPart(sprite, xPosition + 48 * i, yPosition, 14));
			}
		}
		// Bottom
		block = false;
		for (int i = 1; (i <= power) && (block == false); ++i)
		{
			if (CanExplode(Rectangle(xPosition, yPosition + 48 * i, 48, 48), objects, map, block) == true)
			{
				AnimatedSprite* sprite = (i == power) ? assets.GetExplosionBottomEnd() : assets.GetExplosionVertical();
				parts_.push_back(ExplosionPart(sprite, xPosition, yPosition + 48 * i, 14));
			}
		}
		// Left
		block = false;
		for (int i = 1; (i <= power) && (block == false); ++i)
		{
			if (CanExplode(Rectangle(xPosition - 48 * i, yPosition, 48, 48), objects, map, block) == true)
			{
				AnimatedSprite* sprite = (i == power) ? assets.GetExplosionLeftEnd() : assets.GetExplosionHorizontal();
				parts_.push_back(ExplosionPart(sprite, xPosition - 48 * i, yPosition, 14));
			}
		}
	}

	Explosion::~Explosion(void)
	{
	}

	void Explosion::Update(std::list<GameObject*>& objects, std::list<Bomb>& bombs)
	{
		for (std::list<GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it)
		{
			if ((*it)->IsAlive() && IsCollidingWith(**it) == true)
				(*it)->Kill();
		}
		for (std::list<Bomb>::iterator it = bombs.begin(); it != bombs.end(); ++it)
		{
			if (it->IsAlive() && IsCollidingWith(*it))
				it->Kill();
		}
		life_--;
	}

	bool Explosion::IsCollidingWith(const GameObject& object) const
	{
		for (std::list<ExplosionPart>::const_iterator it = parts_.cbegin(); it != parts_.cend(); ++it)
		{
			if (it->IsCollidingWith(object) == true)
				return true;
		}
		return false;
	}

	bool Explosion::IsCollidingWith(const Rectangle& rect) const
	{
		for (std::list<ExplosionPart>::const_iterator it = parts_.cbegin(); it != parts_.cend(); ++it)
		{
			if (it->IsCollidingWith(rect) == true)
				return true;
		}
		return false;
	}
	
	void Explosion::Render(GraphicsManager& graphicsManager)
	{
		for (std::list<ExplosionPart>::iterator it = parts_.begin(); it != parts_.end(); ++it)
		{
			it->Render(graphicsManager);
		}
	}

	bool Explosion::CanExplode(const Rectangle& zone, std::list<GameObject*>& objects, const Map& map, bool& block)
	{
		block = false;
		if (map.IsInMapBounds(zone) == false)
			return false;
		for (std::list<GameObject*>::const_iterator it = objects.cbegin(); it != objects.cend(); ++it)
		{
			if ((*it)->IsCollidingWith(zone) == true)
			{
				return (*it)->CanExplode(block);
			}
		}
		return true;
	}
}