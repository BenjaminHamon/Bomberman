#pragma once

namespace Bomberman
{
	struct PlayerAction
	{
		static const int EnumCount = 5;

		/// <summary>
		/// Enumeration for the player actions.
		/// </sumary>
		enum PlayerActionEnum
		{
			MoveUp = 0,
			MoveRight,
			MoveDown,
			MoveLeft,
			DropBomb,
		};
	};
}