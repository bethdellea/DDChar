//Joseph Yull
//12-9-2015
//Character.h

#pragma once

#ifndef Character_h
#define Character_h

#include "Body.h"
#include "ClassADT.h"
#include "RaceADT.h"
#include "Inventory.h"

class Character {

private:
	
	Body* body;
	RaceADT* race;
	std::string raceStr;
	ClassADT* classType;
	std::string classStr;
	Inventory* inventory;
	int HP;

public:
	std::string name;
	//Default constructor, however it will still ask for user input
	//Will probably be pretty big/delegated to other functions
	//Initializes the pointers with instances
	//Basically ask user for what they want and make it
	//Generates HP by calling Class's rollHP method with Body's Constitution modifier
	Character();

	//Creates a character based on a character save file
	Character(std::string filename, Body* body, RaceADT* race, ClassADT* classType);

	//Calculates AC based on Body's Dex modifier, Inventory's armor, and any size modifiers due to Race
	//For race, check if race = dwarf, essentially
    int getAC();

	//Calculates the Fortitude save (see formula in the character sheet)
	int getFort();

	//Calculates the Reflex save (see formula in the character sheet)
	int getRef();

	//Calculates the Will save (see formula in the character sheet)
	int getWill();

	//Saves a character and all accompanying data in a file format
	void writeFile(std::string filename, Body* body, RaceADT* race, ClassADT* classType);

	//Has the Class generate an amount of starting gold and puts it in Inventory
	void putGold();

	//calls the writeFile function
	void callFile();

	//Deletes the 4 object instances, as all are pointers
	~Character();
};

#endif