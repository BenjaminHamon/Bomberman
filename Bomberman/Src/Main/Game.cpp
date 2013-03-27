#include <Bomberman/Src/Main/Game.h>

#include <iostream>

#include <SDL.h>

#include <Bomberman/Src/AppException.h>
#include <Bomberman/Src/GameObjects/Bomb.h>
#include <Bomberman/Src/GameObjects/Box.h>
#include <Bomberman/Src/GameObjects/Explosion.h>
#include <Bomberman/Src/GameObjects/GameObject.h>
#include <Bomberman/Src/GameObjects/Item.h>
#include <Bomberman/Src/GameObjects/Player.h>
#include <Bomberman/Src/GameObjects/Map.h>
#include <Bomberman/Src/Input/InputBindings.h>

namespace Bomberman
{

#pragma warning(push)
#pragma warning(disable: 4355) // 'this' used in base member initializer list
// This is safe as long as 'this' is not used until fully constructed,
// and UpdateVisitor only stores the reference for later use.
	Game::Game(void)
		: exitRequested_(false),
		  graphics_(),
		  input_(),
		  map_(nullptr),
		  bombs_(),
		  explosions_(),
		  //items_(),
		  objects_(),
		  updateVisitor_(*this),
		  randomGenerator_(),
		  randomDistribution_(0.0, 1.0)
	{
	}
#pragma warning(pop)

	Game::~Game(void)
	{
	}

	void Game::Run(void)
	{
		Initialize();
		
		int frameCount = 0;
		Uint32 startTime = SDL_GetTicks();

		while(exitRequested_ == false)
		{
			++frameCount;
			double elapsedTime = SDL_GetTicks() - startTime; // In milliseconds
			if (elapsedTime >= 1000.0)
			{
				double fps = 1000.0 * frameCount / elapsedTime;
				std::cout << "FPS: " << fps << std::endl; // Display FPS in console.
				frameCount = 0;
				startTime = SDL_GetTicks();
			}

			SDL_Event sdlEvent;
			while(SDL_PollEvent(&sdlEvent) != 0)
			{
				if (sdlEvent.type == SDL_QUIT)
				{
					exitRequested_ = true;
				}
				else
				{
					input_.HandleEvent(sdlEvent);
				}
			}

			Update();
			RemoveDeadObjects();
			Render();
		}

		Finalize();
	}

	void Game::Initialize(void)
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			throw AppException(SDL_GetError(), "Game::Initialize");
		}
		input_.Initialize();
		graphics_.Initialize();

		map_ = new Map(graphics_.GetAssets());

		CreatePlayers();
		
		for (int i = 2; i < 11; ++i)
		{
			objects_.push_back(new Box(*this, graphics_.GetAssets(), i * 48.0f, 0));
			objects_.push_back(new Box(*this, graphics_.GetAssets(), i * 48.0f, 48.0f * 12));
			if (i % 2 == 0)
			{
				objects_.push_back(new Box(*this, graphics_.GetAssets(), i * 48.0f, 48.0f));
				objects_.push_back(new Box(*this, graphics_.GetAssets(), i * 48.0f, 48.0f * 11));
			}
		}

		for (int j = 2; j < 11; ++j)
		{
			if (j % 2 == 0)
			{
				for (int i = 0; i < 13; ++i)
				{
					objects_.push_back(new Box(*this, graphics_.GetAssets(), i * 48.0f, 48.0f * j));
				}
			}
			else
			{
				for (int i = 0; i < 13; i += 2)
				{
					objects_.push_back(new Box(*this, graphics_.GetAssets(), i * 48.0f, 48.0f * j));
				}
			}
		}
	}

	void Game::CreatePlayers(void)
	{
		InputBindings* bindings = new InputBindings();
		bindings->SetBinding(PlayerAction::MoveUp, InputKey::W);
		bindings->SetBinding(PlayerAction::MoveRight, InputKey::D);
		bindings->SetBinding(PlayerAction::MoveDown, InputKey::S);
		bindings->SetBinding(PlayerAction::MoveLeft, InputKey::A);
		bindings->SetBinding(PlayerAction::DropBomb, InputKey::Space);

		objects_.push_back(new Player(graphics_.GetAssets(), 0, 0, 0, bindings));

		bindings = new InputBindings();
		bindings->SetBinding(PlayerAction::MoveUp, InputKey::UpArrow);
		bindings->SetBinding(PlayerAction::MoveRight, InputKey::RightArrow);
		bindings->SetBinding(PlayerAction::MoveDown, InputKey::DownArrow);
		bindings->SetBinding(PlayerAction::MoveLeft, InputKey::LeftArrow);
		bindings->SetBinding(PlayerAction::DropBomb, InputKey::RightCtrl);

		objects_.push_back(new Player(graphics_.GetAssets(), 1, 48 * 12, 48 * 12, bindings));
	}

	void Game::Finalize(void)
	{
		graphics_.Finalize();

		for (std::list<GameObject*>::iterator it = objects_.begin(); it != objects_.end(); ++it)
		{
			delete *it;
		}
		objects_.clear();

		if (map_ != nullptr)
		{
			delete map_;
			map_ = nullptr;
		}

		SDL_Quit();
	}

	void Game::Update(void)
	{
		updateVisitor_.Visit(objects_);

		for (std::list<Bomb>::iterator it = bombs_.begin(); it != bombs_.end(); ++it)
		{
			it->Update();
		}
		for (std::list<Explosion>::iterator it = explosions_.begin(); it != explosions_.end(); ++it)
		{
			it->Update(objects_, bombs_);
		}
	}

	void Game::RemoveDeadObjects(void)
	{
		for (std::list<GameObject*>::iterator it = objects_.begin(); it != objects_.end(); )
		{
			if ((*it)->IsAlive() == false)
			{
				delete *it;
				it = objects_.erase(it);
			}
			else
				++it;
		}

		for (std::list<Bomb>::iterator it = bombs_.begin(); it != bombs_.end(); )
		{
			if (it->IsAlive() == false)
				it = bombs_.erase(it);
			else
				++it;
		}
		for (std::list<Explosion>::iterator it = explosions_.begin(); it != explosions_.end(); )
		{
			if (it->IsAlive() == false)
				it = explosions_.erase(it);
			else
				++it;
		}
	}

	void Game::Render(void)
	{
		graphics_.BeginRender();
		map_->Render(graphics_);
		for (std::list<Bomb>::iterator it = bombs_.begin(); it != bombs_.end(); ++it)
		{
			it->Render(graphics_);
		}
		for (std::list<Explosion>::iterator it = explosions_.begin(); it != explosions_.end(); ++it)
		{
			it->Render(graphics_);
		}
		for (std::list<GameObject*>::iterator it = objects_.begin(); it != objects_.end(); ++it)
		{
			(*it)->Render(graphics_);
		}
		graphics_.EndRender();
	}

	bool Game::CreateBomb(float xPosition, float yPosition, int power)
	{
		// Position is the actual position where the bomb will be created (the nearest cell) instead of where the player precisely is.
		/*Rectangle position((xPosition + Bomb::Width / 2) / Bomb::Width * Bomb::Width,
			(yPosition + Bomb::Height / 2) / Bomb::Height * Bomb::Height,
			Bomb::Width, Bomb::Height);*/
		Rectangle position(xPosition, yPosition, Bomb::Width, Bomb::Height);
		for (std::list<Bomb>::const_iterator it = bombs_.cbegin(); it != bombs_.cend(); ++it)
		{
			if (it->IsCollidingWith(position) == true)
				return false;
		}
		bombs_.push_back(Bomb(*this, graphics_.GetAssets(), position.X, position.Y, power));
		return true;
	}

	void Game::CreateExplosion(float xPosition, float yPosition, int power)
	{
		explosions_.push_back(Explosion(graphics_.GetAssets(), xPosition, yPosition, power, objects_, *map_));
	}

	void Game::CreateItem(float xPosition, float yPosition, ItemType::ItemTypeEnum type)
	{
		objects_.push_back(new Item(graphics_.GetAssets(), xPosition, yPosition, type));
	}

	double Game::RandomDouble()
	{
		return randomDistribution_(randomGenerator_);
	}

	int Game::RandomInteger(int min, int max)
	{
		std::uniform_int_distribution<int> distribution(min, max);
		return distribution(randomGenerator_);
	}
}