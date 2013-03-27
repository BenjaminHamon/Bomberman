#pragma once

// About the Component classes
//
// This is an attempt at component oriented programming.
// See http://gameprogrammingpatterns.com/component.html
//
// The goal of this method is to split big classes in separate components,
// each component handles a specific domain, such as graphics or physics.
// The previous classes become containers for these components and the shared data.
//
// The main benefit is to prevent avoid inheritance problems within a complex object class hierarchy.
// This will also achieve a better separation of concerns, less coupling and smaller classes.
//
// For example, a Graphics Component handles the drawing of an object and stores all graphics specific data.
// The object item has a graphics component member and the needed methods which will be forward the work to the component.

namespace Bomberman
{
	class GraphicsManager;
	class Sprite;

	/// <summary>
	/// Graphics component for a game object.
	/// Draws a single non animated sprite.
	/// </summary>
	class GraphicsComponent
	{
	public:
		GraphicsComponent(Sprite* sprite);
		virtual ~GraphicsComponent(void);

	public:
		void Render(GraphicsManager& graphics, int xPosition, int yPosition);

	private:
		Sprite* sprite_;
	};
}