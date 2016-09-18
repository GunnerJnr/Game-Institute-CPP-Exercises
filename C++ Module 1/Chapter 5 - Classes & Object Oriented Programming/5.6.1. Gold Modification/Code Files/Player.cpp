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

	// Character selection.
	cout << "Please select a character class number..."<< endl;	
	cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";	

	int characterNum = 1;	
	cin >> characterNum;

	switch( characterNum )
	{
	case 1:  // Fighter
		mClassName    = "Fighter";
		mAccuracy     = 10;
		mHitPoints    = 20;
		mMaxHitPoints = 20;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mArmor        = 4;
		mGold		  = 50;
		mWeapon.mName = "Long Sword";
		mWeapon.mDamageRange.mLow  = 1;
		mWeapon.mDamageRange.mHigh = 8;
		break;
	case 2:  // Wizard
		mClassName    = "Wizard";
		mAccuracy     = 5;
		mHitPoints    = 10;
		mMaxHitPoints = 10;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mArmor        = 1;
		mGold		  = 26;
		mWeapon.mName = "Staff";
		mWeapon.mDamageRange.mLow  = 1;
		mWeapon.mDamageRange.mHigh = 4;
		break;
	case 3:  // Cleric
		mClassName    = "Cleric";
		mAccuracy     = 8;
		mHitPoints    = 15;
		mMaxHitPoints = 15;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mArmor        = 3;
		mGold		  = 18;
		mWeapon.mName = "Flail";
		mWeapon.mDamageRange.mLow  = 1;
		mWeapon.mDamageRange.mHigh = 6;
		break;
	default: // Thief
		mClassName    = "Thief";
		mAccuracy     = 7;
		mHitPoints    = 12;
		mMaxHitPoints = 12;
		mExpPoints    = 0;
		mNextLevelExp = 1000;
		mLevel        = 1;
		mArmor        = 2;
		mGold		  = 38;
		mWeapon.mName = "Short Sword";
		mWeapon.mDamageRange.mLow  = 1;
		mWeapon.mDamageRange.mHigh = 6;
		break;
	}
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

		// Increase stats randomly.
		mAccuracy     += Random(1, 3);
		mMaxHitPoints += Random(2, 6);
		mArmor        += Random(1, 2);

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