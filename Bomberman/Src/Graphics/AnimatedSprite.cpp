#include <Bomberman/Src/Graphics/AnimatedSprite.h>

#include <Bomberman/Src/Graphics/Sprite.h>

namespace Bomberman
{
	AnimatedSprite::AnimatedSprite(const std::vector<Sprite*>* sprites)
		: sprites_(sprites)
	{
	}

	AnimatedSprite::~AnimatedSprite(void)
	{
		if (sprites_ != nullptr)
		{
			for (std::vector<Sprite*>::const_iterator it = sprites_->cbegin(); it != sprites_->cend(); ++it)
			{
				delete *it;
			}
			delete sprites_;
		}
	}

	Sprite* AnimatedSprite::GetSprite(int animationTime) const
	{
		return (*sprites_)[animationTime];
	}
}