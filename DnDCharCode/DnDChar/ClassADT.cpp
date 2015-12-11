//ClassADT.cpp
//Joseph Yull
//12-10-2015

#include "stdafx.h"
#include "ClassADT.h"
#include "Body.h"

//Returns a random number with values bewteen min and max, including both min and max
int ClassADT::generateRandomNum(int min, int max)
{
	srand(time(NULL));

	return rand() % (max - min + 1) + min;
}

//Adds a pseudo-random amount of HP to a character
//Max value is 10 (based on hitDie)
//Modifier is based on character's Constitution score.
int ClassADT::rollHP(int modifier)
{
	return generateRandomNum(1, hitDie) + modifier;
}

//Generates the number of d6's used to roll for character gold.
int ClassADT::startingGold()
{
	return generateRandomNum(1, 6) * goldStart * 10;
}

//Determines how many skill ranks the character gets per level
//Amount is fixed by class, added to by modifier
//Modifier is based on character's Intelligence score
int ClassADT::addRanks(Body* bod)
{
	return ranks + bod->getModifier(bod->abilities[3]);
}