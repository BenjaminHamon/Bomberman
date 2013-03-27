#include <Bomberman/Src/GameObjects/MapCell.h>

#include <Bomberman/Src/Graphics/AssetManager.h>
#include <Bomberman/Src/Rectangle.h>

namespace Bomberman
{
	MapCell::MapCell(const AssetManager& assets, float xPosition, float yPosition, bool obstacle)
		: GameObject(Rectangle(xPosition, yPosition, 48, 48), 1),
		  graphics_((obstacle == true) ? assets.GetStone() : assets.GetGrass()),
		  obstacle_(obstacle)
	{
	}

	MapCell::~MapCell(void)
	{
	}

	void MapCell::Render(GraphicsManager& graphicsManager)
	{
		graphics_.Render(graphicsManager, static_cast<int>(position_.X), static_cast<int>(position_.Y));
	}

	bool MapCell::IsCollidingWith(const GameObject& object) const
	{
		return (obstacle_ == true) && GameObject::IsCollidingWith(object);
	}

	bool MapCell::IsCollidingWith(const Rectangle& rect) const
	{
		return (obstacle_ == true) && GameObject::IsCollidingWith(rect);
	}

	bool MapCell::CanExplode(bool& block) const
	{
		block = obstacle_;
		return obstacle_ == false;
	}
}