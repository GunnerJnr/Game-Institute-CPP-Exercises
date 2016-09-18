#include <iostream>
#include <Windows.h>
#include <stdlib.h>	
#include <time.h>	

using std::cout;
using std::cin;
using std::endl;

// defines
#define _DEBUG_MODE
//#define _RELEASE_MODE
#define NUMS_TO_SORT 10
#define MIN -100
#define MAX 100

// globals
int m_storeValue = 0;
int m_tempValue = 0;

// function prototypes
int GetRandomNumber();
void ProgramSleep();

#ifdef _DEBUG_MODE
int main()
{
	// seed random numbers from system time
	srand((unsigned int)time(NULL));

	// variables
	int m_randomInput[NUMS_TO_SORT];

	// output a message to the console
	cout << "Please wait, choosing 10 unsorted integer numbers...";
	// Call sleep function
	ProgramSleep();

	// output a message to the console
	cout << "Inputting the 10 unsorted integer numbers..." << endl << endl;
	// loop through until the user has entered 10 numbers
	for (int i = 0; i < NUMS_TO_SORT; ++i)
	{
		// output i + 1 (e.g 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) 
		// as arrays are 0 indexed this makes it more human friendly
		cout << "[" << i + 1 << "] : ";
		m_randomInput[i] = GetRandomNumber();
		cout << m_randomInput[i] << endl;
		Sleep(750);
	}
	cout << endl << endl;

	// output the users unsorted list 
	cout << "Unsorted list of integers { ";

	// loop through our array
	for (int i = 0; i < NUMS_TO_SORT; ++i)
	{
		// and output the users values
		cout << m_randomInput[i];

		// check if we are not equal to the final element of the array
		if (i != NUMS_TO_SORT - 1)
		{
			// if we are not then output a comma after each number
			cout << ", ";
		}
		else
		{
			// otherwise we have hit the end so output the closing brace.
			cout << " }" << endl << endl;
		}
	}

	// output a message to the console
	cout << "Sorting the list of integers please wait...";
	// Call sleep function
	ProgramSleep();

	// loop through the elements of the array
	for (int i = 0; i < NUMS_TO_SORT; ++i)
	{
		// assign the array elements to the storeValue Variable
		m_storeValue = m_randomInput[i];

		// loop through the elements again, but this time we say
		// if j is equal to 0 + the value of i
		for (int j = 0 + i; j < NUMS_TO_SORT; ++j)
		{
			// now we check if the current element in j is less than that stored
			// currently in storeValue, if it is we..
			if (m_randomInput[j] < m_storeValue)
			{
				// assign the value of storeValue to tempValue
				m_tempValue = m_storeValue;
				// now assign the j element to the storeValue variable
				m_storeValue = m_randomInput[j];
				// next assign the value in tempValue 
				m_randomInput[j] = m_tempValue;
			}
		}
		// and then move it to the new position in the array
		m_randomInput[i] = m_storeValue;
	}

	// output the newly sorted list
	cout << "The integers have now been sorted { ";

	// loop through our array
	for (int i = 0; i < NUMS_TO_SORT; ++i)
	{
		// and output the users values
		cout << m_randomInput[i];

		// check if we are not equal to the final element of the array
		if (i != NUMS_TO_SORT - 1)
		{
			// if we are not then output a comma after each number
			cout << ", ";
		}
		else
		{
			// otherwise we have hit the end so output the closing brace.
			cout << " }" << endl << endl;
		}
	}

	// output a message t the console
	cout << "press any key to exit the program...";

	cin.ignore();
	cin.get();
	return 0;
}
#endif // _DEBUG_MODE

#ifdef _RELEASE_MODE
int main()
{
	// variables
	int m_userSelections[NUMS_TO_SORT];

	// output a message to the console
	cout << "Please enter 10 unsorted integer numbers" << endl << endl;

	// loop through until the user has entered 10 numbers
	for (int i = 0; i < NUMS_TO_SORT; ++i)
	{
		// output i + 1 (e.g 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) 
		// as arrays are 0 indexed this makes it more human friendly
		cout << "[" << i + 1 << "] : ";
		// store the users inputs
		cin >> m_userSelections[i];
	}
	cout << endl << endl;

	// output the users unsorted list 
	cout << "Your unsorted list of integers { ";

	// loop through our array
	for (int i = 0; i < NUMS_TO_SORT; ++i)
	{
		// and output the users values
		cout << m_userSelections[i];

		// check if we are not equal to the final element of the array
		if (i != NUMS_TO_SORT - 1)
		{
			// if we are not then output a comma after each number
			cout << ", ";
		}
		else
		{
			// otherwise we have hit the end so output the closing brace.
			cout << " }" << endl << endl;
		}
	}

	// output a message to the console
	cout << "Sorting your list of integers please wait...";
	// Call sleep function
	ProgramSleep();

	// loop through the elements of the array
	for (int i = 0; i < NUMS_TO_SORT; ++i)
	{
		// assign the array elements to the storeValue Variable
		m_storeValue = m_userSelections[i];

		// loop through the elements again, but this time we say
		// if j is equal to 0 + the value of i
		for (int j = 0 + i; j < NUMS_TO_SORT; ++j)
		{
			// now we check if the current element in j is less than that stored
			// currently in storeValue, if it is we..
			if (m_userSelections[j] < m_storeValue)
			{
				// assign the value of storeValue to tempValue
				m_tempValue = m_storeValue;
				// now assign the j element to the storeValue variable
				m_storeValue = m_userSelections[j];
				// next assign the value in tempValue 
				m_userSelections[j] = m_tempValue;
			}
		}
		// and then move it to the new position in the array
		m_userSelections[i] = m_storeValue;
	}

	// output the newly sorted list
	cout << "Your integers have been sorted { ";

	// loop through our array
	for (int i = 0; i < NUMS_TO_SORT; ++i)
	{
		// and output the users values
		cout << m_userSelections[i];

		// check if we are not equal to the final element of the array
		if (i != NUMS_TO_SORT - 1)
		{
			// if we are not then output a comma after each number
			cout << ", ";
		}
		else
		{
			// otherwise we have hit the end so output the closing brace.
			cout << " }" << endl << endl;
		}
	}	

	// output a message t the console
	cout << "press any key to exit the program...";

	cin.ignore();
	cin.get();
	return 0;
}
#endif // _RELEASE_MODE

// function to return a random number
int GetRandomNumber()
{
	return rand() % (MAX + 1 - MIN) + MIN;
}

//
void ProgramSleep()
{
	// while true (output the effect of a loading bar for the sorting)
	while (true)
	{
		Sleep(750);
		std::cout << "." << std::flush;
		Sleep(750);
		std::cout << "." << std::flush;
		Sleep(750);
		std::cout << "." << std::flush;
		Sleep(750);
		std::cout << "\b\b\b   \b\b\b" << std::flush;
		Sleep(750);
		break;
	}
	cout << endl << endl;
}