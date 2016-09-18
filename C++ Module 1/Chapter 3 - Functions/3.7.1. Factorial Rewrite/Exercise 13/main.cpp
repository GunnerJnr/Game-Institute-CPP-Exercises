#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// function prototypes
int Factorial(int m_num, int m_factorial = 1);

int main()
{
	// variables
	int m_Num = 0;

	// output a message to the console
	cout << "Enter a positive integer to compute the factorial of: ";
	cin >> m_Num;

	Factorial(m_Num);

	// output a message to the console
	cout << "\nThe factorial of : " << m_Num << "! = " << Factorial(m_Num) << endl << endl;
	cout << "Press any key to exit the program..." << endl << endl;

	cin.ignore();
	cin.get();
	return 0;
}

// Factorial Function
int Factorial(int m_num, int m_factorial)
{
	// Do the Math
	// e.g The factorial of 4 (4!) is:
	// 4! = 4x3x2x1 = 24
	for (int cnt = m_num; cnt > 0; --cnt)
	{
		m_factorial *= cnt;
	}

	return m_factorial;
}