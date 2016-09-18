#ifndef _NAVIGATOR_H
#define _NAVIGATOR_H

// include header files
#include <iostream>
#include "vector2.h"

// using namespace declaration
using namespace std;

// Navigator Class
class Navigator
{
public:
	Navigator();
	~Navigator();
	void AskDirections();	// Ask the user which direction they want to go
	void PositionXY();		// output the new position(X,Y)

private:
	// private variables
	Vector2 m_XY;

	char userChoice;

	Vector2 m_North;
	Vector2 m_East;
	Vector2 m_South;
	Vector2 m_West;

	Vector2 result;			// create a new vector2 to store the result
};

#endif //!_NAVIGATOR_H