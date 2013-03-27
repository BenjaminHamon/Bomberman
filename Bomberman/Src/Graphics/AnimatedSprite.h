#pragma once

#include <vector>

namespace Bomberman
{
	class Sprite;

	/// <summary>
	/// Graphic element for animations.
	/// Stores a collection of sprites producing an animation.
	/// </summary>
	class AnimatedSprite
	{
	public:
		AnimatedSprite(const std::vector<Sprite*>* sprites);
		virtual ~AnimatedSprite(void);

	private:
		/// <summary>
		/// Sprites created by the AssetManager and passed as a parameter to the constructor.
		/// The AnimatedSprite is the owner of these sprites and must handle their deletion.
		/// </summary>
		const std::vector<Sprite*>* const sprites_;

	public:
		/// <sumary>
		/// Gets the animation length, which is the number of sprites used in the animation.
		/// </summary>
		int GetAnimationLength(void) const { return sprites_->size(); }

	public:
		Sprite* GetSprite(int animationTime) const;
	};
}