//
//  Dwarf.h
//  D&D
//
//  Created by Nicole Lane on 11/16/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#ifndef D_D_Dwarf_h
#define D_D_Dwarf_h

#include "RaceADT.h"
#include <string>
#include <iostream>
#include <stdio.h>

class Dwarf : public RaceADT {
private:

    
    
    
public:

    std::string* knownLanguages;
    std::string* vision;
    int languageIdx; //Keeps track of which index to add to when adding to the array
    int visionIdx;
    int speed; //Base movement speed
    

public:


    /* Creates a new Dwarf; sets initial base speed and known languages*/
    Dwarf();
    //Create a deep copy of a Dwarf parameter
    Dwarf(const Dwarf& dwarfToCopy);
    //Destructor
    ~Dwarf();
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
    //Prints a list of current visions
    void printVision();
    //Stat bonus
    void changeAbilities(int* abilArr); //Takes body's ability array and adjusts the values based off of specific race
    //For printing to a file
    std::string getLangString();
    std::string getVisionString();
   

};
#endif
