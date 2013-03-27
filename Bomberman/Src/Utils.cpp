#include <Bomberman/Src/Utils.h>

namespace Bomberman
{
	int Utils::Clamp(int number, int lowerBound, int upperBound)
	{
		if (number < lowerBound)
			return lowerBound;
		if (number > upperBound)
			return upperBound;
		return number;
	}
}