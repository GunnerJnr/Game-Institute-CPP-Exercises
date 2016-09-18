// includes
#include <iostream>

// using std's
using std::cout;
using std::cin;
using std::endl;

// globals
bool quit = false;
int searchKey = 0;
int posInArray = 0;
int testArray[] = { 1, 4, 5, 6, 9, 14, 21, 23, 28, 31, 35, 42, 46, 50, 53, 57, 62, 63, 65, 74, 79, 89, 95 };
int numElements = (sizeof(testArray) / sizeof(*testArray));

// function prototypes
int BinSearch(int data[], int numElements, int searchKey);
void PrintTestArray();
void Menu();

// main program entry point
int main()
{
	// Call the menu function
	Menu();

	cin.get();
	cin.ignore();
	return 0;
}

// Function to sort the Binary Search
int BinSearch(int data[], int numElements, int searchKey)
{
	// local variables
	int firstElement = 1;
	int middlePos = 0;
	int middleElement = data[middlePos];
	int lastElement = numElements;

	// Find the center element of the array
	middlePos = (firstElement + lastElement) / 2;

	// while the 1st element is less than equal to the last element
	// and the data in the middle position is not equal to the search key
	while (firstElement <= lastElement && data[middlePos] != searchKey)
	{
		// if search key is greater than that of the middle position
		if (searchKey > data[middlePos])
		{
			// set the first element to the middle position + 1
			firstElement = middlePos + 1;
		}
		// otherwise
		else
		{
			// set the last element to the middle pos - 1
			lastElement = middlePos - 1;
		}
		// Find the center element of the array
		middlePos = (firstElement + lastElement) / 2;
	}
	// return the middle position
	return middlePos;
}

// Function to print the menu to the user
void Menu()
{
	// output a message
	cout << "\t\t\t\t==================" << endl;
	cout << "\t\t\t\tBinary Search V1.0" << endl;
	cout << "\t\t\t\t==================" << endl << endl;

	// Call the print test array function
	PrintTestArray();

	// output a message
	cout << "Enter Search Key or Press [X] to Exit : ";
	cin >> searchKey;
	cout << endl;

	// while we have not quit the program
	while (!quit)
	{
		// if we are not search for a key
		if (!searchKey)
		{
			// set quit to true (and quit the program)
			quit = true;
			break;
		}
		else
		{
			// assign the data to position in array
			posInArray = BinSearch(testArray, numElements, searchKey);

			// if the position in the array is not equal to zero
			if (posInArray != 0)
			{
				// display that the search key was found and in what position
				cout << searchKey << " is in position [" << posInArray + 1 << "] of the Array. " << endl << endl;
				break;
			}
			// otherwise
			else
			{
				// output a message stating the search key wasn't found
				cout << "Sorry " << searchKey << " is not found." << endl << endl;
				break;
			}
		}
	}
}

// Print the test array to the console
void PrintTestArray()
{
	// loop and print all the array elements
	cout << "\t{";
	for (int i = 0; i < numElements; ++i)
	{
		cout << testArray[i];
		
		// if were not at the last element
		if (i != numElements - 1)
		{
			// print a comma after each 
			cout << ",";
		}
		// otherwise
		else
		{
			// print end curly brace
			cout << "}";
		}
	}
	// output some new lines
	cout << endl << endl;
}
