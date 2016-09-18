// include header files
#include "vector2.h"
#include "navigator.h"

int main()
{
	// create a new instance of Navigator
	Navigator* navigator = new Navigator();

	// Call the Ask Directions Method
	navigator->AskDirections();

	// clean up
	delete navigator;
	navigator = NULL;

	//-------------------------------------------------------

	// output a message to console
	cout << "Press any key to quit the application" << endl;
	// ignore any user input for console instructions
	cin.ignore();
	// wait for a key press before exiting the console
	cin.get();
	// ensure we exit without error
	return 0;
}