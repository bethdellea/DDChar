
#include "stdafx.h"
#include <iostream>


class Body {

	//fixed size
	int* skills; //contains the skill bonus
				 //fixed size
	int* abilities; //contains ability score 

	Body::Body() {

	}
	//sets skills or changes them 
	void Body::setSkills(int change) {
 
	}
	//returns the value for the skill
	int Body::skillCheck(int skill) {

	}
	void Body::printThisSkill(std::string skill) {
	
	}
	void Body::printAllSkills() {
	
	}

	//determine amount of bonus given
	int Body::skillCalc(int ability, int rank, int mod) {
	
	}

	void Body::setAbility(int ability) {
	
	}
	//mathematically based on abilities
	int Body::getModifier(int ability) {
	
	}
	void Body::printThisAbil(std::string ability) {
	
	}
	void Body::printAllAbilities() {
	
	}

	Body::~Body() {};
};