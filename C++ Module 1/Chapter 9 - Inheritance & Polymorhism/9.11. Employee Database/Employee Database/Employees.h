#pragma once

// Include Header Files (Pre Processor directives)
#include <iostream>
#include <string>
#include <fstream>
#include<vector>

// namespaces
using namespace std;

// Create the main (Interface/Base/Parent Class)
class Employees
{
protected:
	// Stores the employees firstName 
	std::string _firstName;
	// Stores the employees lastName
	std::string _lastName;
	// Stores the employees annual salary
	double _salary;

public:
	// Constructor
	Employees();
	// Overloaded Constructor
	Employees(std::string, std::string, double);
	// Destructor
	virtual ~Employees();

	//========== Mutators ==========//

	// EnterEmployeeDetails
	void EnterEmployeeDetails(std::string, std::string, double);
	
	//========== Accessors ==========//

	// Return the full first and last name of the employees
	std::string GetFullEmployeeName() const;

	//========== Pure Virtuals (Must be overriden) ==========//

	// Write the data to file
	virtual void SaveDB(std::ofstream& outputFile) const = 0;
	// Read the data from the file
	virtual void LoadDB(std::istream& inputFile) const = 0;
};
