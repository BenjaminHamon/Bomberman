#pragma once

#include <vector>
#include <list>

#include <Bomberman/Src/GameObjects/GameObject.h>
#include <Bomberman/Src/GameObjects/MapCell.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AssetManager;
	class GraphicsManager;
	class Rectangle;

	#pragma endregion

	/// <summary>
	/// 
	/// </sumary>
	class Map : public GameObject
	{
	#pragma region Constructor and destructor

	public:
		Map(const AssetManager& assets);
		virtual ~Map(void);

	#pragma endregion

	public:
		void Render(GraphicsManager& graphicsManager);

	public:
		virtual bool IsCollidingWith(const GameObject& object) const;
		virtual bool IsCollidingWith(const Rectangle& rect) const;

		/// <summary>
		/// Tests if the destination position is reachable.
		/// </summary>
		bool CanMoveTo(const GameObject* movingObject, const Rectangle& position, const std::list<GameObject*>& objects) const;

	private:
		const int mapWidth_;
		const int mapHeight_;

		std::vector<MapCell> cells_;
		/// <summary>
		/// Gets the cell containing the position (x, y).
		/// </summary>
		const MapCell* GetCellFromRealPosition(float x, float y) const; // { return &(cells_[static_cast<int>(x / CellWidth + (y / CellHeight) * mapWidth_)]); }

	public:
		static const float CellWidth;
		static const float CellHeight;

	public:
		float GetMaxX(void) const { return (mapWidth_ - 1) * CellWidth; }
		float GetMaxY(void) const { return (mapHeight_ - 1) * CellHeight; }

	public:
		/// <summary>
		/// Tests if an area is within the map bounds.
		/// </summary>
		bool IsInMapBounds(const Rectangle& rectangle) const;
	};
}