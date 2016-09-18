// include header files
#include <iostream>

// using declarations
using std::cout;
using std::cin;
using std::endl;

int main()
{
	// variables
	int* m_dynArray;
	int m_numbers = 0;
	float m_numInput = 0;
	float m_sum = 0;

	// output a message to the console
	cout << "How many numbers would you like to average: ";
	// store the users input
	cin >> m_numbers;

	// create a dynamic array
	m_dynArray = new int[m_numbers];

	//output some new lines
	cout << endl << endl;

	// simple loop to check we have correct amount of numbers
	for (int i = 1; i <= m_numbers; i++)
	{
		// output a message to the console
		cout << "Please enter the numbers to average " << i << " : ";
		// store the user input
		cin >> m_numInput;

		// add up the input and store it in sum
		m_sum += m_numInput;
	}

	// do the math
	m_numInput = m_sum / m_numbers;

	// output some newlines
	cout << endl << endl;

	// output the 'Average' to the console
	cout << "You chose " << m_numbers << " 'Numbers'" << endl;
	cout << "The 'Sum' of those " << m_numbers << " 'Numbers' was " << m_sum << endl;
	cout << "So the 'Average' of your : " << m_numbers << " 'Numbers' is " << m_numInput << endl;
	cout << "('Sum' / 'Numbers' = 'Average')" << endl << endl;

	// output a message to the console
	cout << "Press any key to exit the application" << endl;

	// clean up
	delete[] m_dynArray;
	m_dynArray = NULL;
	
	// ignore any user input for console instructions
	cin.ignore();
	// wait for a key press before exiting the console
	cin.get();
	// ensure we exit without error
	return 0;
}