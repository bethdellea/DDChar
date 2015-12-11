//Joseph Yull
//11-17-2015
//COMP 220 Final Project: Class ADT

#ifndef _DDChar_Barbarian_
#define _DDChar_Barbarian_

#include "stdafx.h"
#include "ClassADT.h"
#include "ItemWeapon.h"

class Barbarian : public ClassADT {

private:
	//Class skills never change, so can be constant
	//Note that skills is static, as it is the same for all barbarians
	static const std::string const skills[9];

public:

	//Establishes all values in a Barbarian instance
	//Fills skills (fixed input)
	//Fills proficiencies (starting input is fixed)
	//Sets hitDie to 12 and generates random HP value
	Barbarian();

	//Walks the player through assigning an aligment in the constructor
	//Only chaotic alignments for barbarians
	std::string giveAlignment();

	//Determines if a given skill is a class skill
	//Compares to skills
	bool isClassSkill(std::string skill);

	//Determines how many skill ranks the character gets per level
	//Amount is fixed by class, added to by modifier
	//Modifier is based on character's Intelligence score
	int addRanks(const int modifier);

	//Determines if a character is proficient with a given item
	//Compares an identifier in Item class with an array of
	//proficiencies in Character, stored as strings
	bool isProf(std::string ItemType);

	//Adds a proficiency to the character's proficiencies
	void addProf(std::string prof);

	//Prints available proficiencies
	//this was in the header twice, removed one of them so I could build -- Beth
	void printProfs();

	//TODO: Add Barbarian-specific methods

	//Deletes skills and profs
	~Barbarian();

};

#endif

