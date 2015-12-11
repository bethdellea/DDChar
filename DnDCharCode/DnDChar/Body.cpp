
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <string>
#include "Body.h"





Body::Body() {
        //fixed size
        skillSize = 26;
        abilitySize = 6;
		
        //Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
        abilities = new int [abilitySize];
    
    //Set all random values for abilities array
    for (int i = 0; i < 6; i ++) {
        abilities[i] = setAbility();
    }
        //fixed size
        skills = new int [skillSize]; //contains the skill bonus
    
		//Skill
		//Acrobatics(Dex), Appraise (int), Bluff (cha), Climb (str), Craft (int), Diplomacy (cha), 
		//Disable Device (dex), Disguise (cha), Escapse Artist (cha), Fly (dex), 
		//Handle Animal (cha) Heal (wis), Intimidate (cha), Knowledge (int), Linguistics (int)
		//Perception (wis), perform (cha), Profession (wis), Ride (dex), Sense Motive (wis), 
		//Slieght of Hand (dex), Spellcraft (int), Stealth (dex), Survival (wis), Swim (str) 
		//Use Magic Device (cha),
	}

	//sets skills or changes them 
	void Body::setSkills(int index, int change) {
		skills[index] += change;
	}

//Fills the skills array with base modifiers
void Body::fillSkills() {
        for (int i = 0; i < 26; i ++) {
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
            if (i == 2 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12 || i == 16 || i == 25){ //Charisma modifiers
                skills[i] = getModifier(5);
            }
        }
    }

	//returns the value for the skill
    int Body::skillCheck(int skill) {
		//generate a number from 1 -20 
		//adds the modifier skills
		int timer = 0;
		srand(time(0));
		int randNum = rand() % (20 - 1 + 1) + 1;
		randNum += skills[skill];
		return randNum;
	}
    std::string Body::printThisSkill(int skill) {
		//checks the size of the array
		if (skill > 5) {
			std::string error = "Incorrect index input for the skills array.";
			return error + "\n";
		}
		else {
			std::string output = "Skill level at this spot is: " + skills[skill];
			return output + "\n";
		}

	}
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
		int total = (mod / 10) - 2 + rank;
		return total;
	}

int Body::setAbility() {
		//sets to the ability score given 
		int randNum1 = rand() % (6 - 1 + 1) + 1;
		int randNum2 = rand() % (6 - 1 + 1) + 1;
		int randNum3 = rand() % (6 - 1 + 1) + 1;
		int randNum4 = rand() % (6 - 1 + 1) + 1;

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
        //std::cout << abilities[ability] << std::endl;
		//int mod = ((abilities[ability]) / 10) - 2;
        return 0;
	}

void Body::printThisAbil(int ability) {
		//checks the size of the array first
		if (sizeof(abilities) / sizeof(int) > ability) {
			std::cout << "The modifier at this location is: " << abilities[ability] << std::endl;
		}
		else {
			std::cout << "That was not a correct index in the ability array." << std::endl;
		}
	}
int* Body::getAbilities() {
		return abilities;
	}
void Body::printAllAbilities() {
		for (int i = 0; i < abilitySize - 1; i++) {
			std::cout << abilities[i] << ", ";
		}
		std::cout << abilities[abilitySize - 1] << std::endl;
	}
Body::~Body() {
    
};