// Monster.h

#ifndef MONSTER_H
#define MONSTER_H

#include "Weapon.h"
#include <string>

// "Forward class declaration" so that we can use the Player
// class without having defined it yet.  This idea is 
// similar to a function declaration.

class Player;

class Monster
{
public:
	// Monster Constructor
	// Takes a param list, used to initialise the data members of a monster object at time of construction.
	Monster(const std::string& name, int hp, int acc, int xpReward, int goldReward, int armor, const std::string& weaponName, int lowDamage, int highDamage);

	// returns true if a monster is dead, otherwise it returns false. (monster is dead if HP is <= 0)
	bool isDead();

	// accessor method, returns a copy of the mExpReward data member.
	int         getXPReward();

	// accessor method, returns a copy of the mGoldReward data member
	int			getGoldReward();

	// accessor method, returns a copy of the mName data member
	std::string getName();

	// accessor method, returns a copy of the mArmour data member
	int         getArmor();

	// executes the code responsible for the monster attacking the player
	// we pass a reference to a player into the function, this is for efficiency,
	// we do not want to copy the whole array into a parameter, nor do we want to 
	// copy the entire player object, so we pass by reference. (copy a reference (a 32bit address))
	// it also determines if the monsters attack hits or misses the player object.
	void attack(Player& player);

	// this is called when the player hits a monster, it specifies the amount of damage the monster has taken.
	// in turn indicating how many hit points should be deducted from the monster.
	void takeDamage(int damage);

	// output the monsters hit points to the console to let the player know how many the monster has remaining.
	void displayHitPoints();

private:
	std::string mName;			// The name of the monster
	int         mHitPoints;		// An int that describes the num of hit points the monster has
	int         mAccuracy;		// An int value used to determine the probability of a monster hitting or missing a player
	int         mExpReward;		// An int value that describes how many xp points the player gets when they defeat a monster
	int			mGoldReward;	// An int value that describes how many gold coins the player gets when they defeat a monster
	int         mArmor;			// An int value that describes the armour strength of a monster
	Weapon      mWeapon;		// The monsters weapon, a weapon value describes the name of a weapon and its range of damage
};

#endif //MONSTER_H