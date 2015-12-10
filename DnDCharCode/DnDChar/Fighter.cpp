//Fighter.cpp
//Joseph Yull
//12-2-2015

#include "stdafx.h"
#include <iostream>
#include "Fighter.h"


using namespace std;
//Initializes skills at compile time
const string Fighter::skills[10] = {"Climb", "Craft", "Handle Animal", "Intimidate", "Knowledge Dungeoneering", "Knowledge Engineering", "Profession", "Ride", "Survival", "Swim"};

//Establishes all values in a Fighter instance
//Determines skill ranks
//Sets hit die
Fighter::Fighter()
{
	hitDie = 10;

	//Assumes an Intelligence modifier of +0
	ranks = 2;

	//Assigns character's alignment
	alignment = giveAlignment();

	sizeProf = 2;
	profs = new string[sizeProf];
	profs[0] = "Martial";
	profs[1] = "Simple";
}

//Walks the player through assigning an aligment in the constructor
//No alignment restrictions for fighters
string Fighter::giveAlignment()
{
	//Requests player input
	cout << "Please enter your character's morality:" << endl << "Lawful Good (LG)" << endl << "Neutral Good (NG)" << endl << "Chaotic Good (CG)" << endl;
	cout << "Lawful Neutral(LN)" << endl << "Neutral (NN)" << endl << "Chaotic Neutral(CN)" << endl;
	cout << "Lawful Evil (LE)" << endl << "Neutral Evil (NE)" << endl << "Chaotic Evil (CE)" << endl << endl;
	string align;
	cin >> align;

	//Checks align for good input
	while (align != "LG" && align != "NG" && align != "CG" && align != "LN" && align != "NN" && align != "CN" && align != "NE" && align != "LE" && align != "NE" && align != "CE")
	{
		cout << "The input you provided is not correct. Please try again." << endl;
		cin >> align;
	}

	return align;

}

//Determines if a given skill is a class skill
//Compares to skills
bool Fighter::isClassSkill(std::string skill)
{
	for (int i = 0; i < 10; i++)
	{
		if (skill==skills[i])
		{
			return true;
		}
	}

		return false;
}

//Determines how many skill ranks the character gets per level
//Amount is fixed by class, added to by modifier
//Modifier is based on character's Intelligence score
int Fighter::addRanks(const int modifier)
{
	return 2 + modifier;
}

//Determines if a character is proficient with a given item
//Compares an identifier in Item class with an array of
//proficiencies in Character, stored as strings
bool Fighter::isProf(std::string itemType)
{
	//Loops through profs to see if a matching proficiency is present
	for (int i = 0; i < sizeProf; i++)			
	{
		if (profs[i]== itemType)
		{
			return true;
		}
	}
	return false;
}

//Adds a proficiency to the character's proficiencies
void Fighter::addProf(std::string prof)
{
	if (!isProf(prof))
	{
		//Makes a newly sized array for profs
		string* newProfs = new string[sizeProf + 1];

		for (int i = 0; i < sizeProf; i++)
		{
			newProfs[i] = profs[i];
		}

		//Adds prof to the existing list of proficencies
		newProfs[sizeProf] = prof;

		//Cleanup and replace profs
		delete[] profs;
		profs = newProfs;
		sizeProf++;
	}

}

//Prints available proficiencies
void Fighter::printProfs()
{
	for (int i = 0; i < sizeProf; i++)
	{
		cout << profs[i] << endl;
	}
}

//Establishes Fighter's Armor Training feature
//Modifies skill bonus in Body's skill array
void Fighter::armorTrain()
{
	//TODO: Need ability to set specific skills
}

//Applies Fighter's Weapon Training feature
//Modifies attack modifier *only if* trained weapon is equipped
void Fighter::weaponTrain()
{
	//TODO: Need ability to set specific skills
}

//Deletes skills and profs
Fighter::~Fighter()
{
	delete[] profs;
}