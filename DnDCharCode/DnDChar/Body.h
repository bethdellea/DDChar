#pragma once
#ifndef Body_h
#define Body_h

#include "stdafx.h"
#include <iostream>
//#include "ClassADT.h"
//#include "RaceADT.h"
//#include "human.h"

class Body{
	private: 
		//fixed size
		int* skills; //contains the skill bonus
    
		

	public:
        //I had to make this public in order for character to be able to access it!
        int* abilities; //contains ability score
    
		Body();
		//sets skills or changes them 
		void setSkills(int change); 
		//returns the value for the skill
		int skillCheck(int skill);
		void printThisSkill(std::string skill);
		void printAllSkills();
		
		//determine amount of bonus given
		int skillCalc(int ability, int rank, int mod);

		void setAbility(int ability);
		//mathematically based on abilities
        //Return ability array
        int* getAbilities();
		int getModifier(int ability);
		void printThisAbil(std::string ability);
		void printAllAbilities();

		~Body() {};
};
#endif /*Body_h*/