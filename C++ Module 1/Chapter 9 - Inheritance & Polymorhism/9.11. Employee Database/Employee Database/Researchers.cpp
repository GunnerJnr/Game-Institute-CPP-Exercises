// 
#include "Researchers.h"

// 
Researchers::Researchers()
{
	//
	_schoolName = "";
	_subjectChosen = "";
}

// 
Researchers::Researchers(std::string school, std::string subject)
{
	//
	_schoolName = school;
	_subjectChosen = subject;

	//
	EnterResearchDetails(school, subject);
}

// 
Researchers::~Researchers()
{
	// delete and free memory
}

// 
void Researchers::EnterResearchDetails(std::string school, std::string subject)
{
	//
	_schoolName = school;
	_subjectChosen = subject;

	// 
	std::cout << "Enter the name of the school you attended: ";
	std::getline(cin, school);

	//
	std::cout << "Enter the chosen subject: ";
	std::getline(cin, subject);
}

// 
void Researchers::SaveDB(std::ofstream & outputFile) const
{
	outputFile << "\t\t\tEmployee Details for the Researchers\n";
	outputFile << "\t\t\t------------------------------------\n\n";
	outputFile << "Employee name: " << GetFullEmployeeName() << "\n";
	outputFile << "Annual salary : " << _salary << "\n";
	outputFile << "School attended : " << _schoolName << "\n";
	outputFile << "Subject chosen : " << _subjectChosen << "\n";
	std::cout << std::endl << std::endl;
}

// 
void Researchers::LoadDB(std::istream & inputFile) const
{
	// TO DO 
}
