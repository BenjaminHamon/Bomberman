#pragma once

#include <SDL_video.h>

#include <Bomberman/Src/Graphics/AssetManager.h>

namespace Bomberman
{
	#pragma region Forward declarations

	class Map;
	class Sprite;

	#pragma endregion

	/// <summary>
	/// GraphicsManager handles the graphics operations for the application.
	/// In particular, it handles the drawing of the scene and must be called to draw an object.
	/// </summary>
	class GraphicsManager
	{
	#pragma region Constructor and destructor

	public:
		GraphicsManager(void);
		virtual ~GraphicsManager(void);

	#pragma endregion

	public:
		void Initialize(void);
		void Finalize(void);

	private:
		AssetManager assets_;
	public:
		const AssetManager& GetAssets(void) const { return assets_; }

	private:
		/// <summary>
		/// Video display, created with SDL_SetVideoMode.
		/// Its deletion is handled by the SDL.
		/// </summary>
		SDL_Surface* display_;

	public:
		/// <summary>
		/// Begins rendering the scene.
		/// Draws the game background.
		/// </summary>
		void BeginRender(void);
		/// <summary>
		/// Ends the rendering the scene.
		/// </summary>
		void EndRender(void);

		void Draw(SDL_Surface& sourceSurface, SDL_Rect& sourceRectangle, SDL_Rect& destinationRectangle);

		/// <summary>
		/// Draws a sprite at the specified location on the display.
		/// </summary>
		void Draw(Sprite* sprite, int x, int y);

		/// <summary>
		/// Draw an object in the game area.
		/// Drawing at (0, 0) will draw at (GameAreaX, GameAreaY).
		/// </summary>
		void DrawGameObject(Sprite* sprite, int x, int y);

	private:
		// Constants storing the origin of the game area.
		static const int GameAreaX = 325;
		static const int GameAreaY = 72;
	};
}