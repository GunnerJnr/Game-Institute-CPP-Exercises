#pragma once

// Include Header Files (Pre Processor Directives)
#include "Employees.h"

// Create the main class for Engineers which is Derived/Inherited/Child of the Employees Class
class Engineers : public Employees
{
protected:
	std::string _bIsACPPMaster;
	int _numYearsExp;
	std::string _whatType;

public:
	// Constructor
	Engineers();
	// Overloaded constructor
	Engineers(std::string, int, std::string);
	// Destructor
	virtual ~Engineers();

	//========== Mutators ==========//

	// Ask the employee for their research details
	void EnterEngineerDetails(std::string, int, std::string);

	//========== These must be overriden from the employees class ==========//

	// Write the data to file
	void SaveDB(std::ofstream& outputFile) const;
	// Read the data from the file
	void LoadDB(std::istream& inputFile) const;
};