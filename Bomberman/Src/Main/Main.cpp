#include <iostream>

#if _DEBUG
#include <vld.h>
// Visual Leak Detector - Open source memory leak detection system for Visual C++
// You can find it here: http://vld.codeplex.com/
// It will display a summary of the memory leaks at the end of the progam execution.
//
// If you do not want to use it, simply comment the include line.
//
// If you want to use it, download and install Visual Leak Detector.
// Then set the environment variable used by the project: $(VisualLeakDetectorDir)
// to its installation directory, for example: 'F:\Development\Visual Leak Detector'.
// You should be good to go!
#endif

#include <Bomberman/Src/AppException.h>
#include <Bomberman/Src/Main/Game.h>

int main(int argc, char* argv[])
{
	Bomberman::Game& game = Bomberman::Game();
	try
	{
		game.Run();
	}
	catch(Bomberman::AppException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		system("pause");
	}

	return (0);
}
