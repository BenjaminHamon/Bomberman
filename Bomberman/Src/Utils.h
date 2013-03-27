#pragma once

namespace Bomberman
{
	/// <summary>
	/// Static methods for general purpose.
	/// </summary>
	class Utils
	{
	private:
		Utils(void) {}
		~Utils(void) {}

	public:
		/// <summary>
		/// Clamps number to the range between lowerBound and upperBound.
		/// <returns>lowerBound if number is less than lowerBound, upperBound if it is greater than upperBound, number otherwise.</returns>
		/// </summary>
		static int Clamp(int number, int lowerBound, int upperBound);
	};
}
