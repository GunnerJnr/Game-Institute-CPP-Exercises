// Map.cpp

#include "Map.h"
#include <iostream>
#include "Random.h"
using namespace std;

// Constructor, initialises the player's pos coords to the origin (player starts at pos (0,0))
Map::Map()
{
	// Player starts at origin (0, 0)
	mPlayerXPos = 0;
	mPlayerYPos = 0;
}

// Get the players X position
int  Map::getPlayerXPos()
{
	return mPlayerXPos;
}

// Get the players Y position
int  Map::getPlayerYPos()
{
	return mPlayerYPos;
}

// Prompt the user to choose a direction for the player too move, then update the position
void Map::movePlayer()
{
	int selection = 1;
	cout << "1) North, 2) East, 3) South, 4) West: ";
	cin >> selection;

	// Update coordinates based on selection.
	switch( selection )
	{
	case 1: // North
		mPlayerYPos++;
		break;
	case 2: // East
		mPlayerXPos++;
		break;
	case 3: // South
		mPlayerYPos--;
		break;
	default: // West
		mPlayerXPos--;
		break;
	}
	cout << endl;
}

// Check for random enemy encounters on the players roll of the dice
Monster* Map::checkRandomEncounter()
{
	// return a random number in the range for the player's roll
	int roll = Random(0, 20);

	// create a new instance of a monster object
	Monster* monster = 0;

	// if the roll is less than or equal too 5
	if( roll <= 5 )
	{
		// No encounter, return a null pointer.
		return 0;
	}
	// else if the roll is greater then or equal to 6 OR less than or equal to 10
	else if(roll >= 6 && roll <= 10)
	{
		// initialise a monster object
		monster = new Monster("Orc", 10, 8, 200, 1, "Short Sword", 2, 7);
		// and output a message to the player
		cout << "You encountered an Orc!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	// else if the roll is greater or equal to 11 OR les than or equal to 15
	else if(roll >= 11 && roll <= 15)
	{
		// initialise a monster object
		monster = new Monster("Goblin", 6, 6, 100, 0, "Dagger", 1, 5);
		// and output a message to the player
		cout << "You encountered a Goblin!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	// else if the roll is greater or equal to 16 OR les than or equal to 19
	else if(roll >= 16 && roll <= 19)
	{
		// initialise a monster object
		monster = new Monster("Ogre", 20, 12, 500, 2, "Club", 3, 8);
		// and output a message to the player
		cout << "You encountered an Ogre!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	// else if the roll is equal to 20
	else if(roll == 20)
	{
		// initialise a monster object
		monster = new Monster("Orc Lord", 25, 15, 2000, 5, "Two Handed Sword", 5, 20);
		// and output a message to the player
		cout << "You encountered an Orc Lord!!!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	// return the monster object
	return monster;
}

// Print the players position
void Map::printPlayerPos()
{
	// and output the players position (coords, e.g (3,5))
	cout << "Player Position = (" << mPlayerXPos << ", " << mPlayerYPos << ")" << endl << endl;
}