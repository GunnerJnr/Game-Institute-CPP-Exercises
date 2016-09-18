// Include Header Files (Pre Processor Directives)
#include "Employees.h"

// Deafult Constructor
Employees::Employees()
{
	// Initialise the member variables to some default values
	_firstName = "Joe";
	_lastName = "Bloggs";
	_salary = 17.250;
}

// Overloaded Constructor
Employees::Employees(std::string firstName, std::string lastName, double salary)
{
	// Initialise the member variables
	_firstName = firstName;
	_lastName = lastName;
	_salary = salary;

	// Call on our method that fetches the employee details
	EnterEmployeeDetails(firstName, lastName, salary);
}

// Destructor
Employees::~Employees()
{
	// release and give back memory
}

// Enter the employee details (first and last name and salary)
void Employees::EnterEmployeeDetails(std::string firstName, std::string lastName, double salary)
{
	// Initialise the member variables
	_firstName = firstName;
	_lastName = lastName;
	_salary = salary;

	// output a message to the employee asking them to enter their firstName
	std::cout << "Enter your first name : ";
	std::getline(std::cin, firstName);
	// output a message to the employee asking them to enter their lastName
	std::cout << "Enter your last name : ";
	std::getline(std::cin, lastName);
	// output a message to the employee asking them to enter their salary
	std::cout << "Enter your annual salary : ";
	std::cin >> salary;
}

// Get the full employee name
std::string Employees::GetFullEmployeeName() const
{
	// Return the firstName and lastName entered by the employees from the DB
	return _firstName + " " + _lastName;
}
