#include <Bomberman/Src/GameObjects/Bomb.h>

# include <Bomberman/Src/Graphics/AssetManager.h>
# include <Bomberman/Src/Main/Game.h>

namespace Bomberman
{
	const float Bomb::Width = 48.0;
	const float Bomb::Height = 48.0;

	Bomb::Bomb(Game& game, const AssetManager& assets, float xPosition, float yPosition, int power)
		: GameObject(Rectangle(xPosition, yPosition, Width, Height), 30),
		  game_(game),
		  graphics_(assets.GetBombAnimatedSprite(), 10),
		  power_(power)
	{
	}

	Bomb::~Bomb(void)
	{
	}

	void Bomb::Update(void)
	{
		life_--;
		if (IsAlive() == false)
		{
			Kill();
		}
	}

	void Bomb::Render(GraphicsManager& graphicsManager)
	{
		graphics_.Render(graphicsManager, int(position_.X), int(position_.Y));
	}

	void Bomb::Kill(void)
	{
		life_ = 0;
		game_.CreateExplosion(position_.X, position_.Y, power_);
	}

	bool Bomb::CanExplode(bool& block) const
	{
		block = false;
		return true;
	}
}
