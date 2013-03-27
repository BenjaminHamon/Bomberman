#pragma once

namespace Bomberman
{
	/// <summary>
	/// Simple rectangle class to store a rectangle-shaped area.
	/// </sumary>
	class Rectangle
	{
	public:
		Rectangle(float x, float y, float width, float height);
		~Rectangle(void);

	public:
		float X;
		float Y;
		float Width;
		float Height;

	public:
		// Methods to get the rectangle edges.
		inline float Top() const { return Y; }
		inline float Right() const { return X + Width; }
		inline float Bottom() const { return Y + Height; }
		inline float Left() const { return X; }

	public:
		/// <summary>
		/// Tests wether the intersection between two rectangles is empty or not.
		/// </summary>
		bool Intersect(const Rectangle& other) const;
	};
}