// include header files
#include <iostream>

// using namespace declaration
using namespace std;

int main()
{
	// variables
	double realNumber1, realNumber2 = 0;

	// output a message to the console
	cout << "\t\t\t\t\tAritmetic Program" << endl;
	cout << "\t\t\t\t\t=================" << endl << endl;

	// output a message to the console
	cout << "Enter your first real number (N1) : ";
	// store the first entered number
	cin >> realNumber1;

	// output a second message tot he console
	cout << "Enter your second real number (N2) : ";
	// store the second entered number
	cin >> realNumber2;

	// do the math and print the results to the console
	cout << "// Addition" << endl;
	cout << "N1 + N2 = " << realNumber1 + realNumber2 << endl;	// addition
	cout << "// Subtraction" << endl;
	cout << "N1 - N2 = " << realNumber1 - realNumber2 << endl;	// subtraction
	cout << "// Multiplication" << endl;
	cout << "N1 * N2 = " << realNumber1 * realNumber2 << endl;	// multiplication
	cout << "// Division" << endl;
	cout << "N1 / N2 = " << realNumber1 / realNumber2 << endl;	// division
	cout << "// Modulus" << endl;
	cout << "N1 % N2 = " << realNumber1 / realNumber2 << endl;	// modulus

	// ignore any user input for console instructions
	cin.ignore();
	// wait for a key press before exiting the console
	cin.get();
	// ensure we exit without error
	return 0;
}