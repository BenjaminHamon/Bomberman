#pragma once

#include <Bomberman/Src/Rectangle.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class Game;
	class GraphicsManager;
	class GameObjectVisitor;

	#pragma endregion

	/// <summary>
	/// Base abstract class for game entities.
	/// </summary>
	class GameObject
	{

	#pragma region Constructor and destructor

	public:
		GameObject(const Rectangle& position, int life);
		virtual ~GameObject(void) = 0;

	#pragma endregion

	protected:
		/// <summary>
		/// The object position in the world. It is used for collision detection and drawing.
		/// </summary>
		Rectangle position_;

	#pragma region Life

	protected:
		/// <summary>
		/// The game object life. The object should be deleted when its life reaches 0.
		/// </summary>
		int life_;

	public:
		/// <summary>
		/// Returns the state of the object. If false, the object will be deleted at the end of the game tick.
		/// </summary>
		bool IsAlive(void) const { return life_ > 0; }

		/// <summary>
		/// 'Kills' the object, setting its life to 0.
		/// Takes care of the object behavior at death.
		/// </summary>
		virtual void Kill(void);

	#pragma endregion

	#pragma region Collision

	public:
		/// <summary>
		/// Detects collision between two game objects.
		/// </summary>
		virtual bool IsCollidingWith(const GameObject& object) const;
		/// <summary>
		/// Detects collision between a game object and a zone.
		/// </summary>
		virtual bool IsCollidingWith(const Rectangle& rect) const;
		/// <summary>
		/// True if the object blocks other objects.
		/// This is not used in IsCollidingWith and simply tells if the object does blocking collisions.
		/// </summary>
		virtual bool IsCollidable(void) const { return false; }

	#pragma endregion

	public:
		/// <summary>
		/// Draw the game object.
		/// </summary>
		virtual void Render(GraphicsManager& graphicsManager) = 0;

	public:
		// Accept will be made pure when all object classes will be in the visitor and in Game object list
		/// <summary>
		/// Accepts a Visitor.
		/// See the Visitor design pattern.
		/// </summary>
		virtual void Accept(GameObjectVisitor& visitor);

	public:
		/// <summary>
		/// Verifies if the object can be killed by an explosion.
		/// Block is an out parameter to return wether the object also prevents the explosion from going further.
		/// </summary>
		virtual bool CanExplode(bool& block) const;
	};
}
