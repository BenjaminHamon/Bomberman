#pragma once

#include <SDL_events.h>

#include <Bomberman/Src/Input/InputKey.h>

namespace Bomberman
{
	class Input
	{
	public:
		Input(void);
		virtual ~Input(void);

	public:
		void Initialize(void);

	public:
		/// <summary>
		/// Processes the specified event for input.
		/// </summary>
		void HandleEvent(const SDL_Event& sdlEvent);

	public:
		/// <sumary>
		/// Gets the state of a key.
		/// </summary>
		bool IsKeyDown(InputKey::InputKeyEnum key) const;
	};
}