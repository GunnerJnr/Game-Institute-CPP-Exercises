#pragma once

// Include Directives (Pre Processor Directives)
#include "Employees.h"

// Create the Main Manager class which is Derived/Inherited/Child of the Employees Class
class Managers : public Employees
{
protected:
	int _numOfMeetings;
	int _numOfDaysHoliday;

public:
	// Constructor
	Managers();
	// Overloaded Constructor
	Managers(int, int);
	// Destructor
	virtual ~Managers();

	//========== Mutators ==========//

	// Ask the employee for their details
	void EnterManagerDetails(int, int);

	//========== These must be overriden from the employees class ==========//

	// Write the data to file
	void SaveDB(std::ofstream& outputFile) const;
	// Read the data from the file
	void LoadDB(std::istream& inputFile) const;
};