#pragma once

#include <string>
#include <vector>

#include <SDL_video.h>

#include <Bomberman/Src/GameObjects/ItemType.h>
#include <Bomberman/Src/GameObjects/MoveDirection.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class AnimatedSprite;
	class Sprite;

	#pragma endregion

	// TODO: Serious clean up.
	// AssetManager will be reworked to use a collection of assets and exterior metadata for loading and finding assets (See ToDo.txt)

	/// <summary>
	/// <para>
	/// AssetManager manages all the graphical assets needed by the game.
	/// It loads and unloads these assets.
	/// </para>
	/// <para>
	/// The graphics components should keep the references to their assets
	/// but must not create or delete them.
	/// </para>
	/// </summary>
	class AssetManager
	{
	#pragma region Constructor and destructor

	public:
		AssetManager(void);
		virtual ~AssetManager(void);

	#pragma endregion

	public:
		void LoadImages(void);
		void UnloadImages(void);

	private:
		/// <summary>
		/// Base path to the resources/assets directory
		/// </summary>
		static const std::string ResourcePath;

		static const std::string SpriteSheetPath;
		SDL_Surface* spriteSheet_;

		static const std::string MenuBackgroundPath;
		SDL_Surface* menuBackground_;

		static const std::string GameBackgroundPath;
		SDL_Surface* gameBackground_;

	public:
		SDL_Surface* GetSpriteSheet(void) const { return spriteSheet_; }
		SDL_Surface* GetMenuBackground(void) const { return menuBackground_; }
		SDL_Surface* GetGameBackground(void) const { return gameBackground_; }

	private:
		Sprite* grass_;
		Sprite* stone_;
		Sprite* brick_;
		std::vector<std::vector<AnimatedSprite*>> players_;
		std::vector<std::vector<AnimatedSprite*>> playersMoving_;
		Sprite* speedItem_;
		Sprite* powerItem_;
		Sprite* bombItem_;
		AnimatedSprite* bombAnimatedSprite_;
		AnimatedSprite* explosionCenter_;
		AnimatedSprite* explosionHorizontal_;
		AnimatedSprite* explosionVertical_;
		AnimatedSprite* explosionTopEnd_;
		AnimatedSprite* explosionRightEnd_;
		AnimatedSprite* explosionBottomEnd_;
		AnimatedSprite* explosionLeftEnd_;

	public:
		Sprite* GetGrass(void) const { return grass_; }
		Sprite* GetStone(void) const { return stone_; }
		Sprite* GetBrick(void) const { return brick_; }
		const std::vector<AnimatedSprite*>* GetPlayer(int number) const { return &(players_[number]); }
		const std::vector<AnimatedSprite*>* GetPlayerMoving(int number) const { return &(playersMoving_[number]); }
		Sprite* GetItem(ItemType::ItemTypeEnum type) const;
		AnimatedSprite* GetBombAnimatedSprite(void) const { return bombAnimatedSprite_; }
		AnimatedSprite* GetExplosionCenter(void) const { return explosionCenter_; }
		AnimatedSprite* GetExplosionHorizontal(void) const { return explosionHorizontal_; }
		AnimatedSprite* GetExplosionVertical(void) const { return explosionVertical_; }
		AnimatedSprite* GetExplosionTopEnd(void) const { return explosionTopEnd_; }
		AnimatedSprite* GetExplosionRightEnd(void) const { return explosionRightEnd_; }
		AnimatedSprite* GetExplosionBottomEnd(void) const { return explosionBottomEnd_; }
		AnimatedSprite* GetExplosionLeftEnd(void) const { return explosionLeftEnd_; }
	};
}