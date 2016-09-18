// Player.cpp

#include <iostream>
#include "Player.h"
#include "Random.h"
#include <string>
using namespace std;

// Default Constructor
// Initialises the data members to default values
Player::Player()
{
	mName         = "Default";
	mClassName    = "Default";
	mAccuracy     = 0;
	mHitPoints    = 0;
	mMaxHitPoints = 0;
	mExpPoints    = 0;
	mNextLevelExp = 0;
	mLevel        = 0;
	mArmor        = 0;
	mGold		  = 0;
	mWeapon.mName = "Default Weapon Name";
	mWeapon.mDamageRange.mLow  = 0;
	mWeapon.mDamageRange.mHigh = 0;
	mCharacterNum = 0;
}

// returns true if the player is dead, otherwise returns false
// (player is defined dead if hp <= 0)
bool Player::isDead()
{
	return mHitPoints <= 0;
}

// accessor method, returns a copy of the mArmor data member
int Player::getArmor()
{
	return mArmor;
}

// called when a monster hits a player
// The param specifies the amount of damage for which the player was hit, this indicates
// how many hit points should be subtracted from the player
void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}

// This method is used to execute code that performs the character generation process.
// It 1st asks the user to enter a name for their character, then to select the class that player will be,
// then based on the class chosen, the properties of the player are filled out accordingly
void Player::createClass()
{
	cout << "CHARACTER CLASS GENERATION" << endl;
	cout << "==========================" << endl;

	// Input character's name.
	cout << "Enter your character's name: ";
	getline(cin, mName);

	// Character selection, the player will choose the race they wish to be
	cout << "Please select a character class number..."<< endl;	
	cout << "[1] Elf, [2] Human, [3] Dwarf, [4] Halfling : ";

	// create an int variable to store the users character race choice
	int characterRaceNum = 1;
	cin >> characterRaceNum;
	/*
	// TODO - Add message for invalid choice, repeat loop until valid choice is selected.
	else
	{
	cout << "Sorry invalid choice, Please try again.." << endl;
	// Some call to restart loop
	}
	*/

	// here we just do a series of checks, depending on what number the player chose (what race)
	// we output the appropriate selections based on the race choice..

	// if player chose race 1
	if (characterRaceNum == 1)
	{
		// output specific race selections
		cout << "[1]Elf Fighter, [2]Elf Wizard, [3]Elf Cleric, [4]Elf Thief : ";
	}
	// if player chose race 2
	else if (characterRaceNum == 2)
	{
		// output specific race selections
		cout << "[1]Human Fighter, [2]Human Wizard, [3]Human Cleric, [4]Human Thief : ";
	}
	// if player chose race 3
	else if (characterRaceNum == 3)
	{
		// output specific race selections
		cout << "[1]Dwarf Fighter, [2]Dwarf Wizard, [3]Dwarf Cleric, [4]Dwarf Thief : ";
	}
	// if player chose race 4
	else if (characterRaceNum == 4)
	{
		// output specific race selections
		cout << "[1]Halfling Fighter, [2]Halfling Wizard, [3]Halfling Cleric, [4]Halfling Thief : ";
	}
	/*
	// TODO - Add message for invalid choice, repeat loop until valid choice is selected.
	else
	{
	cout << "Sorry invalid choice, Please try again.." << endl;
	// Some call to restart loop
	}
	*/

	// create another int variable to store the second choice 
	// e.g if the player chose elf, then their second choice may be elf fighter [1]
	int characterNum = 1;	
	cin >> characterNum;

	// same idea as a bove but a bit cleaner in a switch statement
	// here we basically set the stats to the player depending on what choice they made 
	// e.g fighter, thief, cleric, wizard

	// if character race is equal to 1 (elf)
	if (characterRaceNum == 1)
	{
		// check which selection the user has made (e.g fighter, wizard, etc..)
		switch (characterNum)
		{
		case 1:  // Elf Fighter
			mClassName = "Elf Fighter";
			mAccuracy = 12;
			mHitPoints = 25;
			mMaxHitPoints = 34;
			mExpPoints = 0;
			mNextLevelExp = 1200;
			mLevel = 1;
			mArmor = 8;
			mGold = 64;
			mWeapon.mName = "Elf Long Sword";
			mWeapon.mDamageRange.mLow = 2;
			mWeapon.mDamageRange.mHigh = 13;
			break;
		case 2:  // Elf Wizard
			mClassName = "Elf Wizard";
			mAccuracy = 8;
			mHitPoints = 22;
			mMaxHitPoints = 28;
			mExpPoints = 0;
			mNextLevelExp = 800;
			mLevel = 1;
			mArmor = 2;
			mGold = 46;
			mWeapon.mName = "Elf Wizard Staff";
			mWeapon.mDamageRange.mLow = 3;
			mWeapon.mDamageRange.mHigh = 5;
			break;
		case 3:  // Elf Cleric
			mClassName = "Elf Cleric";
			mAccuracy = 6;
			mHitPoints = 16;
			mMaxHitPoints = 21;
			mExpPoints = 0;
			mNextLevelExp = 1350;
			mLevel = 1;
			mArmor = 3;
			mGold = 28;
			mWeapon.mName = "Elf Flail";
			mWeapon.mDamageRange.mLow = 3;
			mWeapon.mDamageRange.mHigh = 9;
			break;
		default: // Elf Thief
			mClassName = "Elf Thief";
			mAccuracy = 7;
			mHitPoints = 18;
			mMaxHitPoints = 26;
			mExpPoints = 0;
			mNextLevelExp = 1425;
			mLevel = 1;
			mArmor = 3;
			mGold = 54;
			mWeapon.mName = "Elf Short Sword";
			mWeapon.mDamageRange.mLow = 3;
			mWeapon.mDamageRange.mHigh = 7;
			break;
		}
	}
	// if character race is equal to 2 (Human)
	else if (characterRaceNum == 2)
	{
		switch (characterNum)
		{
		case 1:  // Human Fighter
			mClassName = "Human Fighter";
			mAccuracy = 10;
			mHitPoints = 20;
			mMaxHitPoints = 20;
			mExpPoints = 0;
			mNextLevelExp = 1000;
			mLevel = 1;
			mArmor = 4;
			mGold = 50;
			mWeapon.mName = "Long Sword";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 8;
			break;
		case 2:  // Human Wizard
			mClassName = "Human Wizard";
			mAccuracy = 61;
			mHitPoints = 10;
			mMaxHitPoints = 10;
			mExpPoints = 0;
			mNextLevelExp = 1000;
			mLevel = 1;
			mArmor = 3;
			mGold = 26;
			mWeapon.mName = "Human Staff";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 4;
			break;
		case 3:  // Human Cleric
			mClassName = "Human Cleric";
			mAccuracy = 8;
			mHitPoints = 15;
			mMaxHitPoints = 15;
			mExpPoints = 0;
			mNextLevelExp = 1000;
			mLevel = 1;
			mArmor = 3;
			mGold = 18;
			mWeapon.mName = "Flail";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 6;
			break;
		default: // Human Thief
			mClassName = "Human Thief";
			mAccuracy = 7;
			mHitPoints = 12;
			mMaxHitPoints = 12;
			mExpPoints = 0;
			mNextLevelExp = 1000;
			mLevel = 1;
			mArmor = 2;
			mGold = 38;
			mWeapon.mName = "Short Sword";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 6;
			break;
		}
	}
	// if character race is equal to 3 (Dwarf)
	else if (characterRaceNum == 3)
	{
		switch (characterNum)
		{
		case 1:  // Dwarf Fighter
			mClassName = "Dwarf Fighter";
			mAccuracy = 8;
			mHitPoints = 24;
			mMaxHitPoints = 26;
			mExpPoints = 0;
			mNextLevelExp = 950;
			mLevel = 1;
			mArmor = 5;
			mGold = 62;
			mWeapon.mName = "Long Sword";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 10;
			break;
		case 2:  // Dwarf Wizard
			mClassName = "Dwarf Wizard";
			mAccuracy = 3;
			mHitPoints = 17;
			mMaxHitPoints = 22;
			mExpPoints = 0;
			mNextLevelExp = 850;
			mLevel = 1;
			mArmor = 3;
			mGold = 43;
			mWeapon.mName = "Staff";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 6;
			break;
		case 3:  // Dwarf Cleric
			mClassName = "Dwarf Cleric";
			mAccuracy = 4;
			mHitPoints = 26;
			mMaxHitPoints = 30;
			mExpPoints = 0;
			mNextLevelExp = 1225;
			mLevel = 1;
			mArmor = 4;
			mGold = 18;
			mWeapon.mName = "Flail";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 9;
			break;
		default: // Dwarf Thief
			mClassName = "Dwarf Thief";
			mAccuracy = 3;
			mHitPoints = 15;
			mMaxHitPoints = 18;
			mExpPoints = 0;
			mNextLevelExp = 650;
			mLevel = 1;
			mArmor = 4;
			mGold = 54;
			mWeapon.mName = "Short Sword";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 4;
			break;
		}
	}
	// if character race is equal to 4 (Halfling)
	else if (characterRaceNum == 4)
	{
		switch (characterNum)
		{
		case 1:  // Halfling Fighter
			mClassName = "Halfling Fighter";
			mAccuracy = 11;
			mHitPoints = 16;
			mMaxHitPoints = 16;
			mExpPoints = 0;
			mNextLevelExp = 1525;
			mLevel = 1;
			mArmor = 8;
			mGold = 150;
			mWeapon.mName = "Long Sword";
			mWeapon.mDamageRange.mLow = 2;
			mWeapon.mDamageRange.mHigh = 7;
			break;
		case 2:  // Halfling Wizard
			mClassName = "Halfling Wizard";
			mAccuracy = 2;
			mHitPoints = 12;
			mMaxHitPoints = 14;
			mExpPoints = 0;
			mNextLevelExp = 675;
			mLevel = 1;
			mArmor = 1;
			mGold = 26;
			mWeapon.mName = "Staff";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 5;
			break;
		case 3:  // Halfling Cleric
			mClassName = "Halfling Cleric";
			mAccuracy = 6;
			mHitPoints = 15;
			mMaxHitPoints = 20;
			mExpPoints = 0;
			mNextLevelExp = 1050;
			mLevel = 1;
			mArmor = 4;
			mGold = 18;
			mWeapon.mName = "Flail";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 7;
			break;
		default: // Halfling Thief
			mClassName = "Halfling Thief";
			mAccuracy = 5;
			mHitPoints = 12;
			mMaxHitPoints = 18;
			mExpPoints = 0;
			mNextLevelExp = 755;
			mLevel = 1;
			mArmor = 4;
			mGold = 86;
			mWeapon.mName = "Short Sword";
			mWeapon.mDamageRange.mLow = 1;
			mWeapon.mDamageRange.mHigh = 9;
			break;
		}
	}
	/*
	// TODO - Add message for invalid choice, repeat loop until valid choice is selected.
	else
	{
		cout << "Sorry invalid choice, Please try again.." << endl;
		// Some call to restart loop
	}
	*/

	mCharacterNum = characterNum;
}

// essentially the same as the monster attack method, but has one IMPORTANT difference, that is
// we give the player an option of what to do on his attack turn (e.g Stay and fight .. ? or run, can also be extended..)
bool Player::attack(Monster& monster)
{
	// Combat is turned based: display an options menu.  You can,
	// of course, extend this to let the player use an item,
	// cast a spell, and so on.
	int selection = 1;
	cout << "1) Attack, 2) Run: ";
	cin >> selection;
	cout << endl;

	switch( selection )
	{
	case 1:
		cout << "You attack an " << monster.getName() 
			<< " with a " << mWeapon.mName << endl;

		if( Random(0, 20) < mAccuracy )
		{
			int damage = Random(mWeapon.mDamageRange);

			int totalDamage = damage - monster.getArmor();

			if( totalDamage <= 0 )
			{
				cout << "Your attack failed to penetrate "
					<< "the armor." << endl;
			}
			else
			{
				cout << "You attack for " << totalDamage 
					<< " damage!" << endl;

				// Subtract from monster's hitpoints.
				monster.takeDamage(totalDamage);
			}
		}
		else
		{
			cout << "You miss!" << endl;
		}
		cout << endl;
		break;
	case 2:
		// 25 % chance of being able to run.
		int roll = Random(1, 4);

		if( roll == 1 )
		{
			cout << "You run away!" << endl;
			return true;//<--Return out of the function.
		}
		else
		{
			cout << "You could not escape!" << endl;
			break;
		}
	}

	return false;
}
 
// tests whether or not the player has acquired enough xp points to level up.
// called after every battle (to check xp points), if the player has gained enough, then 
// some of the players stats (i.e hit points and accuracy) are randomly increased.
void Player::levelUp()
{
	if( mExpPoints >= mNextLevelExp )
	{
		cout << "You gained a level!" << endl;

		// Increment level.
		mLevel++;

		// Set experience points required for next level.
		mNextLevelExp = mLevel * mLevel * 1000;

		// if the user chooses fighter
		if (mCharacterNum == 1)
		{
			// Increase stats randomly.
			mAccuracy += Random(2, 5);
			mMaxHitPoints += Random(4, 8);
			mArmor += Random(3, 6);
		}
		// if the user chooses wizard
		else if (mCharacterNum == 2)
		{
			// Increase stats randomly.
			mAccuracy += Random(1, 4);
			mMaxHitPoints += Random(2, 6);
			mArmor += Random(1, 5);
		}
		// if the user chooses cleric
		else if (mCharacterNum == 3)
		{
			// Increase stats randomly.
			mAccuracy += Random(2, 4);
			mMaxHitPoints += Random(2, 5);
			mArmor += Random(1, 3);
		}
		// if the user chooses thief
		else if (mCharacterNum == 4)
		{
			// Increase stats randomly.
			mAccuracy += Random(1, 4);
			mMaxHitPoints += Random(1, 5);
			mArmor += Random(2, 6);
		}

		// Give player full hitpoints when they level up.
		mLevel = mMaxHitPoints;
	}
}

// called when the player chooses to rest, currently it increases the players hit points to maximum (useful for after a battle),
// can add the possibility of random enemy encounters during rest or other events if you wish!!...
void Player::rest()
{
	cout << "Resting..." << endl;

	mHitPoints = mMaxHitPoints;

	// TODO: Modify function so that random enemy encounters
	// are possible when resting.
}

// display the players stats
void Player::viewStats()
{
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;

	cout << "Name            = " << mName         << endl;
	cout << "Class           = " << mClassName    << endl;
	cout << "Accuracy        = " << mAccuracy     << endl;
	cout << "Hitpoints       = " << mHitPoints    << endl;
	cout << "MaxHitpoints    = " << mMaxHitPoints << endl;
	cout << "XP              = " << mExpPoints    << endl;
	cout << "XP for Next Lvl = " << mNextLevelExp << endl;
	cout << "Level           = " << mLevel        << endl;
	cout << "Armor           = " << mArmor        << endl;
	cout << "Gold            = " << mGold		  << endl;
	cout << "Weapon Name     = " << mWeapon.mName << endl;
	cout << "Weapon Damage   = " << mWeapon.mDamageRange.mLow << "-" <<
		mWeapon.mDamageRange.mHigh << endl;

	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
}

// displayed after a player wins battle, a victory message is displayed and gives the player an xp point reward
void Player::victory(int xp, int gold)
{
	cout << "You won the battle!" << endl;
	cout << "You win " << xp << " experience points!" << endl;
	cout << "you win " << gold << " gold coins!" << endl << endl;

	mExpPoints += xp;
	mGold += gold;
}

// called if the player died in battle, displays a "Game Over" message and asks the user to press 'q' to quit the game
void Player::gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "================================" << endl;
	cout << "GAME OVER!" << endl;
	cout << "================================" << endl;
	cout << "Press 'q' to quit: ";
	char q = 'q';
	cin >> q;
	cout << endl;
}

// outputs the player's hit points to the console, used in game during battles, this is so the player may see how many hit points are remaining
void Player::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}