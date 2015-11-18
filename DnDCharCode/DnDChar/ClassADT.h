//Joseph Yull
//11-17-2015
//COMP 220 Final Project: Class ADT

#ifndef _DDChar_Class_ADT_
#define _DDChar_Class_ADT_

#include <iostream>

class ClassADT {

public:
	//Walks the player through assigning an aligment in the constructor
	//Limits the availability of some alignments based on class
	virtual void giveAlignment() = 0;

	//Adds a pseudo-random amount of HP to a character
	//RNG depends on class
	//Modifier is based on character's Constitution score.
	virtual int rollHP(int modifier) = 0;

	//Determines if a given skill is a class skill
	//Compares to an array of strings stored in Class
	virtual bool isClassSkill(std::string skill) = 0;

	//Determines how many skill ranks the character gets per level
	//Amount is fixed by class, added to by modifier
	//Modifier is based on character's Intelligence score
	virtual int addRanks(int modifier) = 0;

	//Determines if a character is proficient with a given item
	//Compares an identifier in Item class with an array of
		//proficiencies in Character, stored as strings
	virtual bool isProf(/*Item item*/) = 0;

	//Adds a proficiency to the character's proficiencies
	virtual void addProf(std::string prof) = 0;

	//Prints available proficiencies
	virtual void printProfs() = 0;

	//Prints available proficiencies
	void printProfs();

	//Virtual default destructor to ensure more specific destructors are called
	virtual ~ClassADT() {};
};

#endif