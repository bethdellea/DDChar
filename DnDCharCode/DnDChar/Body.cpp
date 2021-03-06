
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <string>
#include "Body.h"

using namespace std;
Body::Body() {
    //fixed size
    //contains the skill bonus
    skillSize = 26;
    skills = new int[skillSize];
    abilitySize = 6;
    //Abilities
    //Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
    abilities = new int[abilitySize]; //Roll 4-24 and subtract from 1-6
    //Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
    
    //Set all random values for abilities array
    
    int* tempArr = new int[6]; //Values to be inputted into the abilities array by the user
    for (int i = 0; i < 6; i++) {
        tempArr[i] = setAbility();
        std::cout << tempArr[i] << " ";
    }
    
    std::cout << std::endl;
    
    string names[] = { "Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma" };

    int choice = -1;
    for (int i = 0; i < 6; i++) { //Sets all 6 ability values
        bool goodInput = false;
        while (!goodInput) { //Loop until valid input is given
            choice = -1;
            std::cout << "What value would you like to give " << names[i] << "?" << std::endl;
            cin >> choice;
            if (!cin >> choice) {
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << endl;
                goodInput = false;
            }
            else if (choice != tempArr[0] && choice != tempArr[1] && choice != tempArr[2] && choice != tempArr[3] && choice != tempArr[4] && choice != tempArr[5]) {
                cout << "You have either entered an invalid number or you have already chosen that value." << endl;
                goodInput = false;
            }
            else { //Once a value has been selected and entered into the array, it is set to 0 in the temArray so that the value may not be selected again
                if (choice == tempArr[0]) {
                    cout << "Selection recorded!" << endl;
                    tempArr[0] = 0;
                    abilities[i] = choice;
                    goodInput = true;
                }
                else if (choice == tempArr[1]) {
                    cout << "Selection recorded!" << endl;
                    tempArr[1] = 0;
                    abilities[i] = choice;
                    goodInput = true;
                }
                else if (choice == tempArr[2]) {
                    cout << "Selection recorded!" << endl;
                    tempArr[2] = 0;
                    abilities[i] = choice;
                    goodInput = true;
                }
                else if (choice == tempArr[3]) {
                    cout << "Selection recorded!" << endl;
                    tempArr[3] = 0;
                    abilities[i] = choice;
                    goodInput = true;
                }
                else if (choice == tempArr[4]) {
                    cout << "Selection recorded!" << endl;
                    tempArr[4] = 0;
                    abilities[i] = choice;
                    goodInput = true;
                }
                else {
                    cout << "Selection recorded!" << endl;
                    tempArr[5] = 0;
                    abilities[i] = choice;
                    goodInput = true;
                }
            }
        }
    }
    //fixed size
    skills = new int[26]; //contains the skill bonus
    fillSkills(); //Call the fillSkills method to populate skills array
    
    //Skills
    /*Acrobatics(Dex), Appraise (int), Bluff (cha), Climb (str), Craft (int), Diplomacy (cha),
    //Disable Device (dex), Disguise (cha), Escapse Artist (cha), Fly (dex),
    //Handle Animal (cha) Heal (wis), Intimidate (cha), Knowledge (int), Linguistics (int)
    //Perception (wis), perform (cha), Profession (wis), Ride (dex), Sense Motive (wis),
    //Slieght of Hand (dex), Spellcraft (int), Stealth (dex), Survival (wis), Swim (str)
    Use Magic Device (cha),*/
}

//sets skills or changes them
void Body::setSkills(int index, int change) {
    skills[index] += change;
}

int getRanks(int ranks) {
    return ranks;
}
//Fills the skills array with base modifiers calculated in the method get modifier
void Body::fillSkills() {
    for (int i = 0; i < 26; i++) {
        if (i == 3 || i == 24) {
            skills[i] = getModifier(0); //Strength modifiers
        }
        if (i == 0 || i == 6 || i == 9 || i == 18 || i == 20 || i == 22) { //Dexterity modifiers
            skills[i] = getModifier(1);
        }
        if (i == 1 || i == 4 || i == 13 || i == 14 || 21) { //Intelligence modifiers
            skills[i] = getModifier(3);
        }
        if (i == 11 || i == 15 || i == 17 || i == 19 || i == 23) { //Wisdom modifiers
            skills[i] = getModifier(4);
        }
        if (i == 2 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12 || i == 16 || i == 25) { //Charisma modifiers
            skills[i] = getModifier(5);
        }
    }
}

//returns the value for the skill
int Body::skillCheck(int skill) {
    //generate a number from 1 -20
    //adds the modifier skills
    int randNum = rand() % (20 - 1 + 1) + 1;
    randNum += skills[skill];
    return randNum;
}

//Takes an integer to print out the skill at a specific index, and returns a string to be able to print to a file
std::string Body::printThisSkill(int skill) {
	//checks the size of the array
	if (skill > 5) {
		std::string error = "Incorrect index input for the skills array.";
		return error + "\n";
	}
	else {
		std::string output = "Skill level at this spot is:\t" + skills[skill];
		return output + "\n";
	}
}
//Display values for all skills
void Body::printAllSkills() {
    for (int i = 0; i < skillSize - 1; i++) {
        std::cout << skills[i] << ", ";
    }
    std::cout << skills[skillSize - 1] << std::endl;
}

//determine amount of bonus given
int Body::skillCalc(int rank, int mod) {
    //determines the value for each skill
    //formula......adds the rank and mod
    //return value
    int total = (mod - 10) / 2 + rank;
    return total;
}
int Body::generateRandomNum(int min, int max) {
    int num = rand() % (max - min + 1) + min;
    return num;
}
int Body::setAbility() {
    //sets to the ability score given
    
    int randNum1 = generateRandomNum(1, 6); //Simulating 4 6-sided dice rolling
    int randNum2 = generateRandomNum(1, 6); //Take the lowest value and subtract from total sum
    int randNum3 = generateRandomNum(1, 6);
    int randNum4 = generateRandomNum(1, 6);
    
    //cout << randNum1 << " " << randNum2 << " " << randNum3 << " " << randNum4;
    if ((randNum1 < randNum2) && (randNum1 < randNum3) && (randNum1 < randNum4)) {
        return randNum2 + randNum3 + randNum4;
    }
    else if ((randNum2 < randNum1) && (randNum2 < randNum3) && (randNum2 < randNum4)) {
        return randNum1 + randNum3 + randNum4;
    }
    else if ((randNum3 < randNum1) && (randNum3 < randNum2) && (randNum3 < randNum4)) {
        return randNum1 + randNum2 + randNum4;
    }
    else {
        return randNum1 + randNum2 + randNum3;
    }
    
}
//mathematically based on abilities
int Body::getModifier(int ability) {
    return ((abilities[ability]) - 10) / 2; //Formula for calculating each ability modifier
}

//Prints the ability value at the indicated index
void Body::printThisAbil(int ability) {
    //checks the size of the array first
    if (sizeof(abilities) / sizeof(int) > ability) {
        std::cout << "The modifier at this location is: " << abilities[ability] << std::endl;
    }
    else {
        std::cout << "That was not a correct index in the ability array." << std::endl;
    }
}

//returns the entire abilities array
int* Body::getAbilities() {
    return abilities;
}

//displays all values for all abilities
void Body::printAllAbilities() {
    for (int i = 0; i < abilitySize - 1; i++) {
        std::cout << abilities[i] << ", ";
    }
    std::cout << abilities[abilitySize - 1] << std::endl;
}

//Prints abilities to a string and returns it for printing to a file
std::string Body::printAbilities()
{
	std::string abils = "";
	abils += "Strength:\t" + std::to_string(abilities[0]) + "\n";
	abils += "Dexterity:\t" + std::to_string(abilities[1]) + "\n";
	abils += "Constitution:\t" + std::to_string(abilities[2]) + "\n";
	abils += "Intelligence:\t" + std::to_string(abilities[3]) + "\n";
	abils += "Wisdom:   \t" + std::to_string(abilities[4]) + "\n";
	abils += "Charisma:\t" + std::to_string(abilities[5]) + "\n";
	return abils;
}

Body::~Body() {
    //delete[] tempArr;
    delete[] abilities;
    delete[] skills;
    
};