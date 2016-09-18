// game.cpp

#include "Map.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// main program entry point
int main()
{
	//  seed the random number generator
	srand( (unsigned int) time(0) );

	// instantiate a map object called gameMap
	Map gameMap;

	// instantiate a player object called mainPlayer
	Player mainPlayer;

	// execute the character class creation by calling the createClass method for the mainPlayer
	mainPlayer.createClass();

	// Begin the main game loop, will execute until the player quits or dies
	// Begin adventure.
	bool done = false;
	while( !done )
	{
		// Each loop cycly we output the player position and 
		gameMap.printPlayerPos();
		// a selection menu, which we execute different code paths depending on the players choice
		int selection = 1;
		cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
		cin >> selection;

		// instantiate a new monster object (pointer)
		Monster* monster = 0;
		switch( selection )
		{
		case 1:
			// Move the game player, promopts the user to enter the direction they wish to go
			gameMap.movePlayer();

			// Check for a random encounter.  This function returns a null pointer if no monsters are
			// encountered.
			monster = gameMap.checkRandomEncounter();

			// 'monster' not null, run combat simulation.
			if( monster != 0 )
			{
				// Loop until a 'break' statement.
				while( true )
				{
					// Display hitpoints for player and monster for every loop cycle
					mainPlayer.displayHitPoints();
					monster->displayHitPoints();
					cout << endl;

					// Player's turn to attack first
					bool runAway = mainPlayer.attack(*monster);

					// if the player chooses to run away
					if( runAway )
						break;	// break out of the combat loop

					// if the player attacked and killed the monster
					if( monster->isDead() )
					{
						// execute the victory message, give the xp reward
						mainPlayer.victory(monster->getXPReward(), monster->getGoldReward());
						// and check to see if the player gained enough xp to level up
						mainPlayer.levelUp();
						break;
					}

					// if the monster did not die from the players attack, then it is the 
					// monsters turn to attack the player
					monster->attack(mainPlayer);

					// if the attack kills the player
					if( mainPlayer.isDead() )
					{
						// execute the game over message
						mainPlayer.gameover();
						// exit the game loop
						done = true;
						break;
					}
				}

				// The pointer to a monster returned from checkRandomEncounter was allocated with
				// 'new', so we must delete it to avoid memory leaks.
				delete monster;
				monster = 0;	// set it to null to be safe
			}

			break;
		case 2:
			// if the player chose to rest, call the rest method
			mainPlayer.rest();
			break;
		case 3:
			// if the player chose to view stats, call the viewStats method
			mainPlayer.viewStats();
			break;
		case 4:
			// if the player chose to exit, terminate the game loop
			done = true;
			break;
		}
	}	
}