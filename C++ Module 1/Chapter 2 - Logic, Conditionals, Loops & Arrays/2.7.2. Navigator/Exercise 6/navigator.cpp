// include header files
#include "navigator.h"

// Constructor
Navigator::Navigator() :
m_XY(0, 0),
userChoice(' '),
m_North(0.0f, -1.0f),
m_East(1.0f, 0.0f),
m_South(0.0f, 1.0f),
m_West(-1.0f, 0.0f)
{

}
//-------------------------------------------------------

// Destructor
Navigator::~Navigator()
{

}
//-------------------------------------------------------

// AskDirections - Asks the user which direction they would like to go 
void Navigator::AskDirections()
{
	// output a message to the user
	cout << "Which direction do you want to go: " << endl;
	cout << "[N]orth, [E]ast, [S]outh, [W]est or [Q]uit : ";
	// store the users input
	cin >> userChoice;

	result;

	// simple switch statement checking against the users choice
	switch (userChoice)
	{
		// if the user selects north (supports upper and lower case)
	case 'N':
	case 'n':
		// output the chosen direction
		cout << "You went North" << endl;
		result = m_North;			// set the YPos of North to -1
		break;
		// if the user selects east (supports upper and lower case)
	case 'E':
	case 'e':
		// output the chosen direction
		cout << "You went East" << endl;
		result = m_East;			// set the XPos of East to 1
		break;
		// if the user selects south (supports upper and lower case)
	case 'S':
	case 's':
		// output the chosen direction
		cout << "You went South" << endl;
		result = m_South;			// set the YPos of South to 1
		break;
		// if the user selects west (supports upper and lower case)
	case 'W':
	case 'w':
		// output the chosen direction
		cout << "You went West" << endl;
		result = m_West;			// set the XPos of West to -1
		break;
		// if the user select this option we quit the program
	case 'Q':
	case 'q':
		return;
		// default case -
	default:
		// return a message telling the user they have entered an incorrect choice
		cout << "Sorry you have entered an invalid direction!" << endl;
		cout << "Please try again!" << endl;
	}
	//Calculate new position
	m_XY += result;

	// Call PositionXY Method to display the new position
	PositionXY();
}
//-------------------------------------------------------

// PositionXY -
void Navigator::PositionXY()
{
	// output the new XY positions
	cout << "Your new position is(X: " << m_XY.GetXPos() << ") (Y: " << m_XY.GetYPos() << ")" << endl;
	cout << endl;

	// Call this method so the user can enter another direction
	AskDirections();
}
//-------------------------------------------------------