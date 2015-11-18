//Joseph Yull
//11-17-2015
//COMP 220 Final Project: Class ADT

#ifndef _DDChar_Fighter_
#define _DDChar_Fighter

#include "ClassADT.h"

class Fighter : ClassADT {

private:
	//Class skills never change, so can be constant
	const std::string* skills;
	//Proficiencies can be added to by race, so will not be constant
	std::string* profs;
	const int hitDie, ranks;

public:

	//Establishes all values in a Fighter instance
	//Fills skills (fixed input)
	//Fills proficiencies (starting input is fixed)
	//Sets hitDie to 10 and generates random HP value
	Fighter();

	//Deep copy constructor for skills and profs
	Fighter(const Fighter& fighter);

	//Walks the player through assigning an aligment in the constructor
	//No alignment restrictions for fighters
	void giveAlignment();

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
	int addRanks(int modifier);

	//Determines if a character is proficient with a given item
	//Compares an identifier in Item class with an array of
	//proficiencies in Character, stored as strings
	bool isProf(/*Item item*/);

	//Adds a proficiency to the character's proficiencies
	void addProf(std::string prof);

	//Adds Fighter's conditional Will save bonus against fear effects
	void bravery();

	//Establishes Fighter's Armor Training feature
	//Modifies skill bonus in Body's skill array
	void armorTrain();

	//Applies Fighter's Weapon Training feature
	//Modifies attack modifier *only if* trained weapon is equipped
	void weaponTrain();

	//Prints available proficiencies
	void printProfs();

	//Deletes skills and profs
	~Fighter() {};

};

#endif