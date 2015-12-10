//Joseph Yull
//11-17-2015
//COMP 220 Final Project: Class ADT

#ifndef _DDChar_Fighter_
#define _DDChar_Fighter

#include "stdafx.h"
#include "ClassADT.h"
#include "ItemWeapon.h"

class Fighter : public ClassADT {

private:
	//Class skills never change, so can be constant
	//Note that skills is static, as it is the same for all fighters
	static const std::string const skills[10];

public:

	//Establishes all values in a Fighter instance
	//Fills skills (fixed input)
	//Fills proficiencies (starting input is fixed)
	//Sets hitDie to 10 and generates random HP value
	Fighter();

	//Walks the player through assigning an aligment in the constructor
	//No alignment restrictions for fighters
	std::string giveAlignment();

	//Adds a pseudo-random amount of HP to a character
	//Max value is 10 (based on hitDie)
	//Modifier is based on character's Constitution score.
	int rollHP(const int modifier);

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

	//Establishes Fighter's Armor Training feature
	//Modifies skill bonus in Body's skill array
	void armorTrain();

	//Applies Fighter's Weapon Training feature
	//Modifies attack modifier *only if* trained weapon is equipped
	void weaponTrain();

	//Deletes skills and profs
	~Fighter();
	
};

#endif