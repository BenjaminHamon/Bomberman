#pragma once

#include <Bomberman/Src/GameObjects/GameObject.h>
#include <Bomberman/Src/Graphics/GraphicsComponent.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AssetManager;
	class GraphicsManager;

	#pragma endregion

	/// <summary>
	/// 
	/// </summary>
	class MapCell : public GameObject
	{
	#pragma region Constructor and destructor

	public:
		MapCell(const AssetManager& assets, float xPosition, float yPosition, bool obstacle);
		virtual ~MapCell(void);

	#pragma endregion

	public:
		void Render(GraphicsManager& graphicsManager);

	private:
		GraphicsComponent graphics_;

	private:
		bool obstacle_;
	public:
		/// <sumary>
		/// Tests if the cell is blocking.
		/// </summary>
		bool GetIsObstacle(void) const { return obstacle_; }

	public:
		virtual bool IsCollidingWith(const GameObject& object) const;
		virtual bool IsCollidingWith(const Rectangle& rect) const;

	public:
		virtual bool CanExplode(bool& block) const;
	};
}
