// Employee Database - Game Institute Exercise 9.11
// Project Created on 09/01/2016
// Programmer: David Gunner Jnr
// Email: gunnerjnr@live.co.uk
// Website: http://gunnerjnr.uk

// Include Header files (Pre Processor Directives)

//========== Class Headers Files ==========//

#include "Employees.h"
#include "Managers.h"
#include "Engineers.h"
#include "Researchers.h"

//========== namespaces ==========//

using namespace std;

//========== Variables ==========//

// Create a new vector instance of our employees class
std::vector<Employees*> employees;

//========== Function Prototypes for main.cpp ==========//

// Intro message for program begin
void Intro();
// This function will use an std::vector for adding employees to our database
void AddEmployeesToDB(std::vector<Employees*>& employees);
// This function will use an std::vector for deleting employees to our database
void DeleteEmployeesFromDB(std::vector<Employees*>& employees);
// This function will use an std::vector for saving employees to our database file
void SaveEmployeesToDBFile(std::vector<Employees*>& employees);
// This function will use an std::vector for loading employees from our database file
void LoadEmployeesFromDBFile(std::vector<Employees*>& employees);
// Employee DB Main Menu
void DBMainMenu();


// Main program entry point
int main()
{
	// Call on our intro function
	Intro();

	// Call on our function to present the main menu to the employees
	DBMainMenu();

	// iterate through each array element
	for (size_t DB = 0; DB < employees.size(); ++DB)
	{
		// free and release the memory [delete the elements of the array)
		delete employees[DB];
	}

	// ensure we exit without error
	return 0;
}

//========== Function Declarations for main.cpp (Mutators) ==========//

// Usually this would be part of a proper class but as we dont need anything else with it
// I thought I would just quickly chuck it here for ease of use. It just prints the program intro
void Intro()
{
	std::cout << "\n\n\t\tWelcome to the Employee Database Program 1.0\n";
	std::cout << "\tWe are part of Megacorp, Bringing you a better online future!!!\n";
	std::cout << "\t=======================================================\n\n";
}

// Employee DB Main Menu
void DBMainMenu()
{
	// Create 2 local variables to store the users choice and if the application is running or not
	bool bHasQuit = false;
	int userChoice = 0;

	// While the application is running..
	while (!bHasQuit)
	{
		// output the main menu choices to the employees
		cout << "Please enter your choice from the list below\n";
		cout << "[1] Add Employee to DB\n"
			<< "[2] Delete Employee from DB\n"
			<< "[3] Save DB to file\n"
			<< "[4] Load DB from file\n"
			<< "[5] Exit\n"
			<< "Enter Choice: ";
		cin >> userChoice;

		// Check for the menu choice and return the appropriate method
		switch (userChoice)
		{
			// Add employee to DB
		case 1:
			AddEmployeesToDB(employees);
			break;
			// Delete employee from DB
		case 2:
			DeleteEmployeesFromDB(employees);
			break;
			// Save DB to file
		case 3:
			// Save Employees to DB file
			SaveEmployeesToDBFile(employees);
			break;
			// Load DB from file
			LoadEmployeesFromDBFile(employees);
		case 4:
			// Load Employees from DB file
			break;
			// Exit the program
		case 5:
			// set has quit to true
			bHasQuit = true;
			break;
		}
	}
}

// This function will use an std::vector for adding employees to our database
void AddEmployeesToDB(std::vector<Employees*>& employees)
{
	// Create a local variable to store the value of the users choice
	int userChoice = 0;

	// Ask the employee to choose from the list below
	cout << "Please enter the employee's role from the list below\n";
	cout << "[[1] Managers, [2] Engineers, [3] Researchers]: ";
	cin >> userChoice;

	// Check what the user choice was and return the appropriate action
	switch (userChoice)
	{
		// Add to manager's
	case 1:
		employees.push_back(new Managers);
		break;
		// Add to enginner's
	case 2:
		employees.push_back(new Engineers);
		break;
		// add to researcher's
	case 3:
		employees.push_back(new Researchers);
		break;
	}
}

// This function will use an std::vector for deleting employees to our database
void DeleteEmployeesFromDB(std::vector<Employees*>& employees)
{
	// Create a local variable to store the full name of the user to be deleted
	std::string fullName;

	// Ask for the name of the employee to delete
	cout << "Enter the first and last name of the employee to remove: ";
	getline(cin, fullName);

	// iterate thruough the database and check..
	for (size_t DB = 0; DB < employees.size(); ++DB)
	{
		// if the name entered is equal to a name in the database
		if (fullName == employees[DB]->GetFullEmployeeName())
		{
			// if it is delete them from the database
			delete employees[DB];
			employees.erase(employees.begin() + DB);
			break;
		}
	}
}

// This function will use an std::vector for saving employees to our database file
void SaveEmployeesToDBFile(std::vector<Employees*>& employees)
{
	// Create our output file that will store all of our employee database 
	ofstream outputFileTxt("EmployeeDB.txt"); // (we have chosen a txt format here)

											  // iterate through our database
	for (size_t DB = 0; DB < employees.size(); ++DB)
	{
		// and save each employee to our file
		employees[DB]->SaveDB(outputFileTxt);
	}
	// we have finished now close the file from writing
	outputFileTxt.close();
}

// This function will use an std::vector for loading employees from our database file
void LoadEmployeesFromDBFile(std::vector<Employees*>& employees)
{
	// TO DO
}