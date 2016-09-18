// Map.h

#ifndef MAP_H
#define MAP_H

#include "Weapon.h"
#include "Monster.h"
#include <string>

class Map
{
public:
	// Constructor, initialises the player's pos coords to the origin (player starts at pos (0,0))
	Map();

	// Methods

	// accessor method, returns the current x coord of the player
	int  getPlayerXPos();

	// accessor method, returns the current y coord of the player
	int  getPlayerYPos();

	// keep track of the players pos, is called when the player wnats to move
	// prompts the user to enter his/her choice of direction and then move and 
	// update the position/coordinates accordingly.
	void movePlayer();

	// generates a random number in the range [0, 20]
	// (Depending on which sub range in which the generated number falls, a different 
	// encounter takes place (e.g a different monster is encountered)
	/*
	/* Range [0,5] - The player encounters no enemy
	/* Range [6,10] - The player encounters an orc
	/* Range [11,15] - The player encounters a goblin
	/* Range [16,19] - The player encounters an ogre
	/* Range [20] - The player encounters an orc lord
	*/
	// consists mainly of checking which range we fall in and creating the appropriate monster
	Monster* checkRandomEncounter();

	// between battles and moving (the main menu if you like), we display the player's current 
	// position on the map
	void printPlayerPos();

private:
	// Data members.
	int mPlayerXPos;		// The X-Coodrinate of the player
	int mPlayerYPos;		// The Y-Coordinate of the player
};

#endif //MAP_H