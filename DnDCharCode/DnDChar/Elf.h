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

class Elf: public RaceADT {
private:
    int speed;
    std::string* knownLanguages;
    std::string* vision;
    int languageIdx;
    int visionIdx;

    
public:
    /* Creates a new Elf; sets initial base speed, known languages and adds natural weapon proficiencies*/
    Elf();
    //Create a deep copy of a Elf parameter
    Elf(const Elf& elfToCopy);
    //Destructor
    ~Elf();
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
    //Stat bonus
    void changeAbilities(int* statArr);

    
};


#endif
