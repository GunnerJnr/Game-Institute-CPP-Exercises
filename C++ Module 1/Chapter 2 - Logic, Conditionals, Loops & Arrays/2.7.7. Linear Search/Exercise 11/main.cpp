#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// variables
#define ELEMENTS 17
	int m_ArrayValues[ELEMENTS] = { 7, 3, 32, 2, 55, 34, 6, 13, 29, 22, 11, 9, 1, 5, 42, 39, 8 };
	int m_NumToSearch = 0;
	int m_NumIndexPosition = 0;

	//output a message to the console
	cout << "Number List: ";

	// loop through the array elements
	for (int i = 0; i < ELEMENTS; i++)
	{
		// output the elements of the array
		cout << m_ArrayValues[i];

		// if i is less than the no. of elements - 1
		if (i < ELEMENTS - 1)
		{
			// output a comma after each element
			cout << ", ";
		}
		// other
		else
		{
			// output a new line
			cout << endl;
		}
	}

	// output a message to the console
	cout << "\nEnter an integer in the list to search for: ";
	// store users choice
	cin >> m_NumToSearch;

	// loop through the array elements
	for (int i = 0; i < ELEMENTS; i++)
	{
		// if the num to search for is equal to the value in the array element
		if (m_NumToSearch == m_ArrayValues[i])
		{
			// assign the value of i to the elements index position
			m_NumIndexPosition = i;
		}
	}

	// output a message stating the position(index) at which the element was found
	// NOTE: we add 1 (m_NumIndexPosition + 1) to perceive that the array starts at index 1
	// of course from a programmers view arrays start at index 0, this just makes it more
	// natural to a user who may not know arrays are 0 index based.
	cout << "\nItem found at index [" << m_NumIndexPosition + 1 << "]" << endl << endl;

	// output a message tot he console
	cout << "Press any key to exit..." << endl;

	cin.ignore();
	cin.get();
	return 0;
}