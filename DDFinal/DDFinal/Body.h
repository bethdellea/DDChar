#pragma once
#ifndef Body_h
#define Body_h

//#include "stdafx.h"
#include <iostream>
//#include "ClassADT.h"
//#include "RaceADT.h"
//#include "human.h"

class Body{
	private: 
		//fixed size
		int* skills; //contains the skill bonus
        //int skillsSize;
        //int abilitySize;
		

	public:
    
        //fixed size
        int* abilities; //contains ability score
    
        Body();

		//sets skills or changes them 
		void setSkills(int index, int change); 
		//returns the value for the skill
		int skillCheck(int skill);
		void printThisSkill(int skill);
		void printAllSkills();
		
		//determine amount of bonus given
		int skillCalc( int rank, int mod);

		void setAbility(int ability);
		//mathematically based on abilities
		int getModifier(int ability);
		int* getAbilities();
		void printThisAbil(std::string ability);
		void printAllAbilities();

		~Body() {};
};
#endif /*Body_h*/