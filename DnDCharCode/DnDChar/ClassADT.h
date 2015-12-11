//Joseph Yull
//11-17-2015
//COMP 220 Final Project: Class ADT

#ifndef _DDChar_Class_ADT_
#define _DDChar_Class_ADT_

#include <iostream>
#include <time.h>
#include <string>
#include <array>
#include "Body.h"

class ClassADT {

protected:
	std::string className;
	int goldStart;
	int hitDie;

	int fort, ref, will;

	//Proficiencies can be added to by race, so will not be constant
	//Initialized here, as {} syntax does not work to initialize data members
	std::string* profs;

	int sizeProf;

	std::string alignment;

public:
    
    static int ranks;
	//Walks the player through assigning an aligment in the constructor
	//Limits the availability of some alignments based on class
	virtual std::string giveAlignment() = 0;

	//Adds a pseudo-random amount of HP to a character
	//RNG depends on class
	//Modifier is based on character's Constitution score.
	int rollHP(int modifier);

	//Returns a random number with values bewteen min and max, including both min and max
	int generateRandomNum(int min, int max);

	//Determines if a given skill is a class skill
	//Compares to an array of strings stored in Class
	virtual bool isClassSkill(int skill) = 0;

	//Determines how many skill ranks the character gets per level
	//Amount is fixed by class, added to by modifier
	//Modifier is based on character's Intelligence score
	int addRanks(Body* bod);

	//Determines if a character is proficient with a given item
	//Compares an identifier in Item class with an array of
		//proficiencies in Character, stored as strings
	virtual bool isProf(std::string itemType) = 0;

	//Adds a proficiency to the character's proficiencies
	virtual void addProf(std::string prof) = 0;

	//Prints available proficiencies
	virtual void printProfs() = 0;
	
	//Generates the number of d6's used to roll for character gold.
	int startingGold();



	//Virtual default destructor to ensure more specific destructors are called
	virtual ~ClassADT() {};
};

#endif