// Monster.cpp

#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"
#include "Random.h"
using namespace std;

// Monster Constructor
// Takes a param list, used to initialise the data members of a monster object at time of construction.
Monster::Monster(const std::string& name, int hp, int acc, int xpReward, int goldReward, int armor, const std::string& weaponName, int lowDamage, int highDamage)
{
	mName      = name;
	mHitPoints = hp;
	mAccuracy  = acc;
	mExpReward = xpReward;
	mGoldReward = goldReward;
	mArmor     = armor;
	mWeapon.mName = weaponName;
	mWeapon.mDamageRange.mLow  = lowDamage;
	mWeapon.mDamageRange.mHigh = highDamage;
}

// returns true if a monster is dead, otherwise it returns false. (monster is dead if HP is <= 0)
bool Monster::isDead()
{
	return mHitPoints <= 0;
}

// accessor method, returns a copy of the mExpReward data member.
int Monster::getXPReward()
{
	return mExpReward;
}

// accessor method, returns a copy of the mGoldReward data member
int Monster::getGoldReward()
{
	return mGoldReward;
}

// accessor method, returns a copy of the mName data member
std::string Monster::getName()
{
	return mName;
}

// accessor method, returns a copy of the mArmour data member
int Monster::getArmor()
{
	return mArmor;
}

// executes the code responsible for the monster attacking the player
// we pass a reference to a player into the function, this is for efficiency,
// we do not want to copy the whole array into a parameter, nor do we want to 
// copy the entire player object, so we pass by reference. (copy a reference (a 32bit address))
// it also determines if the monsters attack hits or misses the player object.
void Monster::attack(Player& player)
{
	// output a message
	cout << "A " << mName << " attacks you " << "with a " << mWeapon.mName << endl;

	// Test to see if the monster hit the player.
	if( Random(0, 20) < mAccuracy )
	{
		// Generate a damage value based on the weapons range.
		int damage = Random(mWeapon.mDamageRange);

		// Subtract the player's armor from damage to simulate armor weakening the attack.  
		// Note that if the armor > damage this results in a negative number.
		int totalDamage = damage - player.getArmor();

		// If totalDamage <= 0, then we say that, although the attack hit, it did not penetrate the armor.
		if( totalDamage <= 0 )
		{
			// output a message
			cout << "The monster's attack failed to " << "penetrate your armor." << endl;
		}
		// otherwise..
		else
		{
			// output a message
			cout << "You are hit for " << totalDamage << " damage!" << endl;

			// Subtract from players hitpoints.
			player.takeDamage(totalDamage);
		}
	}
	// otherwise..
	else
	{
		// output a message
		cout << "The " << mName << " missed!" << endl;
	}
	// output a new line
	cout << endl;
}

// this is called when the player hits a monster, it specifies the amount of damage the monster has taken.
// in turn indicating how many hit points should be deducted from the monster.
void Monster::takeDamage(int damage)
{
	mHitPoints -= damage;
}

// output the monsters hit points to the console to let the player know how many the monster has remaining.
void Monster::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}