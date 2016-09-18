#pragma once

// Include Header Files (Pre Processor Directives)
#include "Employees.h"

// Create the main research class which is Derived/Inherited/Child of the Employees Class
class Researchers : public Employees
{
protected:
	std::string _schoolName;
	std::string _subjectChosen;

public:
	// Constructor
	Researchers();
	// Overloaded Constructor
	Researchers(std::string, std::string);
	// Destructor
	virtual ~Researchers();

	//========== Mutators ==========//

	// Ask the employee for their research details
	void EnterResearchDetails(std::string, std::string);

	//========== These must be overriden from the employees class ==========//

	// Write the data to file
	void SaveDB(std::ofstream& outputFile) const;
	// Read the data from the file
	void LoadDB(std::istream& inputFile) const;
};