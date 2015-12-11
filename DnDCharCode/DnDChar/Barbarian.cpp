//
//  Barbarian.cpp
//  D&DFinal
//
//  Created by Joseph Yull on 12/10/15.
//  Copyright (c) 2015 Joseph Yull. All rights reserved.
//

#include "stdafx.h"
#include <iostream>
#include "Barbarian.h"


using namespace std;
//Initializes skills at compile time
const int Barbarian::skills[9] = {1, 4, 5, 11, 13, 15, 17, 22, 23};

//Establishes all values in a Fighter instance
//Determines skill ranks
//Sets hit die
Barbarian::Barbarian()
{
	className = "Barbarian";
	hitDie = 12;
	goldStart = 3;

	//Sets base saves
	fort = 2;
	ref = 0;
	will = 0;

	//Assumes an Intelligence modifier of +0
	ranks = 4;

	//Assigns character's alignment
	alignment = giveAlignment();

	sizeProf = 2;
	profs = new string[sizeProf];
	profs[0] = "Martial";
	profs[1] = "Simple";
}
	//Walks the player through assigning an aligment in the constructor
	//Only nonlawful alignments for barbarians
	std::string Barbarian::giveAlignment()
{
	//Requests player input
	cout << "Please enter your character's morality:" << endl << "Neutral Good (NG)" << endl << "Chaotic Good (CG)" << endl;
	cout << "Neutral (NN)" << endl << "Chaotic Neutral(CN)" << endl;
	cout << "Neutral Evil (NE)" << endl << "Chaotic Evil (CE)" << endl << endl;
	string align;
	cin >> align;

	//Checks align for good input
	while (align != "NG" && align != "CG" && align != "NN" && align != "CN" && align != "NE" && align != "CE")
	{
		cout << "The input you provided is not correct. Please try again." << endl;
		cin >> align;
	}

	return align;
}

//Determines if a given skill is a class skill
//Compares to skills
bool Barbarian::isClassSkill(int skill)
{
	for (int i = 0; i < 9; i++)
	{
		if (skill == skills[i])
		{
			return true;
		}
	}

	return false;
}

//Determines if a character is proficient with a given item
//Compares an identifier in Item class with an array of
//proficiencies in Character, stored as strings
bool Barbarian::isProf(std::string itemType)
{
	//Loops through profs to see if a matching proficiency is present
	for (int i = 0; i < sizeProf; i++)
	{
		if (profs[i] == itemType)
		{
			return true;
		}
	}
	return false;
}

//Adds a proficiency to the character's proficiencies
void Barbarian::addProf(std::string prof)
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
//this was in the header twice, removed one of them so I could build -- Beth
void Barbarian::printProfs()
{
	for (int i = 0; i < sizeProf; i++)
	{
		cout << profs[i] << endl;
	}
}

//Adds to the character's move speed
void Barbarian::buffMove(RaceADT* race)
{
	race->speed += 10;
}