#pragma once

namespace Bomberman
{
	struct ItemType
	{
		static const int EnumCount = 3;
		static const int EnumMax = 2;

		/// <summary>
		/// Enumeration for an item type.
		/// </summary>
		enum ItemTypeEnum
		{
			Speed = 0, // Increases the player speed.
			Power = 1, // Increases the explosions range.
			Bomb = 2,  // Increases the maximum number of carried bombs.
		};
	};
}