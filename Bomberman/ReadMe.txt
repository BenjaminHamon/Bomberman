Project Bomberman

by Benjamin Hamon <hamon.benjamin@gmail.com>


** The old Bomberman **

This project is based on another Bomberman made for the EPITA video game rush by:
 Francois Carnis <fcarnis@gmail.com>
 Francois Forlot <francois.forlot@epita.fr>
 Benjamin Hamon  <hamon.benjamin@gmail.com>

It was a Bomberman made in 36 hours, programmed in C.

The goal of this new project was to remake the Bomberman in C++,
and it became a complete rewrite of the game from scratch.


** Goals **

What this project is meant to be:
- A quick made game, before getting serious and coding a MMORTS.
- An in depth and complex practice ground for C++.
- An experiment laboratory for patterns, C++ features, game development, etc.

What this project is not meant to be:
- A piece of art.
- The perfect game.


** Bindings **

Player 1 (top left):
WASD to move, Space to place a bomb.

Player 2 (bottom right):
Arrows to move, Left Ctrl to place a bomb.


** Version **

v1

Features:
- Two players on the same computer.
- Items: more bombs, bigger explosions, more speed.
- Basic terrain.
- Bomb chain explosion.

Known issues:
- Obstacles don't block explosions.
- Player movement: the player does not move from cell to cell, he can stop between cells.
  This causes changing direction to be difficult (the player must be precisely at the good spot),
  although moving in diagonal (holding down two keys) will make the player turn at the crossroads.
- Framerate drop when flooding with bombs and explosions.


** Distributions **

Release
  Content:	The game executable, the runtime libraries and the needed resource files.
  Use:		Ready to play version of the game.

Development
  Content:	The VS project, the source files and the resources files.
  Use:		Developer version. Requires additional setup for the project dependencies.

  The development version requires that you have downloaded the libraries
  and set the environment variables needed by the project.
  You will also need to copy the required DLL (x86) to the output directory (Debug or Release).

  Library		Env variable	Env variable example						Download URL
  --------------------------------------------------------------------------------------------------------------------------------------------
  SDL			SdlDir			F:\Development\Libraries\SDL-1.2.15			http://www.libsdl.org/download-1.2.php (Development Win32 Visual C++)
  SDL_image		SdlImageDir		F:\Development\Libraries\SDL_image-1.2.12	http://www.libsdl.org/projects/SDL_image/ (Binary Windows devel-VC)
  --------------------------------------------------------------------------------------------------------------------------------------------

Build Ready
  Content:	The VS project, the source files, the resource files and the libraries.
  Use:		Ready to build version.