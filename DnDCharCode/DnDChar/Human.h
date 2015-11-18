//
//  Human.h
//  D&D
//
//  Created by Nicole Lane on 11/16/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#ifndef D_D_Human_h
#define D_D_Human_h

#include "RaceADT.h"
#include <string>
#include <iostream>
#include <stdio.h>

Class Human : public RaceADT {
    int speed;
    std::string* knownLanguages;
    std::string* vision;
    const std::string* raceWeaponProficiencies;
    
public:
    /* Creates a new Human; sets initial base speed, known languages and adds natural weapon proficiencies*/
    Human();
    //Create a deep copy of a Human parameter
    Human(const &Human humanToCopy);
    //Destructor
    ~Human();
    //Get speed of character
    int getSpeed();
    //Increase speed of character
    void changeSpeed (int amt);
    //Add a new known language
    void addLanguage(std::string newLanguage);
    //Prints a list of known languages
    void printLanguages();
    //Add a weapon proficiency
    void addProficiency();
    //Print a list of weapon proficiencies
    void printProficiencies();
    //Stat bonus
    void changeAbilities();

    
private:
    
}


#endif
