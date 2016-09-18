// 
#include "Engineers.h"

// 
Engineers::Engineers()
{
	_bIsACPPMaster = "Yes";
	_numYearsExp = 7;
	_whatType = "Software engineer";
}

// 
Engineers::Engineers(std::string cppMaster, int numOfYears, std::string whatType)
{
	_bIsACPPMaster = cppMaster;
	_numYearsExp = numOfYears;
	_whatType = whatType;
}

// 
Engineers::~Engineers()
{

}

// 
void Engineers::EnterEngineerDetails(std::string cppMaster, int numOfYears, std::string whatType)
{
	// 
	_bIsACPPMaster = cppMaster;
	_numYearsExp = numOfYears;
	_whatType = whatType;

	// 
	std::cout << "Enter your choice fromt he list below\n";
	std::cout << "Have you a degree in C++ ? : ";
	std::getline(cin, cppMaster);

	// 
	std::cout << "Enter the number of years experience: ";
	std::cin >> numOfYears;

	// 
	std::cout << "Enter the type of engineer (e.g., mechanical): ";
	std::getline(cin, _whatType);
}

// 
void Engineers::SaveDB(std::ofstream & outputFile) const
{
	outputFile << "\t\t\tEmployee Details for the Engineers\n";
	outputFile << "\t\t\t------------------------------------\n\n";
	outputFile << "Employee name : " << GetFullEmployeeName() << "\n";
	outputFile << "Annual salary : " << _salary << "\n";
	outputFile << "C++ Degree ? : " << _bIsACPPMaster << "\n";
	outputFile << "How many years experience : " << _numYearsExp << "\n";
	outputFile << "What type of engineer are you ? : " << _whatType << "\n";
	std::cout << std::endl << std::endl;
}

// 
void Engineers::LoadDB(std::istream & inputFile) const
{
	// TO DO
}
