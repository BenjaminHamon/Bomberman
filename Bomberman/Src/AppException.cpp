#include <Bomberman/Src/AppException.h>

namespace Bomberman
{
	AppException::AppException(const std::string& message)
		: std::exception(),
		  message_(message)
	{
	}

	AppException::AppException(const std::string& message, const std::string& source)
		: std::exception(),
		  message_(source + ": " + message)
	{
	}

	AppException::~AppException(void)
	{
	}

	const char* AppException::what() const
	{
		return message_.c_str();
	}
}