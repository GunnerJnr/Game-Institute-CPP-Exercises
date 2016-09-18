// Spell.h

#ifndef SPELL_H
#define SPELL_H

#include "Range.h"
#include <string>

struct Spell
{
	std::string mName;						// The name of the spell (e.g. 'fireball')
	Range       mDamageRange;				// The range of damage the spell inflicts
	int         mMagicPointsRequired;		// The number of magic points required to cast the spell
};

#endif //SPELL_H