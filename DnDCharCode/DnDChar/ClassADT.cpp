//ClassADT.cpp
//Joseph Yull
//12-10-2015

#include "stdafx.h"
#include "ClassADT.h"

//Returns a random number with values bewteen min and max, including both min and max
int ClassADT::generateRandomNum(int min, int max)
{
	srand(time(NULL));

	return rand() % (max - min + 1) + min;
}

//Adds a pseudo-random amount of HP to a character
//Max value is 10 (based on hitDie)
//Modifier is based on character's Constitution score.
int ClassADT::rollHP(const int modifier)
{
	return generateRandomNum(1, hitDie) + modifier;
}