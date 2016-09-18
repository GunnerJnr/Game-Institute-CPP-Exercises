// Include Directives (Pre Processor Directives)
#include "Managers.h"

// Constructor
Managers::Managers()
{
	// Initialise the member variables to some default values
	_numOfMeetings = 10;
	_numOfDaysHoliday = 22;
}

// Overloaded Constructor
Managers::Managers(int meetings, int daysHoliday)
{
	// Initialise the member variables
	_numOfMeetings = meetings;
	_numOfDaysHoliday = daysHoliday;

	// Call on our function to ask the user for their details
	EnterManagerDetails(meetings, daysHoliday);
}

// Destructor
Managers::~Managers()
{
	// free and release memory
}

// Enter Manager Details
void Managers::EnterManagerDetails(int meetings, int daysHoliday)
{
	// Initialise the member variables
	_numOfMeetings = meetings;
	_numOfDaysHoliday = daysHoliday;

	// Ask the employee to enter their number of meetings
	cout << "Enter the number of meetings you have : ";
	cin >> meetings;

	// Ask the employee to enter their number of number of days holiday remaining
	cout << "Enter the number of days holiday you have left : ";
	cin >> daysHoliday;
}

// Save DB to file
void Managers::SaveDB(std::ofstream & outputFile) const
{
	// output the managers details to file
	outputFile << "\t\t\tEmployee Details for the Managers\n";
	outputFile << "\t\t\t---------------------------------\n\n";
	outputFile << "Employee name : " << GetFullEmployeeName() << "\n";
	outputFile << "Annual salary : " << _salary << "\n";
	outputFile << "Number of meetings : " << _numOfMeetings << "\n";
	outputFile << "Number of days holiday remaining : " << _numOfDaysHoliday << "\n";
	std::cout << std::endl << std::endl;
}

// Load DB from file
void Managers::LoadDB(std::istream & inputFile) const
{
	// TO DO 
}
