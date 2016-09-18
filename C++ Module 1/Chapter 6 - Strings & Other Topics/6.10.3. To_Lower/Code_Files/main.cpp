//======================================================================================
// Game Institute - C++ Module 1 Textbook Exercises
// Main.cpp The main Program Entry point.
// Exercise 6.10.2 - To-Upper
// TODO: -  1. Ask the user to enter up to a line of text and store it in string s.
//			2. Transform each alphabetical character into s into its lowercase form. If a 
//			   Character is not an alphabetical character, do not modify it.
//			3. Output the lowercase string to the console window.
//
// Your program output should be formatted as follows:
//
/*
Enter a string: HELLO, WORLD!
Uppercase string = Hello, World!
Press any key to continue..
*/
//======================================================================================

// include directives
#include<iostream>
#include<string>
#include<algorithm>

// using directives
using std::cout;
using std::cin;
using std::endl;
using std::string;

/// NOTE: - We could just put using namespace std; to achieve the same results.

// Functions/Methods

// main program entry point
int main()
{
	// variables
	string s = "";

	// Output to the console window
	cout << "Please enter a string :";
	getline(cin, s);

	// Transform each letter of the string to lowercase
	// If not an alphabetical character don't modify it
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	// output the result to the console (e.g. if user put HELLO, we return Hello,)
	cout << "\nLowercase string : " << s;

	// output a message telling the user to press a key to exit the program
	cout << "\n\nPress any key to continue.." << endl;

	// ignore user input (for keeping the console window open)
	cin.get();
	//cin.ignore();
	// ensure we exit without error
	return 0;
}