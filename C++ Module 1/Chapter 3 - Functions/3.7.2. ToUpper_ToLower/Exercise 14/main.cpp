#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// function prototypes
char ToUpperCase(char input);
char ToLowerCase(char input);

// main program entry point
int main()
{
	int Printendl = 0;
	for (unsigned int i = 33; i <= 255; ++i)
	{
		++Printendl;
		if (i >= 65 && i <= 90)
		{
			cout << i << ": " << ToLowerCase(char(i)) << " ";
		}
		else if (i >= 97 && i <= 122)
		{
			cout << i << ": " << ToUpperCase(char(i)) << " ";
		}
		cout << i << ": " << char(i) << " ";
		if (Printendl == 11)
		{
			cout << endl;
			Printendl = 0;
		}
	}
	cout << endl;

	cin.ignore();
	cin.get();
	return 0;
}

// ToUpperCase
char ToUpperCase(char input)
{
	for (int i = 65; i <= 90; ++i)
	{
		if (char(i) == input)
			input = char(i + 32);
	}
	return input;
}

// ToLowerCase
char ToLowerCase(char input)
{
	for (int i = 97; i <= 122; ++i)
	{
		if (char(i) == input)
			input = char(i - 32);
	}
	return input;
}