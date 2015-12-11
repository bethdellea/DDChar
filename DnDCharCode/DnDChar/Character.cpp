//
//  Character.cpp
//  D&DFinal
//
//  Created by Nicole Lane on 12/10/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#include "stdafx.h"
#include <iostream>
#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "Inventory.h"
#include "Fighter.h"
#include "Barbarian.h"
#include <string>
#include <fstream>
#include "RaceADT.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Human.h"
#include "Character.h"
#include "Barbarian.h"

using namespace std;


Character::Character() {

	//Selection of name and race
	cout << "Hello! You are here to make a Dungeons and Dragons character. Luckily, I am here to help!" << endl;
	cout << "First things first! Please enter a name for your character: ";
	std::cin >> name;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << endl;
	cout << "An excellent choice! That certainly sounds like a strong name to me!" << endl;
    cout<< "Next, a body (you need one, after all)." << endl;
    body = new Body();
    cout << "Nice bod!" << endl;

	cout << "Next, you must select your race. Choose a number from the list below." << endl;
	cout << "1) Dwarf" << endl;
	cout << "2) Elf" << endl;
	cout << "3) Human" << endl;

	int choice = -1;
	bool goodInput = false;
	//This checks for the correct input, which is any number from 1 to 3, but does not include strings
	while (!goodInput) {
		cin >> choice;
		if (!cin >> choice) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << endl;
			goodInput = false;
		}


		else if (choice < 1 || choice > 3) {
			cout << "Please enter a valid number." << endl;
			goodInput = false;
		}

		if (choice == 1 || choice == 2 || choice == 3) {
			cout << "Selection recorded!" << endl;
			goodInput = true;
		}

	}


	//Change the abilities array in body according to selected race
	if (choice == 1) {
		cout << "Chose race type 'Dwarf'." << endl;
		race = new Dwarf();
		race->changeAbilities(body->abilities);
		raceStr = "Dwarf";
	}
	else if (choice == 2) {
		cout << "Chose race type 'Elf'." << endl;
		race = new Elf();
		race->changeAbilities(body->abilities);
		raceStr = "Elf";
	}

	else if (choice == 3) {
		cout << "Chose race type 'Human'." << endl;
		race = new Human();
		race->changeAbilities(body->abilities);
		raceStr = "Human";
	}
    
    race->printLanguages();
    race->printVision();

	//Decide which class (right now, we only have Fighter, but we can add more conditions
	cout << "And now to choose your class. Choose a number from the list below." << endl;
	cout << "1) Fighter" << endl;
	cout << "2) Barbarian" << endl;

	int classChoice = -1;
	bool goodInputClass = false;

	//This checks for the correct input, which right now is only number 1, but does not include strings
	while (!goodInputClass) {
		cin >> classChoice;
		if (classChoice > 2 || classChoice < 1) {
			cout << "Please enter a valid number." << endl;
			goodInputClass = false;
		}
		if (classChoice == 1 || classChoice == 2) {
			cout << "Selection recorded!" << endl;
			goodInputClass = true;
		}

		if (!cin >> classChoice) {
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << endl;
			goodInputClass = false;
		}
	}

	//Create class based on user input, and determine HP based off of body modifier
	if (classChoice == 1) {
		cout << "Chose class type 'Fighter'." << endl;
		classType = new Fighter();
		classStr = "Fighter";
		cout << "Rolling a die to determine your HP." << endl;

		HP = classType->rollHP(body->getModifier(2)); //Send body's constitution modifier to the rollHP method
		cout << "Your total HP is: " << HP << endl;
	}

	if (classChoice == 2) {
		cout << "Chose class type 'Barbarian'." << endl;
		classType = new Barbarian();
		classStr = "Barbarian";
		cout << "Rolling a die to determine your HP." << endl;
		HP = classType->rollHP(body->getModifier(2)); //Send body's constitution modifier to the rollHP method
		cout << "Your total HP is: " << HP << endl;
	}

	includeRanks();


	//Create new, empty inventory
	cout << "Creating your empty inventory now (it won't be empty for long)." << endl;
	inventory = new Inventory();
	inventory->interact();
    
    writeFile("testFile");


}

//Calculates the Fortitude save (see formula in the character sheet)
int Character::getFort() {
	int fort = body->getModifier(2) + classType->fort;
	return fort;
}

int Character::getRef() {
	int ref = body->getModifier(1) + classType->ref;
	return ref;
}

int Character::getWill() {
	int will = body->getModifier(4) + classType->will;
	return will;
}

int Character::getAC() {
	int AC = 10 + body->getModifier(1);
	return AC;
}

Character::~Character() {
	//Calls all 4 destructors for each object
	delete[] body;
	delete[] race;
	delete[] classType;
	delete[] inventory;
}


void Character::writeFile(string fileName){
	//name of file should be name of character
	std::string toWrite = "";
	fileName += ".txt";
	std::ofstream outf(fileName, fstream::app);
	//will append to the file - if you have more than one of a character, you must append it yourself
	if (outf) {

		toWrite += "Name: " + name + "\n";
		toWrite += "Race: " + raceStr + "\n";
		toWrite += "Class: " + classStr + "\n";
		toWrite += "Alignment: " + classType->alignment + "\t";
		toWrite += "Proficiencies: ";
		for (int i = 0; i < classType->sizeProf; i++) {
			toWrite += classType->profs[i] + "\t";
		}
		toWrite += "Your Hit Points: " + to_string(HP) + "\t";
		toWrite += "Your Speed: " + to_string(race->getSpeed()) + "\n";
		// LANGUAGES (thanks Nicole)
		toWrite += "You know the languages: ";
		if (race->languageIdx == 1) {
			toWrite += race->knownLanguages[0] + "\n";
		}
		else {
			for (int i = 0; i < race->languageIdx; i++) {

				if (i == race->languageIdx - 1) { //If last in the list, don't print a comma afterwards
					toWrite += "and " + race->knownLanguages[i];
				}
				else {
					toWrite += race->knownLanguages[i] + ", ";
				}

			}

		}

		// VISIONS (thanks Nicole)
        toWrite += race->getLangString();
        cout<< "TO WRITE: " << toWrite<< endl;
        toWrite += "\n";

		//-------------------------------------------
		//packing up the inventory
		std::cout << "Writing your inventory to its file..." << endl;
		std::cout << "Please enter the desired name for your inventory file: ";
		std::string invFilename;
		while (!(std::cin >> invFilename) || invFilename == "") {
			//Some code I found online. Basically catches when cin cannot turn the input into an integer
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "I'm sorry, but the key you pressed was not a valid input or was greater than the quantity you have. Please try again." << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		invFilename += ".txt";
		inventory->toFile(invFilename);
		toWrite += "Total Gold Hoarded: " + to_string(inventory->getGold()) + "\n";
		toWrite += "Items in your inventory:\n" + inventory->listItems() + "\n";
		toWrite += "More detailed inventory information can be found in " + invFilename + "\n";
		//end of the inventory
		//--------------------------------------------

		std::string out;
		outf << toWrite; //add the string gained in the other fcn to the file!
		outf.close();


	}
	else {
		std::cerr << "Can't write to file" << std::endl;
	}

}

//Walks user through adding ranks to his or her skills
void Character::includeRanks()
{
	/*Acrobatics(dex), Appraise (int), Bluff (cha), Climb (str), Craft (int), Diplomacy (cha),
	//Disable Device (dex), Disguise (cha), Escapse Artist (cha), Fly (dex),
	//Handle Animal (cha) Heal (wis), Intimidate (cha), Knowledge (int), Linguistics (int)
	//Perception (wis), perform (cha), Profession (wis), Ride (dex), Sense Motive (wis),
	//Slieght of Hand (dex), Spellcraft (int), Stealth (dex), Survival (wis), Swim (str)
	Use Magic Device (cha),*/

	cout << "Characters can modify their skills with ranks!" << endl;
	cout << "Eligible skills are as follows:" << endl;
	cout << "1 - Acrobatics(dex)" << endl;
	cout << "2 - Appraise (int)" << endl;
	cout << "3 - Bluff (cha)" << endl;
	cout << "4 - Climb (str)" << endl;
	cout << "5 - Craft (int)" << endl;
	cout << "6 - Diplomacy (cha)" << endl;
	cout << "7 - Disable Device (dex)" << endl;
	cout << "8 - Disguise (cha)" << endl;
	cout << "9 - Escapse Artist (cha)" << endl;
	cout << "10 - Fly (dex)" << endl;
	cout << "11 - Handle Animal (cha)" << endl;
	cout << "12 - Heal (wis)" << endl;
	cout << "13 - Intimidate (cha)" << endl;
	cout << "14 - Knowledge(int)" << endl;
	cout << "15 - Linguistics (int)" << endl;
	cout << "16 - Perception (wis)" << endl;
	cout << "17 - Perform (cha)" << endl;
	cout << "18 - Profession (wis)" << endl;
	cout << "19 - Ride (dex)" << endl;
	cout << "20 - Sense Motive (wis)" << endl;
	cout << "21 - Slieght of Hand (dex)" << endl;
	cout << "22 - Spellcraft (int)" << endl;
	cout << "23 - Stealth (dex)" << endl;
	cout << "24 - Survival (wis)" << endl;
	cout << "25 - Swim (str)" << endl;
	cout << "26 - Use Magic Device (cha)" << endl << endl;

	for (int i = 0; i < classType->addRanks(body); i++) {
		cout << "You have " + to_string(classType->addRanks(body)-i) + " ranks to add to your skills!" << endl;
		cout << "Please enter the number of the skill you wish to add to:" << endl;

		int index = -1;
		bool goodInput = false;
		//This checks for the correct input, which is any number from 1 to 3, but does not include strings
		while (!goodInput) {
			cin >> index;
			if (!cin >> index) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << endl;
			}
			else
			{
				goodInput = true;
			}
		}
		body->setSkills(index, 1);

	}
}

//Has the Class generate an amount of starting gold and puts it in Inventory
void Character::putGold()
{
	int startGold = classType->startingGold();
	inventory->addGold(startGold);
}