#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// variables
	int m_Num;
	int m_Factorial = 1;

	// output a message to the console
	cout << "Enter a positive integer to compute the factorial of: ";
	cin >> m_Num;

	// Do the Math
	// e.g The factorial of 4 (4!) is:
	// 4! = 4x3x2x1 = 24
	for (int cnt = m_Num; cnt > 0; --cnt)
	{
		m_Factorial *= cnt;
	}

	// output a message to the console
	cout << "\nThe factorial of : " << m_Num << "! = " << m_Factorial << endl;

	cin.ignore();
	cin.get();
	return 0;
}