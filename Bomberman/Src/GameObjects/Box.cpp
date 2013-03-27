#include <Bomberman/Src/GameObjects/Box.h>

#include <Bomberman/Src/GameObjects/ItemType.h>
#include <Bomberman/Src/Graphics/AssetManager.h>
#include <Bomberman/Src/Main/Game.h>

namespace Bomberman
{
	const double Box::ItemProbability = 0.5;

	Box::Box(Game& game, const AssetManager& assets, float xPosition, float yPosition)
		: GameObject(Rectangle(xPosition, yPosition, 48, 48), 1),
		  game_(game),
		  graphics_(assets.GetBrick())
	{
	}

	Box::~Box(void)
	{
	}

	void Box::Render(GraphicsManager& graphicsManager)
	{
		graphics_.Render(graphicsManager, static_cast<int>(position_.X), static_cast<int>(position_.Y));
	}

	void Box::Kill(void)
	{
		life_ = 0;
		double random = game_.RandomDouble();
		if (random < ItemProbability)
		{
			// Create a random item at the box position.
			// For now the item types are equally likely, so we simply get a random value from the enum.
			game_.CreateItem(position_.X, position_.Y, static_cast<ItemType::ItemTypeEnum>(game_.RandomInteger(0, ItemType::EnumMax)));
		}
	}

	bool Box::CanExplode(bool& block) const
	{
		block = true;
		return true;
	}
}