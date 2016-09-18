#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	char m_Ascii = 33;

	for (int i = 33; i <= 255; i++)
	{
		cout << i << ": " << m_Ascii << " ";
		m_Ascii = i + 1;
	}

	cin.ignore();
	cin.get();
	return 0;
}