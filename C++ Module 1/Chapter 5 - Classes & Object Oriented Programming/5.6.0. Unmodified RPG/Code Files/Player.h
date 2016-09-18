// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Monster.h"
#include <string>

class Player
{
public:
	// Default Constructor
	// Initialises the data members to default values
	Player();

	// Methods

	// returns true if the player is dead, otherwise returns false
	// (player is defined dead if hp <= 0)
	bool isDead();

	// accessor method, returns a copy of the mArmor data member
	int  getArmor();

	// called when a monster hits a player
	// The param specifies the amount of damage for which the player was hit, this indicates
	// how many hit points should be subtracted from the player
	void takeDamage(int damage);


	// This method is used to execute code that performs the character generation process.
	// It 1st asks the user to enter a name for their character, then to select the class that player will be,
	// then based on the class chosen, the properties of the player are filled out accordingly
	void createClass();
	
	// essentially the same as the monster attack method, but has one IMPORTANT difference, that is
	// we give the player an option of what to do on his attack turn (e.g Stay and fight .. ? or run, can also be extended..)
	bool attack(Monster& monster);

	// tests whether or not the player has acquired enough xp points to level up.
	// called after every battle (to check xp points), if the player has gained enough, then 
	// some of the players stats (i.e hit points and accuracy) are randomly increased.
	void levelUp();

	// called when the player chooses to rest, currently it increases the players hit points to maximum (useful for after a battle),
	// can add the possibility of random enemy encounters during rest or other events if you wish!!...
	void rest();

	// display the players stats
	void viewStats();

	// displayed after a player wins battle, a victory message is displayed and gives the player an xp point reward
	void victory(int xp);

	// called if the player died in battle, displays a "Game Over" message and asks the user to press 'q' to quit the game
	void gameover();

	// outputs the player's hit points to the console, used in game during battles, this is so the player may see how many hit points are remaining
	void displayHitPoints();
 
private:
	// Data members.
	std::string mName;				// The name of the player
	std::string mClassName;			// The player class type (e.g if wizard - "Wizard" would be the class)
	int         mAccuracy;			// An int value used to dertermine the probability of a player hitting or missing a monster
	int         mHitPoints;			// An int the displays the current number of hit points the player has
	int         mMaxHitPoints;		// An int that describes the max num of hit points the player can currently have
	int         mExpPoints;			// An int that describes the number of xp points the player has
	int         mNextLevelExp;		// An int that describes the number of xp points the player needs to reach the next level
									// in terms of the players current level (that is : mNextLevelExp = mLevel * mLevel * 1000; )
	int         mLevel;				// An int that decribes the current level of the player
	int         mArmor;				// An int value that describes the armour strength of the player
	Weapon      mWeapon;			// The player's weapon, A weapon value describes the name of a weapon and its range of damage
};

#endif //PLAYER_H