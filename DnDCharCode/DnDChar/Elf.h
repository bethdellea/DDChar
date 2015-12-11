//
//  Elf.h
//  D&D
//
//  Created by Nicole Lane on 11/16/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#ifndef D_D_Elf_h
#define D_D_Elf_h

#include "RaceADT.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "Body.h"

class Elf: public RaceADT {
private:

    
    
    
public:
    //Public in order for other classes to access them (when sending these data members as parameters, etc.)
    std::string* knownLanguages;
    std::string* vision;
    int languageIdx; //Keeps track of which index in the array to add to next
    int visionIdx;
    int speed;
    
    /* Creates a new Elf; sets initial base speed, known languages and movement*/
    Elf();
    //Create a deep copy of a Elf parameter
    Elf(const Elf& elfToCopy);
    //Destructor
    ~Elf();
    //For printing to a file
    std::string getLangString();
    std::string getVisionString();
    
    //Print speed of character
    void printSpeed();
    //Get speed of character
    int getSpeed();
    //Increase speed of character
    int changeSpeed (int amt);
    //Add a new known language
    void addLanguage(std::string newLanguage);
    //Prints a list of known languages
    void printLanguages();
    //Add a new vision
    void addVision(std::string newVision);
    //Prints a list of visions
    void printVision();
    
    //Stat bonus, takes body's ability array and adjusts the values based off of specific race
    void changeAbilities(int* abilArr);

    
};


#endif
