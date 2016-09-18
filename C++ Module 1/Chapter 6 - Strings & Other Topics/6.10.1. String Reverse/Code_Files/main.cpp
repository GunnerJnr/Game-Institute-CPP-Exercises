//======================================================================================
// Game Institute - C++ Module 1 Textbook Exercises
// Main.cpp The main Program Entry point.
// Exercise 6.10.1 - String Reverse
// TODO: -  
//			Write a program that does the following:
//				1. Ask the user to enter up to a line of text and store it in a string s.
//				2. Reverse the string s.
//				3. Output the reversed string to the console window.
//
// Your program output should be formatted as follows:
//
/*
	Enter a string: Hello, World!
	Reversed string = !dlroW ,olleH
	Press any key to continue
*/
//======================================================================================

// include directives
#include<iostream>
#include<string>		// std::string

// using directives
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::reverse;
using std::getline;

/// NOTE: - We could just put using namespace std; to achieve the same results.

// Create our own reverse string method
void ReverseString(string& str)
{
	// find the length of the string entered
	int stringLength = str.length() - 1;

	// Create and initialise two string variables
	string userString = "";
	string reversedString = "";

	// check to see if we have reached the end of the entered string, if we have then 
	// output the string in reverse order
	for (int cnt = stringLength; cnt >= 0; --cnt)
	{
		// assign the value of each array element to the userString variable
		userString = str[cnt];
		// assign the of reversedString and userString (e.g hello would be o l l e h (a letter per loop))
		reversedString = reversedString + userString;
	}

	// output the reversed string to the console window
	cout << "Your 1st string reversed is : " << reversedString << endl;
}

// ReverseStringTwo - This does the same as above but it utilises the built in reverse function
void ReverseStringTwo(string& str)
{
		// Here we call the std::reverse(first,last); method to reverse the userString
	// void reverse (BidirectionalIterator first, BidirectionalIterator last);
	reverse(str.begin(), str.end());

	// output the reversed string to the console window
	cout << "Your 2nd string reversed is : " << str << endl;
}

// main program entry point
int main()
{
	// Create a string to store the string the user has entered
	string str, str2;

	// Output to the console window
	cout << "Please enter a string: ";
	// we use getline in case the user enters multiple strings and store the input
	getline(cin, str);
	// Output to the console window
	cout << "Please enter another string: ";
	// we use getline in case the user enters multiple strings and store the input
	getline(cin, str2);

	// Call our 1st reverse string method
	ReverseString(str);
	// Call out 2nd reverse string method
	ReverseStringTwo(str2);	

	// output a message telling the user to press a key to exit the program
	cout << "Press any key to continue.." << endl;

	// ignore user input (for keeping the console window open)
	cin.get();
	cin.ignore();
	// ensure we exit without error
	return 0;
}