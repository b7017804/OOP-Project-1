#include <iostream>		// for output and input
#include <string>		// for string
#include <sstream>		// for streamstring

using namespace std;

#include "Game.h"

int main()
{
	UserInterface ui;
	Game game;

	game.set_up(&ui);
	game.run();

	ui.hold_window();
	return 0;
}