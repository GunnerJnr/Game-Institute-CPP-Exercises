// include header files
#include <iostream>

// using namespace declaration
using namespace std;

int main()
{
	// variables
	double realNumber = 0;

	// output a message to the console
	cout << "\t\t\t\t\tCube Program" << endl;
	cout << "\t\t\t\t\t============";

	// output a new line
	cout << endl;

	cout << "Please enter a real number : ";
	// store the value entered by the user
	cin >> realNumber;

	// do the math (cube)
	double result = realNumber * realNumber * realNumber;

	// output a new line
	cout << endl;

	// output the sum and the answer to the console
	cout << realNumber << " ^ 3 = " << result;

	// output a new line
	cout << endl << endl;

	// output a message to the console
	cout << "Press any key to exit the application" << endl;

	// ignore any user input for console instructions
	cin.ignore();
	// wait for a key press before exiting the console
	cin.get();
	// ensure we exit without error
	return 0;
}