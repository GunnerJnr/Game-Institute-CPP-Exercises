// includes
#include <iostream>
#include <cmath>

// using std's
using std::cout;
using std::cin;
using std::endl;

// function prototypes
// Menu
void Menu(int userChoice = 0, float x = 0.0f, float y = 0.0f, bool quit = false);

// main program entry point
int main()
{
	// call the menu function
	Menu();

	// output message
	cout << "Press any key key to exit";

	cin.get();
	cin.ignore();
	return 0;
}

// Menu
void Menu(int userChoice, float x, float y, bool quit)
{
	// while not quit
	while (quit == false)
	{
		// output a message
		cout << "Calculator Program V1.0" << endl;
		cout << "=======================" << endl << endl;
		// output the menu choices
		cout << "[1]cos(x), [2]sin(x), [3]tan(x), [4]atan2(y, x), [5]sqrt(x), [6]x^y" << endl;
		cout << "[7]ln(x), [8]e^x, [9]|x|, [10]floor(x), [11]ceil(x), [12]Exit" << endl << endl;
		// ask user to enter choice
		cout << "Please enter your choice : ";
		cin >> userChoice;

		// return the appropriate input based on user choice
		switch (userChoice)
		{
		case 1:
			cout << "Enter x :";
			cin >> x;
			cout << endl;
			cout << "cos(x) = " << cosf(x) << endl << endl;
			break;
		case 2:
			cout << "Enter x :";
			cin >> x;
			cout << endl;
			cout << "sin(x) = " << sinf(x) << endl << endl;
			break;
		case 3:
			cout << "Enter x :";
			cin >> x;
			cout << endl;
			cout << "tan(x) = " << tanf(x) << endl << endl;
			break;
		case 4:
			cout << "Enter y :";
			cin >> y;
			cout << "Enter x :";
			cin >> x;
			cout << endl;
			cout << "atan2(y, x) = " << atan2f(y, x) << endl << endl;
			break;
		case 5:
			cout << "Enter x :";
			cin >> x;
			cout << endl;
			cout << "sqrt(x) = " << sqrtf(x) << endl << endl;
			break;
		case 6:
			cout << "Enter x :";
			cin >> x;
			cout << "Enter y :";
			cin >> y;
			cout << endl;
			cout << "x^y = " << powf(x, y) << endl << endl;
			break;
		case 7:
			cout << "Enter x :";
			cin >> x;
			cout << endl;
			cout << "ln(x) = " << logf(x) << endl << endl;
			break;
		case 8:
			cout << "Enter x :";
			cin >> x;
			cout << endl;
			cout << "e^x = " << expf(x) << endl << endl;
			break;
		case 9:
			cout << "Enter x :";
			cin >> x;
			cout << endl;
			cout << "|x| = " << fabs(x) << endl << endl;
			break;
		case 10:
			cout << "Enter x :";
			cin >> x;
			cout << endl;
			cout << "floor(x) = " << floorf(x) << endl << endl;
			break;
		case 11:
			cout << "Enter x :";
			cin >> x;
			cout << endl;
			cout << "ceil(x) = " << ceilf(x) << endl << endl;
			break;
		case 12:
			quit = true;
			cout << "Exiting..." << endl;
			break;
		default:
			// output a message if user enters an incorrect choice
			cout << "Sorry you have entered an invalid choice please try again.." << endl << endl;
			// ignore input that isn't numerical
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}