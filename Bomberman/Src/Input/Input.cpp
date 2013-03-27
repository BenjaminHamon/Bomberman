#include <Bomberman/Src/Input/Input.h>

#include <Bomberman/Src/AppException.h>

namespace Bomberman
{
	Input::Input(void)
	{
	}

	Input::~Input(void)
	{
	}

	void Input::Initialize(void)
	{
	}

	void Input::HandleEvent(const SDL_Event& sdlEvent)
	{
		switch (sdlEvent.type)
		{
			case SDL_KEYDOWN:
				break;
			case SDL_KEYUP:
				break;
			default:
				break;
		}
	}

	bool Input::IsKeyDown(InputKey::InputKeyEnum key) const
	{
		int keyCount;
		Uint8* keys = SDL_GetKeyState(&keyCount);
		if (keyCount < key)
		{
			throw AppException("Invalid key index.", "Input::IsKeyDown");
		}
		return keys[key] == 1;
	}
}