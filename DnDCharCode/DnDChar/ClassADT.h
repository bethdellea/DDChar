//Joseph Yull
//11-17-2015
//COMP 220 Final Project: Class ADT

#ifndef _DDChar_Class_ADT_
#define _DDChar_Class_ADT_

#include <iostream>
#include <time.h>
#include <string>
#include <array>


class ClassADT {

protected:

	int goldStart;
	int hitDie;

	//Proficiencies can be added to by race, so will not be constant
	//Initialized here, as {} syntax does not work to initialize data members
	std::string* profs;

	int sizeProf;

	std::string alignment;

	int ranks;

public:
	//Walks the player through assigning an aligment in the constructor
	//Limits the availability of some alignments based on class
	virtual std::string giveAlignment() = 0;

	//Adds a pseudo-random amount of HP to a character
	//RNG depends on class
	//Modifier is based on character's Constitution score.
	virtual int rollHP(int modifier) = 0;

	//Returns a random number with values bewteen min and max, including both min and max
	int generateRandomNum(int min, int max);

	//Determines if a given skill is a class skill
	//Compares to an array of strings stored in Class
	virtual bool isClassSkill(std::string skill) = 0;

	//Determines how many skill ranks the character gets per level
	//Amount is fixed by class, added to by modifier
	//Modifier is based on character's Intelligence score
	virtual int addRanks(const int modifier) = 0;

	//Determines if a character is proficient with a given item
	//Compares an identifier in Item class with an array of
		//proficiencies in Character, stored as strings
	virtual bool isProf(std::string itemType) = 0;

	//Adds a proficiency to the character's proficiencies
	virtual void addProf(std::string prof) = 0;

	//Prints available proficiencies
	virtual void printProfs() = 0;



	//Virtual default destructor to ensure more specific destructors are called
	virtual ~ClassADT() {};
};

#endif