#ifndef BOMBERMAN_MOVE_DIRECTION_H
# define BOMBERMAN_MOVE_DIRECTION_H

namespace Bomberman
{
	struct MoveDirection
	{
		static const int EnumCount = 4;

		/// <summary>
		/// Enumeration for the player movement direction. Used to display the correct player sprite.
		/// </summary>
		enum MoveDirectionEnum
		{
			Down = 0,
			Left,
			Up,
			Right,
		};
	};
}

#endif // BOMBERMAN_MOVE_DIRECTION_H