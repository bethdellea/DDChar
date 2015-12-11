
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <string>
#include "Body.h"





Body::Body() {
        //fixed size
         //contains the skill bonus
        skillSize = 26;
        skills = new int[skillSize];
        abilitySize = 6;
		//Abilites
		//Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
        abilities = new int [abilitySize]; //Roll 4-24 and subtract from 1-6

		//Skill
		//null array
		//how many do they get to choose? 5? 
		//Acrobatics(Dex), Appraise (int), Bluff (cha), Climb (str), Craft (int), Diplomacy (cha), 
		//Disable Device (dex), Disguise (cha), Escapse Artist (cha), Fly (dex), 
		//Handle Animal (cha) Heal (wis), Intimidate (cha), Knowledge (int), Linguistics (int)
		//Perception (wis), perform (cha), Profession (wis), Ride (dex), Sense Motive (wis), 
		//Slieght of Hand (dex), Spellcraft (int), Stealth (dex), Survival (wis), Swim (str) 
		//Use Magic Device (cha)
	}
	//sets skills or changes them 
	/*void Body::setSkills(int index, int change) {
		skills[index] += change;
	}
    
    int Body::generateRandomNum(int min, int max) {
        
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
	void Body::printThisSkill(int skill) {
		//checks the size of the array
		if (skill > 5) {
			std::cout << "Incorrect index input for the skills array." << std::endl;
		}
		else {
			std::cout << "Skill level at this spot is: " + skills[skill] << std::endl;
		}

	}
	void Body::printAllSkills() {
		for (int i = 0; i < skillsSize - 1; i++) {
			std::cout << skills[i] << ", ";
		}
		std::cout << skills[skillsSize - 1] << std::endl;
	}

	//determine amount of bonus given
	int Body::skillCalc(int rank, int mod) {
		//determines the value for each skill
		//formula......adds the rank and mod
		//return value 
		int total = (mod / 10) - 2 + rank;
		return total;
	}

	int Body::setAbility(int ability) {
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
		return ((abilities[ability]) / 10) - 2;
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
};*/