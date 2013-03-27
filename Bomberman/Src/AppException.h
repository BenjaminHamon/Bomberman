#pragma once

#include <exception>
#include <string>

namespace Bomberman
{
	/// <summary>
	/// Base class for the exceptions thrown by the application.
	/// </sumary>
	class AppException : public std::exception
	{
	public:
		AppException(const std::string& message);
		/// <summary>
		/// Creates an AppException object using a message and a source.
		/// Source is the origin location of the exception, for example Game::Initialize.
		/// </summary>
		AppException(const std::string& message, const std::string& source);
		virtual ~AppException(void);

	private:
		const std::string message_;

	public:
		virtual const char* what() const;
	};
}