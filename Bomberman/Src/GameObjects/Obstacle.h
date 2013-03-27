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
	/// Indestructible object blocking movement.
	/// </summary>
	class Obstacle : public GameObject
	{
	public:
		Obstacle(const AssetManager& assets, float xPosition, float yPosition);
		virtual ~Obstacle(void);

	public:
		void Render(GraphicsManager& graphicsManager);

	private:
		GraphicsComponent graphics_;
	};
}