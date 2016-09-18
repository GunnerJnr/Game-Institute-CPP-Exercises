// include header files
#include <iostream>

// using namespace declaration
using namespace std;

int main()
{
	// variables
	const double PI = 3.14159265359f;
	double radius = 0.0f;

	// output a message to the console
	cout << "\t\t\t\t\tCircumference\\Radius" << endl;
	cout << "\t\t\t\t\t====================" << endl << endl;
	cout << "Enter the radius of a circle : ";
	// store the user input
	cin >> radius;

	// do the math
	double area = PI * radius * radius;

	// output a new line
	cout << endl;

	// output a message with the radius to the console
	cout << "The area (A) of a circle with radius " << radius << " = " << area << endl;

	// do the math
	double circumference = 2 * PI * radius;

	// output a message and the circumference to the console
	cout << "The circumference (C) of a circle with radius " << radius << " = " << circumference << endl << endl;

	// output a message to the console
	cout << "Press any key to exit the application" << endl;

	// ignore any user input for console instructions
	cin.ignore();
	// wait for a key press before exiting the console
	cin.get();
	// ensure we exit without error
	return 0;
}