#include <Bomberman/Src/GameObjects/Map.h>

#include <Bomberman/Src/Rectangle.h>
#include <Bomberman/Src/Utils.h>

namespace Bomberman
{
	const float Map::CellWidth = 48.0;
	const float Map::CellHeight = 48.0;

	Map::Map(const AssetManager& assets)
		: GameObject(Rectangle(0, 0, 13 * CellWidth, 13 * CellHeight), 1),
		  mapWidth_(13),
		  mapHeight_(13),
		  cells_()
	{
		for (int j = 0; j < mapHeight_; ++j)
		{
			for (int i = 0; i < mapWidth_; ++i)
			{
				cells_.push_back(MapCell(assets, static_cast<float>(i * CellWidth), static_cast<float>(j * CellHeight), (i % 2 == 1) && (j % 2 == 1)));
			}
		}
	}

	Map::~Map(void)
	{
	}

	void Map::Render(GraphicsManager& graphicsManager)
	{
		for (std::vector<MapCell>::iterator it = cells_.begin(); it != cells_.end(); ++it)
		{
			it->Render(graphicsManager);
		}
	}

	bool Map::IsCollidingWith(const GameObject& object) const
	{
		for (std::vector<MapCell>::const_iterator it = cells_.cbegin(); it != cells_.cend(); ++it)
		{
			if (it->IsCollidingWith(object) == true)
				return true;
		}
		return false;
	}

	bool Map::IsCollidingWith(const Rectangle& rect) const
	{
		return false;
		//return CanMoveTo(rect);
	}

	bool Map::CanMoveTo(const GameObject* movingObject, const Rectangle& position, const std::list<GameObject*>& objects) const
	{
		if (IsInMapBounds(position) == false)
			return false;

		const MapCell* cell = GetCellFromRealPosition(position.Left(), position.Top());
		if (cell->GetIsObstacle() == true)
			return false;
		cell = GetCellFromRealPosition(position.Right() - 1, position.Top());
		if (cell->GetIsObstacle() == true)
			return false;
		cell = GetCellFromRealPosition(position.Left(), position.Bottom() - 1);
		if (cell->GetIsObstacle() == true)
			return false;
		cell = GetCellFromRealPosition(position.Right() - 1, position.Bottom() - 1);
		if (cell->GetIsObstacle() == true)
			return false;

		for (std::list<GameObject*>::const_iterator it = objects.cbegin(); it != objects.cend(); ++it)
		{
			if ((*it != movingObject) && ((*it)->IsCollidable() == true) && (*it)->IsCollidingWith(position) == true)
				return false;
		}
		return true;
	}

	bool Map::IsInMapBounds(const Rectangle& rectangle) const
	{
		return (rectangle.Left() >= 0) && (rectangle.Top() >= 0) && (rectangle.Right() <= (mapWidth_ * CellWidth)) && (rectangle.Bottom() <= (mapHeight_ * CellHeight));
	}

	const MapCell* Map::GetCellFromRealPosition(float x, float y) const
	{
		int n = static_cast<int>(x / CellWidth) + static_cast<int>(y / CellHeight) * mapWidth_;
		return &(cells_[n]);
	}
}