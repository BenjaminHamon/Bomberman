#include <Bomberman/Src/GameObjects/Item.h>

#include <Bomberman/Src/Graphics/AssetManager.h>
#include <Bomberman/Src/GameObjects/Map.h>
#include <Bomberman/Src/Main/GameObjectVisitor.h>

namespace Bomberman
{
	Item::Item(const AssetManager& assets, float xPosition, float yPosition, ItemType::ItemTypeEnum type)
		: GameObject(Rectangle(xPosition, yPosition, Map::CellWidth, Map::CellHeight), 1),
		  graphics_(assets.GetItem(type)),
		  type_(type),
		  protection_(15)
	{
	}

	Item::~Item(void)
	{
	}

	void Item::Update(void)
	{
		if (protection_ > 0)
		{
			protection_--;
		}
	}

	void Item::Render(GraphicsManager& graphicsManager)
	{
		graphics_.Render(graphicsManager, static_cast<int>(position_.X), static_cast<int>(position_.Y));
	}

	void Item::Accept(GameObjectVisitor& visitor)
	{
		visitor.Visit(this);
	}

	void Item::Kill(void)
	{
		if (protection_ <= 0)
		{
			life_ = 0;
		}
	}

	bool Item::CanExplode(bool& block) const
	{
		block = false;
		return true;
	}
}
