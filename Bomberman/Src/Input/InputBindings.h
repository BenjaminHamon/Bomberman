#pragma once

#include <vector>

#include <Bomberman/Src/Input/PlayerAction.h>
#include <Bomberman/Src/Input/InputKey.h>

namespace Bomberman
{
	class InputBindings
	{
	public:
		InputBindings(void) : bindings_(PlayerAction::EnumCount) {}
		~InputBindings(void) {}

	private:
		/// <summary>
		/// Collection of key bindings for the player actions.
		/// The vector indices are PlayerAction values.
		/// </sumary>
		std::vector<InputKey::InputKeyEnum> bindings_;

	public:
		InputKey::InputKeyEnum GetBinding(PlayerAction::PlayerActionEnum action) const { return bindings_[action]; }
		void SetBinding(PlayerAction::PlayerActionEnum action, InputKey::InputKeyEnum key) { bindings_[action] = key; }
	};
}