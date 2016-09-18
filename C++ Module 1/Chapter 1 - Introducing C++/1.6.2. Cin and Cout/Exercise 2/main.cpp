// include header files
#include <iostream>
#include <string>

// using namespace declaration
using namespace std;

int main()
{
	// variables
	// here we create 2 strings to hold the first and last names
	string firstName, lastName = "";

	// output a message to the console
	cout << "\t\t\t\t\tCin and Cout" << endl;
	cout << "\t\t\t\t\t============" << endl << endl;

	cout << "Please enter your first name and press enter:";
	// store the users first name
	cin >> firstName;

	// output a second message to the console
	cout << "Please enter your last name and press enter:";
	// store the users second name
	cin >> lastName;

	// create a third string variable and assign it the values from first and last name
	string fullName = firstName + " " + lastName;

	// output a new line
	cout << endl;
	// output a message and the users name to the console
	cout << "Thank you for your details " << fullName << ", We will be in touch soon!";
	// output a new line
	cout << endl << endl;
	// output a message to the console
	cout << "Press any key to exit the application";
	// output a new line
	cout << endl << endl;

	// ignore any user input for console instructions
	cin.ignore();
	// wait for a key press before exiting the console
	cin.get();
	// ensure we exit without error
	return 0;
}