#pragma once

#include <Bomberman/Src/GameObjects/GameObject.h>
#include <Bomberman/Src/GameObjects/ItemType.h>
#include <Bomberman/Src/Graphics/GraphicsComponent.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AssetManager;
	class GraphicsManager;

	#pragma endregion

	class Item : public GameObject
	{
	#pragma region Constructor and destructor

	public:
		Item(const AssetManager& assets, float xPosition, float yPosition, ItemType::ItemTypeEnum type);
		virtual ~Item(void);

	#pragma endregion

	public:
		void Update(void);
		void Render(GraphicsManager& graphicsManager);

	public:
		virtual void Accept(GameObjectVisitor& visitor);

	private:
		GraphicsComponent graphics_;

	private:
		/// <summary>
		/// Short protection to prevent the item from being destroyed by the same explosion that spawned it.
		/// </summary>
		int protection_;
		ItemType::ItemTypeEnum type_;
	public:
		ItemType::ItemTypeEnum GetType(void) const { return type_; }

	public:
		virtual void Kill(void);

	public:
		virtual bool CanExplode(bool& block) const;
	};
}