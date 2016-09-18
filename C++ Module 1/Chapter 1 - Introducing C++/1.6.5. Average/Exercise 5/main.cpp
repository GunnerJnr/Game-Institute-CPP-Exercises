// include header files
#include <iostream>

// using namespace declaration
using namespace std;

int main()
{
	// variables
	double x, numbers, sum = 0;

	// output a message to the console
	cout << "\t\t\t\t\tAverage" << endl;
	cout << "\t\t\t\t\t=======" << endl << endl;

	// output a message to the console
	cout << "Enter how many numbers : ";
	cin >> numbers;

	// output a new line
	cout << endl << endl;

	// here we create a for loop to
	for (int i = 1; i <= numbers; i++)
	{
		// ask the user to enter the numbers
		cout << "Enter Number " << i << " : ";
		// store the numbers entered
		cin >> x;

		// calculate the numbers entered (by adding them), and store the value in sum
		sum += x;
	}

	// now we calculate the average, x equals sum divided by the amount of numbers (e.g 5)
	x = sum / numbers;

	// output a new line
	cout << endl << endl;

	// output the 'Average' to the console
	cout << "You chose " << numbers << " 'Numbers'" << endl;
	cout << "The 'Sum' of those " << numbers << " 'Numbers' was " << sum << endl;
	cout << "So the 'Average' of your : " << numbers << " 'Numbers' is " << x << endl;
	cout << "('Sum' / 'Numbers' = 'Average')" << endl << endl;

	// output a message to the console
	cout << "Press any key to exit the application" << endl;

	// ignore any user input for console instructions
	cin.ignore();
	// wait for a key press before exiting the console
	cin.get();
	// ensure we exit without error
	return 0;
}