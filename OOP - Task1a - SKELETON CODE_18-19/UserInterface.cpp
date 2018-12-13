#include <conio.h>	// for _getch()

#include "UserInterface.h" 

int UserInterface::get_keypress_from_user() const
{	//DO NOT CHANGE THIS FUNCTION
	// read in the selected arrow key or command letter
	int key_pressed(_getch());

	// ignore symbol following cursor key
	while (key_pressed == 224)
		key_pressed = _getch();

	// return the key in uppercase
	return(toupper(key_pressed));
}

const void UserInterface::draw_grid_on_screen(const string& grid_data) const
{
	// clear screen
	system("cls");

	cout << grid_data;
}

const void UserInterface::show_results_on_screen(string message) const
{
	cout << message;
}

const void UserInterface::hold_window()
{
	cout << "\n\n";
	system("pause");
}