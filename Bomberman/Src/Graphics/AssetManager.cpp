#include <Bomberman/Src/Graphics/AssetManager.h>

#include <SDL_image.h>

#include <Bomberman/Src/AppException.h>
#include <Bomberman/Src/Graphics/AnimatedSprite.h>
#include <Bomberman/Src/Graphics/Sprite.h>

namespace Bomberman
{
	const std::string AssetManager::ResourcePath = "Resources/";
	const std::string AssetManager::SpriteSheetPath = "SpriteSheet.png";
	const std::string AssetManager::MenuBackgroundPath = "MenuBackground.png";
	const std::string AssetManager::GameBackgroundPath = "GameBackground.png";

	AssetManager::AssetManager(void)
		: spriteSheet_(nullptr),
		  menuBackground_(nullptr),
		  gameBackground_(nullptr),
		  grass_(nullptr),
		  stone_(nullptr),
		  brick_(nullptr),
		  players_(4),
		  playersMoving_(4),
		  speedItem_(nullptr),
		  powerItem_(nullptr),
		  bombItem_(nullptr),
		  bombAnimatedSprite_(nullptr),
		  explosionCenter_(nullptr),
		  explosionHorizontal_(nullptr),
		  explosionVertical_(nullptr),
		  explosionTopEnd_(nullptr),
		  explosionRightEnd_(nullptr),
		  explosionBottomEnd_(nullptr),
		  explosionLeftEnd_(nullptr)
	{
	}

	AssetManager::~AssetManager(void)
	{
	}

	void AssetManager::LoadImages(void)
	{
		spriteSheet_ = IMG_Load((ResourcePath + SpriteSheetPath).c_str());
		if (spriteSheet_ == nullptr)
			throw AppException(IMG_GetError());

		menuBackground_ = IMG_Load((ResourcePath + MenuBackgroundPath).c_str());
		if (menuBackground_ == nullptr)
			throw AppException(IMG_GetError());

		gameBackground_ = IMG_Load((ResourcePath + GameBackgroundPath).c_str());
		if (gameBackground_ == nullptr)
			throw AppException(IMG_GetError());

		grass_ = new Sprite(spriteSheet_, 150, 63, 48, 48);
		stone_ = new Sprite(spriteSheet_, 12, 51, 48, 48);
		brick_ = new Sprite(spriteSheet_, 81, 51, 48, 48);

		std::vector<Sprite*>* sprites = nullptr;

		for (int playerNumber = 0; playerNumber < 4; ++playerNumber)
		{
			for (int i = 0; i < MoveDirection::EnumCount; ++i)
			{
				sprites = new std::vector<Sprite*>();
				for (int j = 0; j < 3; ++j)
				{
					sprites->push_back(new Sprite(spriteSheet_, 9 + 69 * j, 684 + 111 * i * 2 + 888 * playerNumber, 54, 87));
				}
				players_[playerNumber].push_back(new AnimatedSprite(sprites));

				sprites = new std::vector<Sprite*>();
				for (int j = 0; j < 8; ++j)
				{
					sprites->push_back(new Sprite(spriteSheet_, 9 + 69 * j, 684 + 111 + 111 * i * 2 + 888 * playerNumber, 54, 87));
				}
				playersMoving_[playerNumber].push_back(new AnimatedSprite(sprites));
			}
		}

		speedItem_ = new Sprite(spriteSheet_, 219, 63, 48, 48);
		powerItem_ = new Sprite(spriteSheet_, 219 + 69, 63, 48, 48);
		bombItem_ = new Sprite(spriteSheet_, 219 + 69 * 2, 63, 48, 48);

		sprites = new std::vector<Sprite*>();
		sprites->push_back(new Sprite(spriteSheet_, 11, 173, 48, 48));
		sprites->push_back(new Sprite(spriteSheet_, 69 + 11, 173, 48, 48));
		sprites->push_back(new Sprite(spriteSheet_, 69 + 69 + 11, 173, 48, 48));
		bombAnimatedSprite_ = new AnimatedSprite(sprites);

		sprites = new std::vector<Sprite*>();
		for (int i = 0; i < 4; ++i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12, 285 + 111 * i, 48, 48));
		}
		for (int i = 2; i >= 0; --i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12, 285 + 111 * i, 48, 48));
		}
		explosionCenter_ = new AnimatedSprite(sprites);

		sprites = new std::vector<Sprite*>();
		for (int i = 0; i < 4; ++i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69, 285 + 111 * i, 48, 48));
		}
		for (int i = 2; i >= 0; --i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69, 285 + 111 * i, 48, 48));
		}
		explosionHorizontal_ = new AnimatedSprite(sprites);

		sprites = new std::vector<Sprite*>();
		for (int i = 0; i < 4; ++i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69 * 2, 285 + 111 * i, 48, 48));
		}
		for (int i = 2; i >= 0; --i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69 * 2, 285 + 111 * i, 48, 48));
		}
		explosionVertical_ = new AnimatedSprite(sprites);

		sprites = new std::vector<Sprite*>();
		for (int i = 0; i < 4; ++i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69 * 3, 285 + 111 * i, 48, 48));
		}
		for (int i = 2; i >= 0; --i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69 * 3, 285 + 111 * i, 48, 48));
		}
		explosionTopEnd_ = new AnimatedSprite(sprites);

		sprites = new std::vector<Sprite*>();
		for (int i = 0; i < 4; ++i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69 * 4, 285 + 111 * i, 48, 48));
		}
		for (int i = 2; i >= 0; --i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69 * 4, 285 + 111 * i, 48, 48));
		}
		explosionRightEnd_ = new AnimatedSprite(sprites);

		sprites = new std::vector<Sprite*>();
		for (int i = 0; i < 4; ++i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69 * 5, 285 + 111 * i, 48, 48));
		}
		for (int i = 2; i >= 0; --i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69 * 5, 285 + 111 * i, 48, 48));
		}
		explosionBottomEnd_ = new AnimatedSprite(sprites);

		sprites = new std::vector<Sprite*>();
		for (int i = 0; i < 4; ++i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69 * 6, 285 + 111 * i, 48, 48));
		}
		for (int i = 2; i >= 0; --i)
		{
			sprites->push_back(new Sprite(spriteSheet_, 12 + 69 * 6, 285 + 111 * i, 48, 48));
		}
		explosionLeftEnd_ = new AnimatedSprite(sprites);
	}

	void AssetManager::UnloadImages(void)
	{
		if (grass_ != nullptr)
		{
			delete grass_;
			grass_ = nullptr;
		}
		if (stone_ != nullptr)
		{
			delete stone_;
			stone_ = nullptr;
		}
		if (brick_ != nullptr)
		{
			delete brick_;
			brick_ = nullptr;
		}
		for (std::vector<std::vector<AnimatedSprite*>>::iterator playerVector = players_.begin(); playerVector != players_.end(); ++playerVector)
		{
			for (std::vector<AnimatedSprite*>::const_iterator anim = playerVector->cbegin(); anim != playerVector->cend(); ++anim)
			{
				delete *anim;
			}
			playerVector->clear();
		}
		for (std::vector<std::vector<AnimatedSprite*>>::iterator playerVector = playersMoving_.begin(); playerVector != playersMoving_.end(); ++playerVector)
		{
			for (std::vector<AnimatedSprite*>::const_iterator anim = playerVector->cbegin(); anim != playerVector->cend(); ++anim)
			{
				delete *anim;
			}
			playerVector->clear();
		}
		if (bombAnimatedSprite_ != nullptr)
		{
			delete bombAnimatedSprite_;
			bombAnimatedSprite_ = nullptr;
		}
		if (speedItem_ != nullptr)
		{
			delete speedItem_;
			speedItem_ = nullptr;
		}
		if (powerItem_ != nullptr)
		{
			delete powerItem_;
			powerItem_ = nullptr;
		}
		if (bombItem_ != nullptr)
		{
			delete bombItem_;
			bombItem_ = nullptr;
		}
		if (explosionCenter_ != nullptr)
		{
			delete explosionCenter_;
			explosionCenter_ = nullptr;
		}
		if (explosionHorizontal_ != nullptr)
		{
			delete explosionHorizontal_;
			explosionHorizontal_ = nullptr;
		}
		if (explosionVertical_ != nullptr)
		{
			delete explosionVertical_;
			explosionVertical_ = nullptr;
		}
		if (explosionTopEnd_ != nullptr)
		{
			delete explosionTopEnd_;
			explosionTopEnd_ = nullptr;
		}
		if (explosionRightEnd_ != nullptr)
		{
			delete explosionRightEnd_;
			explosionRightEnd_ = nullptr;
		}
		if (explosionBottomEnd_ != nullptr)
		{
			delete explosionBottomEnd_;
			explosionBottomEnd_ = nullptr;
		}
		if (explosionLeftEnd_ != nullptr)
		{
			delete explosionLeftEnd_;
			explosionLeftEnd_ = nullptr;
		}

		if (spriteSheet_ != nullptr)
		{
			SDL_FreeSurface(spriteSheet_);
			spriteSheet_ = nullptr;
		}
		if (menuBackground_ != nullptr)
		{
			SDL_FreeSurface(menuBackground_);
			menuBackground_ = nullptr;
		}
		if (gameBackground_ != nullptr)
		{
			SDL_FreeSurface(gameBackground_);
			gameBackground_ = nullptr;
		}
	}

	Sprite* AssetManager::GetItem(ItemType::ItemTypeEnum type) const
	{
		switch (type)
		{
			case ItemType::Bomb:
				return bombItem_;
			case ItemType::Power:
				return powerItem_;
			case ItemType::Speed:
				return speedItem_;
			default:
				throw AppException("Unexpected enum value", "AssetManager::GetItem");
		}
	}
}